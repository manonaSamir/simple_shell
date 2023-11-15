#include "main.h"

/**
 * concate_command - check if file exist
 * @command: string to be splited
 *
 * Return: new array
 */

int concate_command(char *command)
{
	int buffer = 1024;
	char *new_paths = malloc(buffer * sizeof(char *));

	_strcpy(new_paths, "/bin/");
	_strcat(new_paths, command);
	if (access(new_paths, F_OK) != -1)
	{
		free(new_paths);
		return (1);
	}
	free(new_paths);
	return (0);
}

/**
 * error_size - check if file exist
 * @size: string to be splited
 *
 * Return:1 if success 0 if not
 */
void error_size(char **size)
{
	if (!size)
	{
		fprintf(stderr, "allocation error in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}
}
