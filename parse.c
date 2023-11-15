#include "main.h"

/**
 * split_command - split a user input to small strings
 * @command: string to be splited
 *
 * Return: new array
 */

char **split_command(char *command)
{
	int buffer = 64, i = 0;
	char **Line_size = malloc(buffer * sizeof(char *)),
		 *small_str = malloc(1024 * sizeof(char *)), *token,
		 *path = _getenv("PATH");

	error_size(Line_size);
	token = strtok(command, " \t\r\n\a\"");

	if (access(token, F_OK) == -1 && path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", commands, command);
		exit(127);
	}

	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		if (!_strstr(token, "/bin/") && !_strstr(token, "/") && concate_command(token) == 1)
		{
			_strcat(small_str, "/bin/");
			_strcat(small_str, token);
			Line_size[i++] = small_str;
		}
		else
			Line_size[i++] = token;

		if (i >= buffer)
		{
			buffer += buffer;
			Line_size = realloc(Line_size, buffer * sizeof(char *));
			error_size(Line_size);
		}
		token = strtok(NULL, " \t\r\n\a\"");
	}
	free(small_str);
	return (Line_size);
}
