#include "shell.h"

/**
 * _putchar - prints a char
 * @c: char
 *
 * Return: Always 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints strings
 * @s: pointer to the string
 *
 * Return: len of the string
 */

int _puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}

/**
 * _strlen - calculates the length of a string
 * @s: pointer to the string
 *
 * Return: length of the string
 */

int _strlen(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcmp - compares two strigs
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: 1 if true, else 0
 */

int _strcmp(char *s1, char *s2)
{
	int i, l1, l2;
	l1 = _strlen(s1);
	l2 = _strlen(s2);
	if (l1 != l2)
		return (0);
	for (i = 0; i < l1; i++)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

/**
 * _strtok - breaks a string into a sequence of zero or more
 * non-empty tokens.
 * @str: pointer to the string
 * @delim: pointer to the delimeter
 *
 * Return: pointer to the token
 */

char *_strtok(char *str, char *delim)
{
	static char *buffer;
	char *token, *b;
	const char *d;

	if (str != NULL)
		buffer = str;
	if (buffer[0] == '\0')
		return (NULL);

	token = buffer;
	for (b = buffer; *b != '\0'; b++)
	{
		for (d = delim; *d != '\0'; d++)
		{
			if (*b == *d)
			{
				*b = '\0';
			        buffer = ++b;
				return (token);
			}
		}
	}
	return (token);
}
