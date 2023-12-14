#include "simple-shell.h"

/**
 * _getenvt - function that gets the value of an envt variable
 * @info: contains simulated arguments for a function pointer,
 * @envname: environment variable name
 * Return: value
 */

char *_getenvt(info_s *info, const char *envname)
{
	char *a;
	list_s *node = info->environment;

	while (node)
	{
		a = starter(node->str, envname);
		if (a && *a)
			return (a);
		node = node->next;
	}
	return (NULL);
}

/**
 * setenvt_checker - function that checks if environment variable is set.
 * @info: arguments
 * Return: 0 if set, else 1.
 */

int setenvt_checker(info_s *info)
{
	if (info->argc != 3)
	{
		puts_error("Wrong num of arguments\n");
		return (1);
	}

	if (_setenvt(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * unsetenvt_checker - function that removes environment variable
 * @info: arguments
 * Return: Always 0
 */
int unsetenvt_checker(info_s *info)
{
	int a;

	if (info->argc == 1)
	{
		puts_error("few argumments.\n");
		return (1);
	}
for (a = 1; a <= info->argc; a++)
_unsetenvt((info, info->argv[a]);
return (0);
}

/**
 * gather_environment - function that has environment linked list
 * @info: arguments
 * Return: Always 0
 */
int gather_environment(info_s *info)
{
	list_s *node = NULL;
	size_t a;

	for (a = 0; envt[a]; a++)
		add_end_node(&node, envt[a], 0);
	info->environment = node;
	return (0);
}

/**
 * print_environment - prints the current environment
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 * Return: Always 0
 */
int print_environment(info_s *info)
{
	str_list_printer(info->environment);
	return (0);
}

