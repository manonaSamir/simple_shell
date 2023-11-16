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
	char **path = NULL, *test = NULL,
		 *Line_size = NULL, *token = NULL;

	if (removeSpaces(command) == NULL)
		return (0);

	Line_size = malloc(buffer * sizeof(char *));
	error_size(Line_size);
	path = getenv("PATH");

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
		if (!_strstr(token, "/bin/") && !_strstr(token, "/")
		&& concate_command(token) == 1)
			Line_size[i++] = addingstr(token);
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
	Line_size[i] = NULL;
	free(test);
	return (Line_size);
}
