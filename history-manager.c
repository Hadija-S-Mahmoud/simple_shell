#include "simple-shell.h"

/**
 * history_reading - function that gets the history file
 * @info: parameter
 * Return: string with history file
 */

char *history_reading(info_s *info)
{
	char *buffr, *dirct;

	dirct = _getenvt(info, "HOME=");
	if (!dirct)
		return (NULL);
	buffr = malloc(sizeof(char) * (_strlen(dirct) + _strlen(HISTORY_NAME) + 2));
	if (!buffr)
		return (NULL);
	buffr[0] = 0;
	str_copy(buffr, dirct);
	str_cat(buffr, "/");
	str_cat(buffr, HISTORY_NAME);
 	return (buffr);
}

/**
 * hist_creator - function that creates a file
 * @info: parameter
 * Return: 1 on success, or  -1 on failure
 */
int hist_creator(info_s *info)
{
	ssize_t fdesc;
	char *filename = history_reading(info);
	list_s *node = NULL;

	if (!filename)
		return (-1);

	fdesc = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fdesc == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		chars_writer(node->str, fdesc);
		char_writer('\n', fdesc);
	}
	char_writer(B_FLUSH, fdesc);
	close(fdesc);
	return (1);
}

/**
 * hist_reader - function that reads the hist from file
 * @info: parameter
 * Return: history_lines if successful, 0 on failure
 */
int hist_reader(info_s *info)
{
	int a, last = 0, lincnt = 0;
	ssize_t fdesc, rdlent, fsize = 0;
	struct stat s;
	char *buffr = NULL, *filename = history_reading(info);

	if (!filename)
		return (0);

	fdesc = open(filename, O_RDONLY);
	free(filename);
	if (fdesc == -1)
		return (0);
	if (!fstat(fdesc, &s))
		fsize = s.s_size;
	if (fsize < 2)
		return (0);
	buffr = malloc(sizeof(char) * (fsize + 1));
	if (!buffr)
		return (0);
	rdlent = read(fdesc, buffr, fsize);
	buffr[fsize] = 0;
	if (rdlent <= 0)
		return (free(buffr), 0);
	close(fdesc);
	for (a = 0; a < fsize; a++)
		if (buffr[a] == '\n')
		{
			buffr[a] = 0;
			hist_updater(info, buffr + last, lincnt++);
			last = a + 1;
		}
	if (last != a)
		hist_updater(info, buffr + last, lincnt++);
	free(buffr);
	info->history_lines = lincnt;
	while (info->history_lines-- >= HISTORY_MAX)
		deleting_node(&(info->history), 0);
	hist_renum(info);
	return (info->history_lines);
}

/**
 * hist_updater - function that adds an entry to a hist linked list
 * @info: arguments for pointer,
 * @buffr: buffer
 * @lncnt: hist line cnt
 * Return: Always 0
 */

int hist_updater(info_s *info, char *buffr, int lncnt)
{
	list_s *node = NULL;

	if (info->history)
		node = info->history;
	add_end_node(&node, buffr, lncnt);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * hist_renum - function that renumber hist linked list
 * @info: arguments for pointer of function
 * Return: history_lines
 */
int hist_renum(info_s *info)
{
	list_s *node = info->history;
	int a = 0;

	while (node)
	{
		node->num = a++;
		node = node->next;
	}
	return (info->history_lines = a);
}

