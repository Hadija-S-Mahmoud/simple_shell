#include "shell.h"

/**
 * is_chain - function that tests if the current char in the buf is a chain delimeter
 * @info: parameter
 * @buf: char buffer
 * @p: the address of currnt pos in buf
 * Return: 1 if successful, 0 if failure
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t j = *p;
if (buf[j] == '|' && buf[j + 1] == '|')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[j] == '&' && buf[j + 1] == '&')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[j] == ';')
{
buf[j] = 0;
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = j;
return (1);
}

/**
 * check_chain - function checking if we should cont chaining based on the last stat
 * @info: param
 * @buf: char buf
 * @p: addrs currnt pos in buf
 * @i: start pos in buf
 * @len: the leng
 * Return: void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t j = *p;
if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
j = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
j = len;
}
}
*p = j;
}

/**
 * replace_alias - funct that replaces aliases in tokenized strng
 * @info: param
 * Return: 1 if successful, 0 on failure
 */
int replace_alias(info_t *info)
{
int i;
list_t *node;
char *p;
for (i = 0; i < 10; i++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}

/**
 * replace_vars - function that replace variables in tokenized strng
 * @info: param
 * Return: 1 if successful, 0 on failure
 */
int replace_vars(info_t *info)
{
int i = 0;
list_t *node;
for (i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] != '$' || !info->argv[i][1])
continue;
if (!_strcmp(info->argv[i], "$?"))
{
replace_string(&(info->argv[i]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[i], "$$"))
{
replace_string(&(info->argv[i]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[i][1], '=');
if (node)
{
replace_string(&(info->argv[i]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[i], _strdup(""));
}
return (0);
}

/**
 * replace_string - function that replaces strings
 * @old: old string address
 * @new: new string address
 * Return: 1 if successful, 0 on failure
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
