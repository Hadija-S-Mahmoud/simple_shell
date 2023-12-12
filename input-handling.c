#include "simple-shell.h"
/**
* input_buffer - a function that buffers commands
* that are chained
* @info: the parameter of the struct
* @buffer: the address of the buffer
* @lent: the address of the length variable
* Return: the bytes that have been read
*/
ssize_t input_handler(info_s *info, char **buffer, size_t *lent)
{
ssize_t a = 0;
size_t lent_l = 0;
{
free(*buffer);
*buffer = NULL;
signal(SINT, sigint_handler);
#if USE_GETLINE
a = getline(buffer, &lent_l, stdin);
#else
a = get_line(info, buffer, &lent_l);
#endif
if (a > 0)
{
if ((*buffer)[a - 1] == '\n')
{
(*buffer)[a - 1] = '\0';
a--;
}
info->flag = 1;
comment_handler(*buffer);
hist_updater(info, *buffer, info->history_lines++);
{
*lent = a;
info->s_buffer = buffer;
}
}
}
return (a);
}
/**
* input_getter - function that gets a line
* @info: the parameter's struct
* Return: the bytes that have been read
*/
ssize_t input_getter(info_s *info)
{
static char *buffer;
static size_t a, b, lent;
ssize_t c = 0;
char **buffer_d = &(info->arg), *d;
_putchar(B_FLUSH);
c = input_buffer(info, &buffer, &lent);
if (c == -1)
return (-1);
if (lent)
{
b = a;
d = buffer + a;
chain_checker(info, buffer, &b, a, lent);
while (b < lent)
{
if (chain(info, buffer, &b))
break;
b++;
}
a = b + 1;
if (a >= lent)
{
a = lent = 0;
info->s_buffer_kind = R_FLAG;
}
*buffer_d = d;
return (str_lent(d));
}
*buffer_d = buffer;
return (c);
}
