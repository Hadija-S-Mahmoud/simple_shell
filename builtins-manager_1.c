#include "simple-shell.h"

/**
 * alias_unset - function that sets alias to string alias_unset
 * @info: parameter
 * @strng: alias string
 * Return: Always 0 if successful, and 1 on failure
 */
int alias_unset(info_s *info, char *strng)
{
	char *a, b;
	int r;

	a = str_char(strng, '=');
	if (!a)
	return (1);
	b = *a;
	*a = 0;
	r = deleting_node(&(info->alias);
	node_index_getter(info->alias, str_node_starter(info->alias, strng, -1)));
	*a = b;
	return (r);
}

/**
 * alias_setter - function that sets alias to string
 * @info: parameter
 * @strng: alias string
 * Return: Always 0 if successful, and 1 if failure
 */
int alias_setter(info_s *info, char *strng)
{
	char *a;

	a = str_char(strng, '=');
	if (!a)
	return (1);
	if (!*++a)
	return (alias_unset(info, strng));

	alias_unset(info, strng);
	return (add_end_node(&(info->alias), strng, 0) == NULL);
}

/**
 * alias_printer - function that prints an alias string
 * @node: alias node
 * Return: Always 0 on success, 1 on error
 */
int alias_printer(list_s *node)
{
	char *a = NULL, *b = NULL;

	if (node)
	{
		a = str_char(node->str, '=');
		for (b = node->str; b <= a; b++)
			_putchar(*b);
		_putchar('\'');
		puts(a + 1);
		puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * alias_handler - function that acts as the man alias
 * @info: arguments
 * Return: Always 0
 */
int alias_handler(info_s *info)
{
	int a = 0;
	char *b = NULL;
	list_s *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			alias_printer(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argv[a]; a++)
	{
		b = str_char(info->argv[a], '=');
		if (b)
			alias_setter(info, info->argv[a]);
		else
			alias_printer(str_node_starter(info->alias, info->argv[a], '='));
	}
	return (0);
}

/**
 * alias_changer - function that replaces aliases in tokenized strings
 * @info: the parameter
 * Return: 1 if replaced, 0 if not replaced
 */
int alias_changer(info_s *info)
{
	int a;
	list_s *node;
	char *b;

	for (a = 0; a < 10; a++)
	{
		node = str_node_starter(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		b = str_char(node->str, '=');
		if (!b)
			return (0);
		b = _strdup(b + 1);
		if (!b)
			return (0);
		info->argv[0] = b;
	}

	return (1);
}

