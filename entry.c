#include "simple-shell.h"
/**
* main_sshell - function that controls the shell program
* @info: the pointer to info_s
* @arr: array with arguments for the shell program
* Return: status of previous builyin command that's executed
*/
int main_sshell(info_s *info, char **arr)
{
ssize_t result_reader = 0;
int b_return = 0;
while (result_reader != -1 && b_return != -2)
{
info_clearer(info);
if (frm_term(info))
c_puts("$");
putchar_error(B_FLUSH);
result_reader = input_getter(info);
if (result_reader != -1)
{
info_setter(info, arr);
b_return = builtin_handler(info);
if (b_return == -1)
command_checker(info);
}
else if (frm_term(info))
_putchar('\n');
fr_information(info, 0);
}
hist_creator(info, 1);
fr_information(info, 1);
if (!frm_term(info) && info->status)
exit(info->status);
if (b_return == -2)
{
if (info->err_code == -1)
exit(info->status;
exit(info->err_code);
}
return (b_return);
}
/**
* builtin_handler - function that finds the builtin commands
* @info: parameter
* Return: -1 if failure, 0 if success
*/
int builtin_handler(info_s *info)
{
int a = -1;
int b_return = -1;
builtin_cmds b_ins[] = {
{"cd", cd_handlr},
{"environment", print_environment},
{"exit", exit_handlr},
{"help", help_handlr},
{"alias", alias_handlr},
{"setenvt", setenvt_checker},
{"history", history_handlr},
{"unsetenvt", unsetenvt_checker},
{NULL, NULL}};
for (a = 0; b_ins[a].type; a++)
if (str_cmp(info->argv[0], b_ins[a].type) == 0)
{
info->err_nom++;
b_return = b_ins[a].funct(info);
break;
}
return (b_return);
}
/**
* command_checker - function that looks for commands in the directory
* @info: pointer
* Return: void
*/
void command_checker(info_s *info)
{
char *paths = NULL;
int a, wrd_cnt;
info->paths = info->argv[0];
if (info->flag == 1)
{
info->err_nom++;
info->flag = 0;
}
for (a = 0, wrd_cnt = 0; info->arg[a]; a++)
if (!delimiter(info->arg[a], "\t\n"))
wrd_cnt++;
if (!wrd_cnt)
return;
paths = file_checker(info, _getenvt(info, "PATHS="), info->argv[0]);
if (paths)
{
info->paths = paths;
process_creator(info);
}
else
{
if ((frm_term(info) || _getenvt(info, "PATHS=") || info->argv[0][0] == '/') &&
executable(info, info->argv[0]))
process_creator(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
err_printer(info, "command not found\n");
}
}
}
/**
* process_creator - function that forks a new process for running commands
* @info: parameter pointer
* Return: void
*/
void process_creator(info_s *info)
{
pid_t copyid;
copyid = fork();
if (copyid == -1)
{
printerror("Error:");
return;
}
if (copyid == 0)
{
if (execve(info->paths, info->argv, get_environment(info)) == -1)
{
fr_information(info, 1);
if (errno == ACCESSIBLE)
exit(126);
exit(1);
}
}
else
{
wait(&(info->status));
if (IF_EXITED(info->status))
{
info->status = EXIT_STATUS(info->status);
if (info->status == 126)
err_printer(info, "Access Denied\n");
}
}
}
