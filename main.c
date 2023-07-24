#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

int main()
{
	int lenght;

	lenght = _printf("Hello % World");
	printf("\n%d", lenght);

	return (0);
}

