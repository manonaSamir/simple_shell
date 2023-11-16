#include "main.h"


int setenv_command(const char *variable, const char *value, int overwrite)
{

	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "setenv: Missing argument\n");
		return -1;
	}


	if (getenv(variable) != NULL && overwrite == 0)
	{
		fprintf(stderr, "setenv: Variable %s already exists and overwrite is not allowed\n", variable);
		return -1;
	}


	if (setenv(variable, value, 1) != 0)
	{
		fprintf(stderr, "setenv: Unable to set environment variable %s\n", variable);
		return -1;
	}

	return 0;
}


int unsetenv_command(const char *variable)
{

	if (variable == NULL)
	{
		fprintf(stderr, "unsetenv: Missing argument\n");
		return -1;
	}


	if (getenv(variable) == NULL)
	{
		fprintf(stderr, "unsetenv: Variable %s does not exist\n", variable);
		return -1;
	}

	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "unsetenv: Unable to unset environment variable %s\n", variable);
		return -1;
	}

	return 0;
}