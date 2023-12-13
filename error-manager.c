#include "simple-shell.h"

/**
 * error_number - function that converts a str to an int
 * @z: string
 * Return: 0 if there are no numbers in string, else -1
 */
int error_number(char *z)
{
	int a = 0;
	unsigned long int result = 0;

	if (*z == '+')
		z++;
	for (a = 0; z[a] != '\0'; ai++)
	{
		if (z[a] >= '0' && z[a] <= '9')
		{
			result *= 10;
			result += (z[a] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * err_printer - function that prints an error message
 * @info: parameter
 * @errstr: string that has a specified error type
 * Return: 0 or -1
 */
void err_printer(info_s *info, char *errstr)
{
	puts_error(info->program_name);
	puts_error(": ");
	dec_printer(info->err_nom, STDERR_FILENO);
	puts_error(": ");
	puts_error(info->argv[0]);
	puts_error(": ");
	puts_error(errstr);
}
/**
 * dec_printer - function that prints a decimal number
 * @input: input
 * @fdesc: the file descriptor to write to
 * Return: the number of characters to be printed
 */

int dec_printer(int input, int fdesc)
{
	int (*__putchar)(char) = _putchar;
	int a, count = 0;
	unsigned int _abs_, current;

	if (fdesc == STDERR_FILENO)
		__putchar = putchar_error;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (a = 1000000000; a > 1; a /= 10)
	{

		if (_abs_ / a)
		{
			__putchar('0' + current / a);
			count++;
		}
		current %= a;
	}
	__putchar('0' + current);
	count++;
	return (count);
}
/**
 * base_changer - function that is a convertoer
 * @nom: number
 * @base: base
 * @flags: argument
 * Return: the str
 */
char *base_changer(long int nom, int base, int flags)
{
	char s = 0;
	char *pntr;
	unsigned long i = nom;

	static char *array;
	static char buffer[50];

	if (!(flags & BAS_CHANGE_UNSIG) && nom < 0)
	{
		i = -nom
		s = '-';
	}
	array = flags & CVT_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	pntr = &buffer[49];
	*pntr = '\0';
	do {
		*--pntr = array[i % base];
		i /= base;
	} while (i != 0);
	if (s)
		*--pntr = s;
	return (pntr);
}

/**
 * comment_handler - function that replaces the first instance of '#' with '\0'
 * @buffr: address
 * Return: 0;
 */

void comment_handler(char *buffr)
{
	int j;

	for (j = 0; buffr[j] != '\0'; j++)
		if (buffr[j] == '#' && (!j || buffr[j - 1] == ' '))
		{
			buffr[j] = '\0';
			break;
		}
}

