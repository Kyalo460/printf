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
		string = "(null)";

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
  *check_char - checks if character is special
  *@format: contains a character
  *@len: length of output
  *@arg: list of variadic arguments
  *
  *Return: Length of String (if success)
  */
int check_char(char format, int len, va_list arg)
{
	if (format == 'c')
	{
		len = print_char(len, arg);
		return (len);
	}

	else if (format == 's')
	{
		len = print_string(len, arg);
		return (len);
	}

	else if (format == '%')
	{
		len = print_perc(len);
		return (len);
	}

	else if (format == ' ')
		return (-1);

	else if (format == '\0')
		return (-1);

	else
	{
		len = print_perc(len);
		write(1, &format, 1);
		len++;
	}

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
	va_list arg;

	va_start(arg, format);
	if (format != NULL)
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				i++;
				if (format[i] == '\0')
					return (-1);
				char_format = format[i];

				len = check_char(char_format, len, arg);
				i++;
			}
			else if (format[i] != '%' && format[i] != '\0' && len != -1)
			{
				char_format = format[i];
				write(1, &char_format, 1);
				len++;
				i++;
			}
			else
				return (-1);

		}
	}
	else
		return (-1);
	return (len);
}
