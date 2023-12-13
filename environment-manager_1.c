#include "simple-shell.h"

/**
 * get_environment - Funct returns a copy of envt var as array of strings
 * @info: structure with envt variables
 * Return: environment variables
 */

char **get_environment(info_s *info)
{
	if (!info->envt || info->changed_envt)
	{
		info->envt = vector_list(info->environment);
		info->changed_envt = 0;
	}
	return (info->envt);
}

/**
 * _setenvt - a function that adds or updates environment variables.
 * @info: Struct
 * @varb: The name of the environment variable to added or updated.
 * @val: The value of the environment variable to be added or updated.
 * Return: 0 if the envt variable was added or updated, else 1
 */
int _setenvt(info_s *info, char *varb, char *val)
{
	char *buffer = NULL;
	list_s *node;
	char *a;

	if (!varb || !val)
	return (1);

	buffer = malloc(str_lent(varb) + str_lent(val) + 2);
	if (!buffer)
		return (1);

	str_copy(buffer, varb);
	str_cat(buffer, "=");
	str_cat(buffer, val);


	node = info->environment;
	while (node)
	{
		a = starter(node->str, varb);
		if (a && *a == '=')
		{
			free(node->str);
			node->str = buffer;
			info->changed_envt = 1;
			return (0);
		}

		node = node->next;
	}

	add_end_node(&(info->environment), buffer, 0);
	free(buffer);
	info->changed_envt = 1;
	return (0);
}

/**
 * _unsetenvt - Function that removes an environment variable.
 * @info: Structure
 * @varb: environment variable to remove.
 * Return: 1 if successfully removed, else 0.
 */

int _unsetenvt(info_s *info, char *varb)
{
	list_s *node = info->environment;
	size_t indx = 0;
	char *a;

	if (!node || !var)
	return (0);

	while (node)
	{
		a = starter(node->str, varb);
		if (a && *a == '=')
		{
			info->changed_envt = deleting_node(&(info->environment), indx);

			indx = 0;
			node = info->environment;
			continue;
		}

		node = node->next;
		index++;
	}

	return (info->changed_envt);
}

