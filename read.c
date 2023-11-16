#include "main.h"

/**
 * read_command - read a line from stdin
 *
 * Return: pointer that points to a str with the line content
 */

char *read_command(void)
{
	ssize_t count;
	char *line = NULL;
	size_t bufsize = 0;
	char buffer[10];
	int fptr;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		fptr = open("/dev/stdin", O_RDONLY);
		count = read(fptr, buffer, 10);
		if (count == 0)
		{
			free(line);
			close(fptr);
			exit(0);
		}
		else
		{
			free(line);
			close(fptr);
			perror(commands);
			exit(1);
		}
		close(fptr);
	}

	return (line);
}

/**
 * read_fstream - read a line from the stream
 *
 * Return: void func
 */

char *read_fstream(void)
{

	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar();
		if (character == EOF)
		{
			free(line);

			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i++] = '\0';
			return (line);
		}
		else
			line[i++] = character;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
