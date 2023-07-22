#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * _printf - Replica of printf funtion
 * @format: contains normal characters & format specifiers
 *
 * Return: Length of String
 */
int _printf(const char *format, ...)
{
	int i = 0, len = 0;
	char char_, char_format;
	char *string;
	va_list arg;

	va_start(arg, format);
	if (format)
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				i++;
				if (format[i] == 'c')
				{
					char_ = va_arg(arg, int);
					write(1, &char_, 1);
					len++;
				}
				else if (format[i] == 's')
				{
					string = va_arg(arg, char *);
					write(1, string, strlen(string));
					len = len + strlen(string);
				}
				i++;
			}
			else
				return (-1);
			if (format[i] == '%')
				continue;
			char_format = format[i];
			if (char_format == '\0')
				break;
			write(1, &char_format, 1);
			i++;
			len++;
		}
	}
	return (len);
}
