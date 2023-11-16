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

/**
 * free_memory - free array
 * @Line_size: string to be splited
 * @count: string to be splited
 * Return:1 if success 0 if not
 */

void free_memory(char **Line_size, int count)
{
	int j = 0;
	for (; j < count; j++)
	{
		free(Line_size[j]);
	}
	free(Line_size);
}

/**
 * containsBigSpace - containsBigSpace
 * @str: string to be splited
 * Return:1 if success 0 if not
 */
int containsBigSpace(const char *str)
{
	int i = 0;

	while (*str)
	{
		if (isspace(*str))
			i++;
		if (i > 1)
			return (1);
		str++;
	}
	return (0);
}
