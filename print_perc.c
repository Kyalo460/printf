#include "main.h"
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
