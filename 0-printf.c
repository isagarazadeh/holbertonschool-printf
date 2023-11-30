#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
int print_int(unsigned int r, int s);
/**
 * _printf - functions
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
		if ((format[i] == '%') && (format[i + 1] == 'd'
			|| (format[i + 1] == 'i')))
		{
			count = print_int(count, va_arg(args, int));
			i++;
		}
		else if (format[i] == '%')
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
					count += write(1, "%", 1), count += write(1, format + i, 1);
					break;
			}
		}
		else
			_putchar(format[i]), count++;
	}
	if (count == 0)
		return (-1);
	va_end(args);
	return (count);
}
/**
* print_int - for printing numbers
* @r: count of numbers
* @s: number string
* Return: count of numbers
*/
int print_int(unsigned int r, int s)
{
	int m = 0, c = 0;
	unsigned int n;
	char number[11];

	if (s < 0)
	{
		_putchar('-');
		r++;
		n = -1 * s;
	}
	else
		n = s;
	if (n == 0)
	{
		_putchar(48);
		return (r + 1);
	}
	while (n > 0)
	{
		m = n % 10;
		number[c] = m + 48;
		n = n / 10;
		c++;
	}
	r = r + c;
	c = c - 1;
	for (; c >= 0; c--)
	{
		_putchar(number[c]);
	}
	return (r);
}
