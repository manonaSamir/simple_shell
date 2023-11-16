#include "main.h"
/**
 * execution - map if command is a builtin or a process
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int execution(char **args)
{

	if (args[0] == NULL)
		return (-1);

	if (_strcmp(args[0], "exit") == 0)
		return (exit_func(args));

	else if (_strcmp(args[0], "env") == 0)
		return (env_func(args));

	else if (_strcmp(args[0], "cd") == 0)
		return (cd_func(args));



	return (run_command(args));
}
