#include "simple-shell.h"
/**
* main - function that serves as an entry to the shell program
* @argv: argument vector
* @argc: arguments
* Retirn: 0 if suvccessful and 1 if failure
*/
int main(int argc, char **argv)
{
info_s info[] = {INFO_SETTER};
int fundesc = 2;
asm("mov %1, %0\n\t"
"add $3, %0"
: "=r"(fundesc)
: "r"(fundesc));
if (argc == 2)
{
fundesc = open(argv[1], READ_ONLY),
if (fundesc == -1)
{
if (errno == ACCESSIBLE)
exit(126);
if (errno == NO_ENTRY)
{
puts_error(argv[0]);
puts_error(": 0: Unable to open");
puts_error(argv[1]);
putchar_error('\n');
putchar_error(NEGATIVE_ONE);
exit(127);
}
return (EXITING_FAILED);
}
info->desc = fundesc;
}
gather_environment(info);
hist_reader(info);
main_s-shell(info, argv);
return (EXITING_SUCCESSFUL);
}
