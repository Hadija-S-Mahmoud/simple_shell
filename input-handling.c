#include "simple-shell.h"
/**
* input_handler - a function that buffers commands
* that are chained
* @info: the parameter of the struct
* @buffr: the address of the buffer
* @lent: the address of the length variable
* Return: the bytes that have been read
*/
ssize_t input_handler(info_s *info, char **buffr, size_t *lent)
{
ssize_t a = 0;
size_t lent_l = 0;
{
free(*buffr);
*buffr = NULL;
signal(SINT, sigint_handler);
#if USE_GETLINE
a = getline(buffer, &lent_l, stdin);
#else
a = get_line(info, buffer, &lent_l);
#endif
if (a > 0)
{
if ((*buffr)[a - 1] == '\n')
{
(*buffr)[a - 1] = '\0';
a--;
}
info->flag = 1;
comment_handler(*buffr);
hist_updater(info, *buffr, info->history_lines++);
{
*lent = a;
info->s_buffer = buffr;
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

/**
* buffer_reader - function that reads the buffer
* @info: the parameter
* @buffr: buffer
* @a: the size of the buffer
* Return: z
*/
ssize_t buffer_reader(info_s *info, char *buffr, size_t *a)
{
ssize_t z = 0;
if (*a)
return (0);
z = read(info->desc, buffr, READ_THE_BUFFER_SIZE);
if (z >= 0)
*a = z;
return (z);
}

/**
* get_line - a function that gets the next line
* @info: parameter
* @lengt: size of the pointer if not NULL
* @pointr: the address of the pointer
* Return: s
*/
int get_line(info_s *info, char **pointr, size_t *lengt)
{
static char buffer[READ_THE_BUFFER_SIZE];
static size_t a, lent;
size_t b;
ssize_t c = 0, d = 0;
char *e = NULL, *new_e = NULL, *f;
e = *pointr;
if (e && lengt)
d = *lengt;
if (a == lent)
a = lent = 0;
c = buffer_reader(info, buffer, &lent);
if (c == -1 || (c == 0 && lent == 0))
return (-1);
f = str_char(buffer + a, '\n');
b = f ? 1 + (unsigned int)(f -  buffer) : lent;
new_e = real_loct(e, d, d ? d + b : b + 1);
if (!new_e)
return (e ? free(e), -1 : -1);
if (d)
strn_cat(new_e, buffer + a, b - a);
else
strn_copy(new_e, buffer + a, b - a + 1);
d += b - a;
a = b;
e = new_e;
if (lengt)
*lengt = d;
*pointr = e;
return (d);
}

/**
* sigint_handler - function that blocks ctrl-c
* @sig_nom: the number of the signal
* Return: void
*/
void sigint_handler(__attribt__((unused)) int sig_nom)
{
puts("\n");
puts("$");
_putchar(B_FLUSH);
}
