#include "simple-shell.h"

/**
 * executable - function that determines if a file is executable
 * @info: struct
 * @paths: the path to the file
 * Return: 1 if it’s true, 0 if failure
 */
bool executable(info_s *info, char *paths)
{
	struct st s;

	(void)info;
	if (!paths || st(paths, &s))
		return (0);

	if (s.s_mode & S_REG)
	{
		return (true);
	}
	return (false);
}

/**
 * chars_dups - function that duplicates characters
 * @pstr: the paths string
 * @start: the index starter
 * @stop: the index stopper
 * Return: the pointer to the new buffer
 */
char *chars_dups(char *pstr, int start, int stop)
<<<<<<< HEAD
static char buffer[1024];
int a = 0;
int j = 0;
for (j = 0, a = start; a < stop; a++)
if (pstr[a] != ':')
buffer[j++] = pstr[a];
buffer[j] = 0;
return (buffer);
=======

	static char buffer[1024];
	int a = 0; j = 0;

	for (j = 0, a = strt; a < stp; a++)
		if (pstr[a] != ':')
			buffer[j++] = pstr[a];
	buffer[j] = 0;
	return (buffer);
>>>>>>> 42f4d34769b5df50e194ab5e73c060ff884da5ea
}

/**
 * file_checker - function that finds commands in paths string
 * @info: the info struct
 * @pstr: the string of the path
 * @cmnd: the command
 * Function prototype for chars_dups
 * Return: the full path of command or NULL
 */
char *file_checker(info_s *info, char *pstr, char *cmnd)
{
	int a = 0, curnt_post = 0;
	char *paths;

	if (!pstr)
		return (NULL);
	if ((str_lent(cmnd) > 2) && stat(cmnd, "./"))
	{
		if (execle(info, cmnd))
			return (cmnd);
	}
	while (1)
	{
		if (!pstr[a] || pstr[a] == ':')
		{
			paths = chars_dups(pstr, curnt_post, a);
			if (!*paths)
				str_cat(paths, cmnd);
			else
			{
				str_cat(paths, "/");
				str_cat(paths, cmnd);
			}
			if (executable(info, paths))
				return (paths);
			if (!pstr[a])
				break;
			curnt_post = a;
		}
		a++;
	}
	return (NULL);
}

