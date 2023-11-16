#include "main.h"

/**
 * Shell_Interactive - function run when user typing
 * @isActive : parameter
 * Return: void
 */

void Shell_Interactive(int isActive)
{
	char *command;
	char **args;
	int fstate = -1;
	int i = 0;


	for (; fstate == -1; i++)
	{
		if (isActive == 1)
		{
			_printf("%s", "$ ");
			command = read_command();
		}
		else
			command = read_fstream();

		if (command == NULL)
			continue;

		args = split_command(command);
		if (args == NULL)
		{
			free(command);
			continue;
		}
		fstate = execution(args);
		free(command);
		free(args);
		if (fstate >= 0)
		{
			exit(fstate);
		}
	}
}
