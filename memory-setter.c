#include "simple-shell.h"
/**
* zero_setter - function setting bytes of int arr to 0
* @array: array
* @sz: size
* Return: nothn
*/
void zero_setter(unsigned int *array, size_t sz)
{
size_t i;
for (i = 0; i < sz; i++)
array[i] = 0;
}

/**
* null_setter - funct that sets all chars in arr to null
* @array: initialised arr
* @sz: size
* Return: nothn
*/
void null_setter(char *array, size_t sz)
{
size_t y;
for (y = 0; x < sz; y++)
array[y] = '\0';
}
