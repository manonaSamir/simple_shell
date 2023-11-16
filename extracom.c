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
 * removeSpaces - containsBigSpace
 * @input: string to be splited
 * Return:1 if success 0 if not
 */

char *removeSpaces(const char *input)
{
	size_t j = 0, i, len;
	char *result = NULL;

	if (input == NULL)
		return (NULL);
	len = strlen(input);
	result = (char *)malloc(len + 1);
	if (result == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < len; i++)
	{
		if (input[i] != ' ')
			result[j++] = input[i];
	}
	result[j] = '\0';
	if (j == 0)
	{
		free(result);
		return (NULL);
	}

	return (result);
}

/**
 * addingstr - free array
 * @Line_size: string to be splited
 * Return:1 if success 0 if not
 */

char *addingstr(char *token)
{
	char *small_str = NULL;

	small_str = malloc((strlen("/bin/") + strlen(token) + 1) * sizeof(char));
	if (!small_str)
	{
		fprintf(stderr, "allocation error in split_line: tokens\n");
		exit(EXIT_FAILURE);
		free(small_str);
	}
	_strcpy(small_str, "/bin/");
	_strcat(small_str, token);
	return (small_str);
}
