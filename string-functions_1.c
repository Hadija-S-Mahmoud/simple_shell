#include "simple-shell.h"
/**
* str_lent - function that returns the length of the string
* @c: string
* Return: length
*/
int str_lent(char *c)
{
int a = 0;
if (!c)
return (0);
while (*c++)
a++;
return (a);
}
/**
* str_cmp - function that compares strings
* @d1: first string
* @d2: second
* Return: negative, positive, zero
*/
int str_cmp(char *d1, char *d2)
{
while (*d1 && *d2)
{
if (*d1 != *d2)
return (*d1 - *d2);
d1++;
d2++;
}
if (*d1 == *d2)
return (0);
else
return (*d1 < *d2 ? -1 : 1);
}
/**
* starter - function that checks if needle starts with haystack
* @needle: substring
* @haystack: string
* Return: address or NULL
*/
char starter(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
* str_cat - function that concatenates strings
* @des: destination to buffer
* @srce: source
* Return: pointer
*/
char *str_cat(char des, char *srce)
{
char *r = des;
while (*des)
des++;
while (*srce)
*des++ = *srce++;
*des = *srce;
return (r);
}
