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
	int i, count = 0;
	va_list args;

	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case '\0':
					i--;
					break;
				case 'c':
					_putchar(va_arg(args, int)), count++;
					break;
				case 's':
					s = va_arg(args, char *);
					s == NULL ? s = "(null)" : s, count += write(1, s, strlen(s));
					break;
				case '%':
					write(1, "%", 1), count++;
					break;
				default:
					count += write(1, "%", 1);
					count += write(1, format + i, 1);
					break;
			}
		}
		else
		{
			_putchar(format[i]), count++;
		}
	}
	if (count == 0)
		return (-1);
	va_end(args);
	return (count);
}
