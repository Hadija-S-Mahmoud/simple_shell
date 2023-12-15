#include "shell.h"
/**
 * _strlen - function that returns the lengh of a strng
 * @s: string
 * Return: lengt of strng
 */
int _strlen(char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}

/**
 * _strcmp - function that performs comparison of two strngs.
 * @s1: first
 * @s2: second
 * Return: negative or zero
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - function that checks if needle starts with haystack
 * @haystack: strg
 * @needle: substring
 * Return: address or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strcat - funct that concatenates two strings
 * @dest: dest buffer
 * @src: srce buffer
 * Return: pontr to  dest buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
