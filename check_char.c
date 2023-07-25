#include "main.h"
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

	else if (format == 'd' || format == 'i')
	{
		len = print_int(len, arg);
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
