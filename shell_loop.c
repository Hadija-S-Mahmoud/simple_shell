#include "shell.h"

/**
 * hsh - function that is the main shell loop
 * @info: param and return
 * @av: arg vector
 * Return: 0 if success, and 1  if error occurs, or give an error code
 */
int hsh(info_t *info, char **av)
{
ssize_t r = 0;
int builtin_ret = 0;
while (r != -1 && builtin_ret != -2)
{
clear_info(info);
if (interactive(info))
_puts("$ ");
_eputchar(BUF_FLUSH);
r = get_input(info);
if (r != -1)
{
set_info(info, av);
builtin_ret = find_builtin(info);
if (builtin_ret == -1)
find_cmd(info);
}
else if (interactive(info))
_putchar('\n');
free_info(info, 0);
}
write_history(info);
free_info(info, 1);
if (!interactive(info) && info->status)
exit(info->status);
if (builtin_ret == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}
return (builtin_ret);
}

/**
 * find_builtin - funct that finds a builtin cmnd
 * @info: param & return info struct.
 * Return: -1 when not found,0 if successful
 */
int find_builtin(info_t *info)
{
int a, built_in_ret = -1;
builtin_table builtintbl[] = {
{"exit", _myexit},
{"env", _myenv},
{"help", _myhelp},
{"history", _myhistory},
{"setenv", _mysetenv},
{"unsetenv", _myunsetenv},
{"cd", _mycd},
{"alias", _myalias},
{NULL, NULL}};
for (a = 0; builtintbl[a].type; a++)
if (_strcmp(info->argv[0], builtintbl[a].type) == 0)
{
info->line_count++;
built_in_ret = builtintbl[a].func(info);
break;
}
return (built_in_ret);
}

/**
 * find_cmd - function that finds a cmndd in PATH
 * @info: param
 * Return: void
 */
void find_cmd(info_t *info)
{
char *path = NULL;
int i, k;
info->path = info->argv[0];
if (info->linecount_flag == 1)
{
info->line_count++;
info->linecount_flag = 0;
}
for (i = 0, k = 0; info->arg[i]; i++)
if (!is_delim(info->arg[i], " \t\n"))
k++;
if (!k)
return;
path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
if (path)
{
info->path = path;
fork_cmd(info);
}
else
{
if ((interactive(info) || _getenv(info, "PATH=") ||
info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
fork_cmd(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
print_error(info, "not found\n");
}
}
}
/**
 * fork_cmd - funct that forks a exec thread to run cmd
 * @info: param
 * Return: void
 */
void fork_cmd(info_t *info)
{
pid_t child_pid;
child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(info->path, info->argv, get_environ(info)) == -1)
{
free_info(info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
print_error(info, "Permission denied\n");
}
}
}
