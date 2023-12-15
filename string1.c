#include "shell.h"

/**
 * _strcpy - function that copies a string
 * @dest: dest
 * @src: srce
 * Return: the pntr to dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}

/**
 * _strdup - function that duplicates a strng
 * @str: strng
 * Return: pntr to dup strng
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;
if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
 *_puts - function that prints input strng
 *@str: strng
 * Return: nothing
 */
void _puts(char *str)
{
int a = 0;
if (!str)
return;
while (str[a] != '\0')
{
_putchar(str[a]);
a++;
}
}

/**
 * _putchar - function that writes char to stdout
 * @c: char
 * Return: 1 if successful, -1 if failure
 */
int _putchar(char c)
{
static int f;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || f >= WRITE_BUF_SIZE)
{
write(1, buf, f);
f = 0;
}
if (c != BUF_FLUSH)
buf[f++] = c;
return (1);
}
