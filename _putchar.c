#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On (Success) 1, if error -1, error is set appropriately
 */
int _putchar(char c)
{
	return (buffer(c));
}
/**
 * buffer - save the character in a buffer.
 * @c: character
 * Return: 1
 */
int buffer(char c)
{
	static char buffering[1024];
	static int i;

	if (c == -1 || i == 1024)
	{
		write(1, buffering, 1);
		i = 0;
	}

	if (c != -1)
		buffering[i++] = c;
	return (1);
}
