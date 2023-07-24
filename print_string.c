#include "main.h"

/**
 *print_string - prints a string
 *@len: length of string
 *@arg: list of variadic arguments
 *
 *Return: returns the length (if success)
 */
int print_string(int len, va_list arg)
{
	char *string;

	string = va_arg(arg, char *);

	if (string == NULL)
	string = "(null)";

	write(1, string, strlen(string));
	len += strlen(string);
	return (len);
}
