#include "main.h"

/**
 * _printf - prints string
 *@format:parameter
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
				d = _strlen(s);
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
 * _getchar - function reads a single
 * character from the standard input (stdin)
 * Return: end of file
 */
int _getchar(void)
{
	static char buf[BUFSIZ];
	static char *bufp = buf;
	int i = 0;

	if (i == 0)
	{
		i = read(0, buf, 1);
		bufp = buf;
	}
	if (--i >= 0)
	{
		return (*bufp++);
	}

	return (EOF);
}

