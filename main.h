#ifndef PRINTF_H
#define PRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
  *printf.h - this file will contain our prototypes
  *_printf - variadic function
  *@format: the format specifiers
  *
  *Return: returns something
  */
int _printf(const char *format, ...);
int print_string(int len, va_list arg);
int print_char(int len, va_list arg);
int print_perc(int len);
int check_char(char format, int len, va_list arg);
#endif
