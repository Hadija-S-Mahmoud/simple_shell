#include "simple-shell.h"
/**
 * add_start_node - function that adds a node to start of a list
 * @headr: address
 * @str: str
 * @nom: node indx
 * Return: the size of the list
 */
list_s *add_start_node(list_s **headr, const char *str, int nom)
{
list_s *n_headr;
if (!headr)
return (NULL);
n_headr = malloc(sizeof(list_s));
if (!n_headr)
return (NULL);
memory_set((void *)n_headr, 0, sizeof(list_s));
n_headr->nom = nom;
if (str)
{
n_headr->str = strd_up(str);
if (!n_headr->str)
{
free(n_headr);
return (NULL);
}
}
n_headr->next = *headr;
*headr = n_headr;
return (n_headr);
}

/**
 * add_end_node - function that adds a node to list ends
 * @headr:addres
 * @str: str
 * @nom: node index
 * Return: the size of the list
 */
list_s *add_end_node(list_s **headr, const char *str, int nom)
{
list_s *n_node, *node;
if (!headr)
return (NULL);
node = *headr;
n_node = malloc(sizeof(list_s));
if (!n_node)
return (NULL);
memory_set((void *)n_node, 0, sizeof(list_s));
n_node->nom = nom;
if (str)
{
n_node->str = strd_up(str);
if (!n_node->str)
{
free(n_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = n_node;
}
else
*headr = n_node;
return (n_node);
}

/**
 * str_list_printer - function that prints the string element
 * of a list_s linked list only
 * @z: the pointer to fst node
 * Return: size
 */
size_t str_list_printer(const list_s *z)
{
size_t a = 0;
while (z)
{
c_puts(z->str ? z->str : "(nil)");
c_puts("\n");
z = z->next;
a++;
}
return (a);
}

/**
 * deleting_node - function that deletes a node at gvn indx
 * @headr: address
 * @indx: indx
 * Return: 1 if successful, 0 if failure
 */
int deleting_node(list_s **headr, unsigned int indx)
{
list_s *node, *p_node;
unsigned int a = 0;
if (!headr || !*headr)
return (0);
if (!indx)
{
node = *headr;
*headr = (*headr)->next;
free(node->str);
free(node);
return (1);
}
node = *headr;
while (node)
{
if (a == indx)
{
p_node->next = node->next;
free(node->str);
free(node);
return (1);
}
a++;
p_node = node;
node = node->next;
}
return (0);
}
/**
 * fr_list - function that frees all the nodes of a list
 * @hd_pntr: address
 * Return: void
 */
void fr_list(list_s **hd_pntr)
{
list_s *node, *nxt_node, *headr;
if (!hd_pntr || !*hd_pntr)
return;
headr = *hd_pntr;
node = headr;
while (node)
{
nxt_node = node->next;
free(node->str);
free(node);
node = nxt_node;
}
*hd_pntr = NULL;
}
