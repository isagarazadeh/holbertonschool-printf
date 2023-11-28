#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - function
 * @format: var
 * Return: return success
 */
int _printf(const char *format, ...)
{
	char *s;
	int count = 0;
	int i = 0;
	va_list args;

	va_start(args, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case '\0':
					break;
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					count += write(1, s, strlen(s));
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;

			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	if (!count)
		return (-1);
	va_end(args);
	return (count);
}
