#include "main.h"
#include <limits.h>
/**
  *print_int - calls a function that prints integers
  *@len: length of characters
  *@arg: variadic list
  *
  *Return: returns length of printed characters if success
  *        return -1 if unsuccessful
  */
int print_int(int len, va_list arg)
{
	int num;

	num = va_arg(arg, int);

	if (num > INT_MAX || num < INT_MIN)
		return (-1);

	else
	{
		len += print_num(len, num);
		return (len);
	}
}
