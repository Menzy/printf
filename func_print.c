#include "main.h"
/**
 * func_print - Prints argument based type
 * @Format: Formatted string to print the arguments.
 * @list: Arguments to be printed.
 * @ind: index
 * @buffer: Buffer array to handle print.
 * @flags: Calculates the active flags
 * @width: gets the width.
 * @precision: Precision for printing
 * @size: Size to cast the argument
 * Return: 1 or 2;
 */
int func_print(const char *Format, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	format_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'S', print_non_printable}, {'p', print_pointer},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; format_types[i].Format != '\0'; i++)
		if (Format[*ind] == format_types[i].Format)
			return (format_types[i].ptr(list, buffer, flags, width, precision, size));

	if (format_types[i].Format == '\0')
	{
		if (Format[*ind] == '\0')
		{
			return (-1);
		}
		unknown_len += write(1, "%%", 1);
		if (Format[*ind - 1] == ' ')
		{
			unknown_len += write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (Format[*ind] != ' ' && Format[*ind] != '%')
				--(*ind);
			if (Format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &Format[*ind], 1);
		return (unknown_len);
	}
	return (printed_chars);
}
