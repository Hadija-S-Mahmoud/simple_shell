#include "simpleshell.h"

/**
 * exit_handlr - function that exits the shell
 * @info: arguments
 * Return: exit status
 */

int exit_handlr(info_s *info)
{
	int ex;

	if (info->argv[1]) 
	{
		ex = error_number(info->argv[1]);
		if (ex == -1)
		{
			info->status = 2;
			err_printer(info, "Unknown number: ");
			puts_error((info->argv[1]);
			putchar_error('\n');
			return (1);
		}
		info->err_code = error_number(info->argv[1]);
		return (-2);
	}
	info->err_code = -1;
	return (-2);
}
/**
 * cd_handlr - function that changes the current directory 
 * @info: arguments 
 * Return: 0
 */

int cd_handlr(info_s *info)
{
	char *i, *dirct, buffer[1024];
	int chdir_r;

	i = getcd(buffer, 1024);
	if (!i)
		puts("TODO: >>getcd failure message here<<\n");
	if (!info->argv[1])
	{
		dirct = _getenvt(info, "HOME=");
		if (!dirct)
			chdir_r = /* TODO: what shld this be? */
			chdir((dirct = _getenvt(info, "PWD=")) ? dirct : "/");
		else
			chdir_r = chdir(dirct);
	}
	else if (str_cmp(info->argv[1], "-") == 0)
	{
		if (!_getenvt(info, "OLDPWD="))
		{
			puts(i);
			_putchar('\n');
			return (1);
		}
		puts(_getenvt(info, "OLDPWD=")), _putchar('\n');
		chdir_r = /* TODO: what should this be? */
			chdir((dirct = _getenvt(info, "OLDPWD=")) ? dirct : "/");
	}
	else
		chdir_r = chdir(info->argv[1]);

	if (chdir_r == -1)
	{
		err_printer(info, "cannot cd to ");
		puts_error(info->argv[1]), putchar_error('\n');
	}
	else
	{
		_setenvt(info, "OLDPWD", _getenvt(info, "PWD="));
		_setenvt(info, "PWD", getcd(buffer, 1024));
	}
	return (0);
}

/**
 * help_handlr - function that prints a message for a function that’s not implemented
 * @info: arguments
 * Return: 0
 */

int help_handlr(info_s *info)
{
	char **arg_array;

	arg_array = info->argv;
	puts("help. Function not implemented \n");
	if (0)
		puts(*arg_array);

	return (0);
}

/**
 * history_handlr - function that gives the history list
 * @info: argument
 * Return: Always 0
 */

int history_handlr(info_s *info)
{
	list_printer(info->history);

	return (0);
}

