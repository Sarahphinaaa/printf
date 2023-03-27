#include "main.h"

/**
* handle_print - prints an argument based on its type
* @format: the formatted string used to print the arguments
* @list: list of arguments
* @ind: ind
* @buffer: Buffer array to handle print
* @flags: computes active flags
* @width: get width
* @precision: Precision specification
* @size: size specifier
* Return: 1 or 2
*/
int handle_print(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	format_t format_types[] = {
	{'c', print_char}, {'s', print_string}, {'%', print_percentg},
	{'i', print_int}, {'d', print_int}, {'b', print_binary},
	{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
	{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
	{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	}
	for (i = 0; format_types[i].format != '\0'; i++)
	{
		if (format[*ind] == format_types[i].format)
		{
			return (format_types[i].format(list, buffer, flags,
						width, precision, size));
		}
	}
	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
		{
			return (-1);
		}
		unknown_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
		{
			unknown_len += write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &format[*ind], 1);
		return (unknown_len);
	}
	return (printed_chars);
}
