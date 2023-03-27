#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int size;
	va_list list;

	if (format == NULL)
		return (-1);

	size = _strlen(format);
	if (size <= 0)
		return (0);

	va_start(list, format);
	size = handler(format, list);

	_putchar(-1);
	va_end(list);

	return (size);
}
/**
 * _strlen - computes the length of a string
 * @str: string
 *
 * Return: Length
 */
int _strlen(const char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
	
	return (i);
}
