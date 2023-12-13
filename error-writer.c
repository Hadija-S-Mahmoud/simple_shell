#include "simple-shell.h"
/**
* puts_error - function taht prints input strings
* @strng: string
* Return: void
*/
void puts_error(char *strng)
{
int a = 0;
if (!strng)
return;
while (strng[a] != '\0')
{
putchar_error(strng[a]);
a++;
}
}

/**
* putchar_error - function that writes a character to std erroe
* @z: character to be prointed
* Return: 1 if successful, -1 if failure
*/
int putchar_error(char z)
{
static int a;
static char buffer[WRITE_THE_BUFFER_SIZE];
if (z != B_FLUSH)
buffer[a++] = z;
return (1);
}

/**
* char_writer - function that writes character to give desc
* @z: character to be printed
* @fdesc: file descriptor
* Return: 1 if successful, -1 if failure
*/
int char_writer(char z, int fdesc)
{
static int a;
static char buffer[WRITE_THE_BUFFER_SIZE];
if (z == B_FLUSH || a >= WRITE_THE_BUFFER_SIZE)
{
write(fdesc, buffer, a);
a = 0;
}
if (z != B_FLUSH)
buffer[a++] = z;
return (1);
}

/**
* chars_writer - function that prints an input strng
* @strng: string
* @fdesc: funct descriptor
* Return: number of characters
*/
int chars_writer(char *strng, int fdesc)
{
int b = 0;
if (!strng)
return (0);
while (*strng)
{
b += char_writer(*strng++, fdesc);
}
return (b);

