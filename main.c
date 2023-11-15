#include "main.h"

/**
 * main -point of fire simple shell
 * @argc: parametr int
 *@argv:parametwr  array
 * Return: (0) on SUCCESS
 */

int main(int argc, char *argv[])
{
	int fill = STDIN_FILENO;

	commands = argv[0];
	(void)argc;

	if (isatty(fill) == 1)
		Shell_Interactive(1);
	else
		Shell_Interactive(0);
	exit(exit_status);

	return (0);
}
