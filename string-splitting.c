#include "simple-shell.h"
/**
* string_splitter - function that splits a string into wrds
* @str: string
* @sep: delimiters
* @wrd_cnt: wrds number in string
* Return: pointr to strng vect
*/
char **string_splitter(char *str, char *sep, size_t *wrd_cnt)
{
int u, wrds_num;
char **wrds;
char *str_pntr = str;
unsigned int d, wrd_sizes[MAXIMUM_COUNT];
zero_setter(wrd_sizes, MAXIMUM_COUNT);
wrds_num = wrd_cnt(str, sep, wrd_sizes);
if (wrds_num == 0)
return (NULL);
wrds = malloc((sizeof(char *) * wrds_num) +1);
if (!wrds)
return (NULL);
for (u = 0; u < wrds_num; u++)
{
wrds[u] = malloc((sizeof(char) * wrd_sizes[u]) + 1);
if (!wrds[u])
{
for (u--; u >= 0; u--)
free(wrds[u]);
free(wrds);
return (NULL);
}
for (d = 0; d < wrd_sizes[u]; d++, str_pntr++)
{
while (delimiter(*str_pntr, sep))
str_pntr++;
wrds[u][d] = *str_pntr;
};
wrds[u][d] = '\0';
}
*wrd_cnt = wrds_num;
wrd[u] = NULL;
return (wrds);
}

#include "simple-shell.h"
/**
* *str_towr - function tht splits strng int words
* @str: input strng
* @y: delimite str
* Return: NULL if failure and point of arr of strimgs
*/
char **str_towr(char *str, char *y)
{
int a, b, c, d, numberwrds = 0;
char **e;
if (str == NULL || str[0] == 0)
return (NULL);
if (!y)
y = " ";
for (a = 0; str[a] != '\0'; a++)
if (!delimiter(str[a], y) && (delimiter(str[a + 1], y) || !str[a + 1]))
numberwrds++;
if (numberwrds == 0)
return (NULL);
e = malloc((1 + numberwrds) *sizeof(char *));
if (!e)
return (NULL);
for (a = 0, b = 0; b < numberwrds; b++)
{
while (delimiter(str[a], y))
a++;
c = 0;
while (!delimiter(str[a + c], y) && str[a + c])
c++;
e[b] = malloc((c + 1) * sizeof(char));
if (!e[b])
{
for (c = 0; c < b; c++)
free(e[c]);
free(e);
return (NULL);
}
for (d = 0; d < c; d++)
e[b][d] = str[a++];
e[b][d] = 0;
}
e[b] = NULL;
return (e);
}
