#include "simple-shell.h"
/**
* str_copy - function that cpies strng
* @destn: destn
* @src: source
* Return: pointr
*/
char *str_copy(char *destn, char *src)
{
int a = 0;
if (destn == src || src == 0)
return (destn);
while (src[a])
{
destn[a] = src[a];
a++;
}
destn[a] = 0;
return (destn);
}

/**
* strd_up - function duplicating strngs
* @str: strng
* Return: pointr
*/
char *strd_up(const char *str)
{
int lengt = 0;
char *r;
if (str == NULL)
return (NULL);
while (*str++)
lengt++;
r = malloc(sizeof(char) * (lengt + !));
if (!r)
return (NULL);
for (length++; lengt--;)
r[lengt] = *--str;
return (r);
}

/**
* c_puts - funct printin input str
* @str: string printed
* Return: nothing
*/
void c_puts(char *str)
{
int a = 0;
if (!str)
return;
while (str[a] != '\0')
{
_putchar(str[a]);
a++
}
}

/**
* _putchar - function that writes char c to stdout
* @i: char
* Return: 1 if successful, -1if failure
*/
int _putchar(char i)
{
static int c;
static char buffr[WRITE_THE_BUFFER_SIZE];
if (i == B_FLUSH || c >= WRITE_THE_BUFFER_SIZE)
{
write(1, buffr, c);
c = 0;
}
if (i != B_FLUSH)
buffr[c++] = i;
return (1);
}
