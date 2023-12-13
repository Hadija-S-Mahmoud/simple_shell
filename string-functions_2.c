#include "simple-shell.h"
/**
* *strn_copy - function copyin a strng
* @destn: destination
* @src: srce
* @x: chars to copy
* Return: cancatenatd strng
*/
char *strn_copy(char *destn, char *src, int x)
{
int a, b;
char *c = destn;
a = 0;
while (src[a] != '\0' && a < x - 1)
{
destn[a] = src[a];
a++;
}
if (a < x)
{
b = a;
while (b < x)
{
destn[b] = '0';
b++;
}
}
return (c);
}

/**
* *strn_cat - function that conctnts two strings
* @destn: string one
* @src: string two
* @h: bytes
* Return: concatntd string
*/
char *strn_cat(char *destn, char *src, int h)
{
int a, b;
char *c = destn;
a = 0;
b = 0;
while (destn[a] != '\0')
a++;
while (src[b] != '\0' && b < h)
{
destn[a] = src[b];
a++;
b++;
}
if (b < h)
destn[a] = '\0';
return (c);
}

/**
* *str_char - function that locates char in strng
* @h: parsed strng
* @m: char
* Return: h
*/
char *str_char(char *h, char m)
{
do {
if (*h == m)
return (h);
} while (*h++ != '\0');
return (NULL);
}
