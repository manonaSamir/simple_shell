#include "main.h"

/**
 * _strstr - function that locates a substring.
 * @haystack: source string to search through.
 * @needle: string to search for.
 * Return: return beginning of located substring or NULL.
 */

char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j = 0;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[j])
			j++;
		if (needle[j] == '\0' && j > 0)
			return ((haystack + i - j + 1));
		else if (needle[j] == '\0' && j < 1)
			return (haystack);
	}
	return (NULL);
}

/**
 * *_strcat - concatenates two strings
 * @dest: pointer to first value
 * @src: pointer to second value
 * Return: a pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	unsigned int i, j = 0;

	for (i = strlen(dest); j <= strlen(src); i++)
	{
		dest[i] = src[j];
		j++;
	}
	return (dest);
}

/**
 * _strcmp -  compares two strings
 * @s1: @s1: the string to compare
 * @s2: @s1: the string to compare
 * Return: a int value.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
	}
	return (s1[i] - s2[i]);
}

/**
 * _strlen - function that returns the length of a string.
 * @s: string to measure.
 *
 * Return: Length of the string as INT.
 */

int _strlen(char *s)
{
	if (*s)
		return (1 + _strlen((s + 1)));
	return (0);
}

/**
 * _strcpy - fuction copies the string pointed
 * @dest: pointer to copy the string to.
 * @src: the string to copy to the destination.
 *
 * Return: a copy of the src.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= _strlen(src); i++)
		dest[i] = src[i];

	return (dest);
}
