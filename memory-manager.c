#include "simple-shell.h"
/**
* memory_set - funct that fills mem wth const bytes
* @z: pointer to memory area
* @a: byte to fill *s
* @y: amount of byts
* Return: z
*/
char *memory_set(char *z, char a, unsigned int y)
{
unsigned int h;
for (h = 0; h < y; h++)
z[h] = a;
return (z);
}
/**
* fr_vector - function freeing mem in two-dimensional chars
* @vect: vector
* Return: notn
*/
void fr_vector(char **vect)
{
char **pntr = vectr;
if (!vectr)
return;
while (*vectr)
free(*vectr++);
free(pntr);
}
/**
 * real_loct - Function that handles reallocation of blocks of memory
 * @p: pointer
 * @sz_old: size of byte of prev block
 * @sz_new: size of byte of nw block
 * Return: the pntr to the older block
 */

void *real_loct(void *p, unsigned int sz_old, unsigned int sz_new)
{
char *t;
if (!p)
return (malloc(sz_new));
if (!sz_new)
return (free(p), NULL);
if (sz_new == sz_old)
return (p);
t = malloc(sz_new);
if (!t)
return (NULL);
sz_old = sz_old < sz_new ? sz_old : sz_new;
while (sz_old--)
t[sz_old] = ((char *)p)[sz_old];
free(p);
return (t);
}

#include "simple-shell.h"
/**
 *freeb - function that makes a pointer free and the address NULL
 * @pntr: address
 * Return: 1 if successful, 0 if failure
 */
int freeb(void **pntr)
{
if (pntr && *pntr)
{
free(*pntr);
*pntr = NULL;
return (1);
}
return (0);
}

