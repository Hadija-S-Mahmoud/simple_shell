#include "shell.h"

/**
 **_memset - function that fills mem with a constant byte
 *@s: pontr to mem
 *@b: bytes
 *@n: bytes to fill
 *Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int r;
for (r = 0; r < n; r++)
s[r] = b;
return (s);
}

/**
 * ffree - function that frees string of strings
 * @a: strng
 */
void ffree(char **a)
{
char **h = a;
if (!a)
return;
while (*a)
free(*a++);
free(h);
}

/**
 * _realloc - function that reallocates block of mem
 * @ptr: pntr
 * @old_size: prev blck byte sz
 * @new_size: nw blck byte sz
 * Return: old blcks pntr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *i;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
i = malloc(new_size);
if (!i)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
i[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (i);
}
