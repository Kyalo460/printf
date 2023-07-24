#include "main.h"

/**
 *print_char- prints a character
 *@len: length of string
 *@arg: list of variadic arguments
 *
 *Return: returns the length (if success)
 */
int print_char(int len, va_list arg)
{
	char char_;

	char_ = va_arg(arg, int);

	write(1, &char_, 1);
	len++;
	return (len);
}
