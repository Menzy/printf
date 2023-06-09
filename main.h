#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define S_LONG 2
#define S_SHORT 1

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct Format - Struct to choose function for each specifier
 *
 * @Format: The format.
 * @ptr: The function associated.
 */

struct Format
{
	char Format;
	int (*ptr)(va_list, char[], int, int, int, int);
};


typedef struct Format format_t;

int _printf(const char *format, ...);
int func_print(const char *format, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);


int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);


int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int _flags(const char *format, int *i);
int _width(const char *format, int *i, va_list list);
int _size(const char *format, int *i);
int _precision(const char *format, int *i, va_list list);

int append_hexa_code(char, char[], int);
int is_digit(char);
int is_printable(char);

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int handle_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int handle_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int handle_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int handle_num(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int handle_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);


long int convert_size_unsgnd(unsigned long int num, int size);
long int convert_size_number(long int num, int size);

#endif
