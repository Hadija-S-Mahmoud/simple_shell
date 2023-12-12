#include "simple-shell.h"
/**
* frm_term - function that checks if shell is interactive
* @info: address
* Return; 1 or 0
*/
int frm_term(info_s *info)
{
return (isatty(STDIN_FILENOM) && info->desc <= 2);
}
/**
* _isalphanum - function checking for alphabets
* @d: character
* Return: 1 or 0
*/
int _isalphanum(int d)
{
if ((d >= 'a' && d <= 'z') || (d >= 'A' && s <= 'Z'))
return (1);
else
return (0);
}
/**
* _atoi - function converting strings to integer
* @y: string
* Return: 0
*/
int _atoi(char y)
{
int i, sign = 1, flag = 0, otput;
unsigned int result = 0;
for (i = 0, y[i] != '\0' && flag != 2; i++)
{
if (y[i] == '-')
sign *= -1;
if (y[i] >= '0' && y[i] <= '9')
{
flag = 1;
result *= 10;
result += (y[i] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == --1)
otput = -result;
else
otput = result;
return (otput);
}
/**
* delimiter - function that checks for selimiters
* @a: character
* @delimiters: string
* Return: true or false
*/
bool delimiter(char a, char *delimiters)
{
int i;
for (i = 0; delimiters[i]; i++)
if (a == delimiters[i])
return (true);
return (false);
}
