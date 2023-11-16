#include "main.h"

/**
 * run_command - create a new process
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */

int run_command(char **args)
{
	pid_t pid;
	int status;

	if (access(args[0], F_OK) != -1)
	{

		pid = fork();
		if (pid == 0)
		{

			if (execve(args[0], args, environ) == -1)
			{
				write(2, commands, strlen(commands));
				write(2, ": 1: ", 5);
				write(2, args[0], strlen(args[0]));
				write(2, ": not found\n", 12);
				exit_status = 127;
				exit(exit_status);
			}
			else
				exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			perror(commands);

		else
		{
			wait(&status);
			exit_status = WIFEXITED(status) ? WEXITSTATUS(status) : 0;
		}
	}
	else
	{
		fprintf(stderr, "%s: %s: command not found\n", commands, args[0]);
		exit_status = 127;
		return (127);
	}

	return (-1);
}
