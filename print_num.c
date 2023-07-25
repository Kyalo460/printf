#include "main.h"
#include <stdlib.h>
/**
  *print_num - prints num one character at a time
  *@len: number of characters
  *@num: number to print
  *
  *Return: returns the number of characters printed if success
  */
int print_num(int len, int num)
{
	int numdig = 1;
	int temp;
	int i, len2 = 0;
	char *num_array;

	if (num < 0)
	{
		write(1, "-", 1);
		num = (num * -1);
		len2++;
	}
	temp = num;

	while (temp >= 10)
	{
		temp = (temp / 10);
		numdig++;
	}
	i = numdig - 1;

	num_array = malloc(numdig);
	if (num_array == NULL)
		return (-1);

	while (num > 0)
	{
		num_array[i] = ((num % 10) + '0');
		num /= 10;
		i--;
	}
	len = numdig + len2;
	write(1, num_array, numdig);
	free(num_array);
	return (len);
}
