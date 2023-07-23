#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
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
		string = "(NULL)";

	write(1, string, strlen(string));
	len += strlen(string);
	return (len);

}
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
/**
  *print_perc - prints %
  *@len: length of string
  *
  *Return: returns the length (if success)
  */
int print_perc(int len)
{
	char char_ = '%';

	write(1, &char_, 1);
	len++;
	return (len);
}
/**
  *_printf - Replica of printf funtion
  *@format: contains normal characters & format specifiers
  *
  *Return: Length of String
  */
int _printf(const char *format, ...)
{
	int i = 0, len = 0;
	char char_format;
	/*char *string;*/
	va_list arg;

	va_start(arg, format);
	if (format != NULL)
	{
		for (i = 0; format[i]; i++)
		{
			if (format[i] == '%')
			{
				i++;
				if (format[i] == 'c')
					len = print_char(len, arg);

				else if (format[i] == 's')
					len = print_string(len, arg);

				else if (format[i] == '%')
					len = print_perc(len);

				else
					return (-1);

				i++;
			}
			if (format[i] == '%')
				continue;
			char_format = format[i];
			if (char_format == '\0')
				break;
			write(1, &char_format, 1);
			len++;
		}
	}
	else
		return (-1);
	return (len);
}
