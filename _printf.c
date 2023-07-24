#include "main.h"

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
