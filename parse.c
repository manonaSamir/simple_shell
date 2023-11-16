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
	char **Line_size = NULL,
		 *small_str = NULL, *token = NULL,
		 *path = NULL;

	if (containsBigSpace(command) == 1)
		return (0);

	Line_size = malloc(buffer * sizeof(char *));
	error_size(Line_size);
	path = getenv("PATH");

	/*if (!Line_size)
	{
		fprintf(stderr, "allocation error in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}*/

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
			small_str = malloc((strlen("/bin/") + strlen(token) + 1) * sizeof(char));
			/*malloc(1024 * sizeof(char *));*/
			if (!small_str)
			{
				fprintf(stderr, "allocation error in split_line: tokens\n");
				exit(EXIT_FAILURE);
				free_memory(Line_size, i);
			}
			_strcpy(small_str, "/bin/");
			_strcat(small_str, token);
			Line_size[i++] = small_str;
			small_str = NULL;
			free(small_str);
		}
		else
			Line_size[i++] = token;

		if (i >= buffer)
		{
			buffer += buffer;
			Line_size = realloc(Line_size, buffer * sizeof(char *));
			/*error_size(Line_size);*/
			if (!Line_size)
			{
				fprintf(stderr, "allocation error in split_line: tokens\n");
				Line_size = NULL;
				free(Line_size);
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a\"");
	}

	Line_size[i] = NULL;
	/*for (; j < i; j++)
	{
		printf("%s\n", Line_size[j]);
	}*/
	return (Line_size);
}
