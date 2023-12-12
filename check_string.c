#include "simple-shell.h"
/**
 * chain - checks whether the current char in the buffer is a chain delimiter
 * @info: parameter
 * @buffer: char buffer
 * @h: address of the current position in the buffer
 * Return: 1 if it’s a chain delimiter else 0 if it’s not
 */
bool chain (info_s *info, char *buffer, size_t *h)
{
	size_t a = *h;

	if (buffer[a] == '|' &&buffer[a + 1] == '|')
	{
		buffer[a] = 0;
		a++;
		info->s_buffer_type = O_FLAG;
	}
	else if (buffer[a] == '&' &&buffer[a + 1] == '&')
	{
		buffer[a] = 0;
		a++;
		info->s_buffer_type = A_FLAG;
	}
	else if (buffer[a] == ';')
	{
		buffer[a] = 0;
		info->s_buffer_type = C_FLAG;
	}
	else
		return (false);
	*h = a;
	return (true);
}

/**
 * chain_checker - function that checks chaining
 * @info: parameter
 * @buffer: char buffer
 * @h: the address of the current position in the buffer
 * @m: the starting position in the buffer
 * @lent: the length of the buffer
 * Return: Void
 */
void chain_checker(info_s *info, char *buffer, size_t *h, size_t m, size_t lent)
{
	size_t a = *h;

	if (info->s_buffer_type == A_FLAG)
	{
		if (info->status)
		{
			buffer[m] = 0;
			a = lent;
		}
	}
	if (info->s_buffer_type == O_FLAG)
	{
		if (!info->status)
		{
			buffer[m] = 0;
			a = lent;
		}
	}
	*h = a;
}

/**
 * v_changer - a function that replaces variables in the tokenised string
 * @info: parameter
 * Return: 1 if it’s replaced, and 0 if not
 */
int v_changer(info_s *info)
{
	int b = 0;
	list_s *node;

	for (b = 0; info->argv[b]; b++)
	{
		if (info->argv[b][0] != '$' || !info->argv[b][1])
			continue;
		if (!str_cmp(info->argv[b], "$?"))
		{
			string_changer(&(info->argv[b]),

			   str_dup(base_changer(info->status, 10, 0)));

			continue;
		}		
		if (!str_cmp(info->argv[i], "$$"))
		{
			string_changer(&(info->argv[b]),

			   str_dup(base_changer(getpid(), 10, 0)));

			continue;
		}
		node = str_node_starter(info->environment, &info->argv[b][1], '=');
		if (node)
		{
			string_changer(&(info->argv[b]),

			 str_dup(str_char(node->str, '=') + 1));

			continue;
		}
		string_changer(&info->argv[b], str_dup(""));
	}
	return (0);
}
/**
 * string_changer - a function that replaces a string
 * @old-str: the address of the old string
 * @new-str: the address of the new string
 * Return: 1 if it’s replaced, 0 if it’s not
 */
int string_changer(char **old-str, char *new-str)
{
	free(*old-str);
	*old-str = new-str;

	return (1);
}

