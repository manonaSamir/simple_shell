#include "main.h"

/**
 * _printf - prints string
 * Return: number of char printed
 */

void _printf(const char *format, ...)
{
	va_list args;
	const char *p;
	char *s;
	int d, m;

	va_start(args, format);
	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == 's')
			{
				s = va_arg(args, char *);
				d = strlen(s);
				m = write(1, s, d);
			}
		}
		else
		{
			m = write(1, p, 1);
		}
		if (!m)
			return;
	}

	va_end(args);
}

/**
 * remove_extra_spaces - function replace char
 * character from the standard input (stdin)
 * Return: end of file
 */
void remove_extra_spaces(char *str)
{
	int i, x;

	for (i = x = 0; str[i]; ++i)
	{
		if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1])))
			str[x++] = str[i];

	}
	str[x] = '\0';
}
