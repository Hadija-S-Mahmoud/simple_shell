#include "simple-shell.h"

/**
 * info_clearer - function that initializs info_s struct
 * @info: address of the struct
 */
void info_clearer(info_s *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
/**
 * info_setter - initializes info_s struct
 * @info: struct address
 * @av: argument vector
 */
void info_setter(info_s *info, char **av)
{
	int a = 0;

	info->program_name = av[0];
	if (info->arg)
	{
		info->argv = str_towr(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = strd_up(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (a = 0; info->argv && info->argv[a]; a++)
			;
		info->argc = a;
		alias_changer(info);
		v_changer(info);
	}
}
/**
 * fr_information - function that frees info_s struct
 * @info: the address of the struct
 * @alli: true
 */
void fr_information(info_s *info, int alli)
{
	fr_vector(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (alli)
	{
		if (!info->s_buffer)
			free(info->arg);
		if (info->environment)
			fr_list(&(info->environment));
		if (info->history)
			fr_list(&(info->history));
		if (info->alias)
			fr_list(&(info->alias));
		fr_vector(info->envt);
		info->envt = NULL;
		freeb((void **)info->s_buffer);
		if (info->desc > 2)
			close(info->desc);
		_putchar(B_FLUSH);
	}
}

