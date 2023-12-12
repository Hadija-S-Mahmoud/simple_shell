#include "simple-shell.h"
/**
* wrd_cnt - function that counts the number of words in strings
* @strng: string
* @sep: separtor
* @array: pointer
* Return: the number of words in the string
*/
int wrd_cnt(char *strng, char *sep, unsigned int *array)
{
unsigned int a, i, wrd_lengt = 1;
unsigned int wrd_cnt = 0;
char *st_cpy = string;
bool start = false, isdelimiter;
if (!strng)
return (0);
while (!start)
for (i = 0; sep[i]; i++)
{
if (*st_cpy == sep[i])
st_cpy++;
else
start = true;
}
if (!*(st_cpy + 1))
{
array[0] = 1;
return (1);
}
for (a = 1; st_cpy[a]; a++)
{
isdelimiter = delimiter(st_cpy[a], sep);
if (isdelimiter && !(delimiter(st_cpy[a-1], sep)))
{
array[wrd_cnt] = wrd_lengt;
wrd_cnt++;
}
if ((!st_cpy[a + 1]) && !isdelimiter)
{
wrd_lengt++;
array[wrd_cnt] = wrd_lengt;
wrd_cnt++;
break;
}
if (!isdelimiter)
wrd_lengt++;
else
wrd_lengt = 0;
}
return (wrd_cnt);
}
