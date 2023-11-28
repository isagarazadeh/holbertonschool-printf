#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"
/**
 * _printf - function
 * @format: var
 * Return: return success
 */
int _printf(const char *format, ...)
{
	char c, *s;
	int count = 0;
	int i = 0;
	va_list args;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					_putchar(c);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					_putchar(s[count]);
					count += strlen(s);
					break;
				case '%':
					_putchar('%');
					count++;
					break;

			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}