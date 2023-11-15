#include "main.h"

/**
 * cd_func - changes the working dir of the current shell executon env
 * @args: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int cd_func(char **args)
{
	char *dir = args[1];
	char *home = getenv("HOME");
	char *old = getenv("OLDPWD");
	char current[256];

	getcwd(current, sizeof(current));
	if (home == NULL)
		home = current;
	if (old == NULL)
		old = current;
	if (dir == NULL)
	{
		setenv("OLDPWD", current, 1);
		chdir(home);
		setenv("PWD", home, 1);
	}
	else if (_strcmp(dir, "-") == 0)
	{
		chdir(old);
		setenv("PWD", old, 1);
		setenv("OLDPWD", current, 1);
		getcwd(current, sizeof(current));
		_printf("%s\n", current);
	}
	else
	{
		if (chdir(dir) != 0)
			fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", dir);
		else
		{
			setenv("OLDPWD", current, 1);
			setenv("PWD", dir, 1);
		}
	}

	/*free(args);*/
	return (-1);
}

/**
 * env_func - enviroment function
 * @args:an array of all variable in string
 *
 * Return: an integer
 */
int env_func(char **args)
{
	int i = 0;

	args = environ;
	if (args[1] != NULL)
		fprintf(stderr, "env: %s: No such file or directory\n", args[1]);
	while (args[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	/*free_arr(arg);*/
	return (-1);
}

int exit_status = 0;
char *commands;
/**
 * exit_func - exit the shell
 * @args: an array of command
 *
 * Return: an interger
 */
int exit_func(char **args)
{
	char *first;
	char *second;
	int i;

	if (args == NULL || args[0] == NULL)
		return (0);
	first = args[0];
	second = (args[1] != NULL) ? args[1] : NULL;
	if (strcmp(first, "exit") == 0)
	{
		if (second != NULL)
		{
			for (i = 0; second[i] != '\0'; i++)
			{
				if (second[i] < '0' || second[i] > '9')
				{
					fprintf(stderr, "%s: 1: exit: Illegal number: %s\n",
							commands, second);
					exit_status = 2;
					return (exit_status);
				}
			}
			exit_status = atoi(second);
		}
		else
		{
			return (0);
		}

		return (exit_status);
	}

	return (0);
}

/**
 * _getenv - exit the shell
 * @name: an array of command
 *
 * Return: an interger
 */

char *_getenv(const char *name)
{
	int i = 0;
	char *env_var;

	for (; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		if (strncmp(env_var, name, strlen(name)) == 0 &&
			env_var[strlen(name)] == '=')
		{
			return (env_var + strlen(name) + 1);
		}
	}
	return (NULL);
}
