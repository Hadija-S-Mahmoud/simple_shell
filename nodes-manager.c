#include "simple-shell.h"
/**
* list_lent - funct that gets the len oflinked lists
* @g: pointer
* Return: size of list
*/
size_t list_lent(const list_s *g)
{
size_t a = 0;
while (g)
{
g = g->next;
a++;
}
return (a);
}

/**
* vector_list - funct returning an arr of strngs of list->str
* @headr: pointer
* Return: strings array
*/
char **vector_list(list_s *headr)
{
list_s *node = headr;
size_t a = list_lent(headr), b;
char **strgs;
char *str;
if (!headr || !a)
return (NULL);
strgs = malloc(sizeof(char *) * (a + 1));
if (!strgs)
return (NULL);
for (a = 0; node; node = node->next, a++)
{
str = malloc(str_lent(node->str) + 1);
if (!str)
{
for (b = 0; b < a; b++)
free(strgs[b]);
free(strgs);
return (NULL);
}
str = str_copy(str, node->str);
strgs[a] = str;
}
strgs[a] = NULL;
return (strgs);
}
/**
* list_printer - function printing all elemnts of list_s
* @g: pntr
* Return: list size
*/
size_t list_printer(const list_s *g)
{
size_t a = 0;
while (g)
{
c_puts(base_changer(g->num, 10, 0));
_putchar(':');
_putchar(' ');
c_puts(g->str ? g->str : "(nil)");
c_puts("\n");
g = g->nect;
a++
}
return (a);
}

/**
* str_node_starter - function returning a node with a
* string starting with a prfx
* @node: pntr
* @prfx: strng
* @k: nxt char
* Return: null or matching node
*/
list_s *str_node_starter(list_s *node, char *prfx, char k)
{
char *i = NULL;
while (node)
{
i = starter(node->str, prfx);
if (i && ((k == -1) || (*i == k)))
return (node);
node = node->next;
}
return (NULL);
}

/**
* node_index_getter - function that gets indc of nodes
* @headr: pointr
* @node:pointr node
* Return: indx of node or -1
*/
ssize_t node_index_getter(list_s *headr, list_s *node)
{
size_t f = 0;
while (headr)
{
if (headr == node)
return (f);
f++;
}
return (-1);
}
