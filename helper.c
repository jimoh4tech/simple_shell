#include "shell.h"

/**
 * stripe_newline - removes newline character
 * @s:pointer to the string
 * Return: pointer to the stripped string
 */

char *stripe_newline(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)

		if (s[i] == '\n')
			s[i] = '\0';
	return (s);
}


/**
 * trim  - removes all spaces characters in a string
 * @s:pointer to the string
 *
 * Return: the trimmed string
 */

char *trim(char *s)
{
	size_t l = _strlen(s);

	while (isspace(s[l - 1]))
		--l;
	while (*s && isspace(*s))
	{
		++s;
		--l;
	}
	return (strndup(s, l));

}


/**
 * _getline - reads a new line
 * @lineptr: pointer to the string pointer
 * @n: pointer to the size
 * @stream: pointer inputs streams
 *
 * Return: length of the string
 */

size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char line[256];

	char *ptr;

	size_t len;

	if (lineptr == NULL || ferror(stream) || feof(stream))
		return (-1);

	fgets(line, 256, stream);

	ptr = strchr(line, '\n');

	if (ptr)
		*ptr = '\0';

	len = _strlen(line);

	if ((len + 1) < 256)
	{
		ptr = realloc(*lineptr, 256);
		if (ptr == NULL)
			return (-1);
		*lineptr = ptr;
		*n = 256;
	}
	strcpy(*lineptr, line);
	return (len);
}


/**
 * before_delim - gets the value of string before a delimiter
 * @s: pointer to the string
 * @c: the delimeter to stop at
 *
 * Return: pointer to the string
 */

char *before_delim(char *s, char c)
{
	unsigned int i = 0;
	char *value;

	value = malloc(sizeof(char) * _strlen(s));
	if (!value)
		exit(1);

	while (s[i] != '\0' && s[i] != c)
	{
		value[i] = s[i];
		i++;
	}
	value[i] = '\0';

	return (value);
}

/**
 * after_delim - gets the pointer to the string after delimiter
 * @s: pointer to the string
 * @c: the delimiter character
 *
 * Return: pointer to the string
 */

char *after_delim(char *s, char c)
{
	unsigned int i = 0, j = 0;
	char *value;

	value = malloc(sizeof(char) * _strlen(s));
	if (!value)
		exit(1);

	while (s[i] != '\0' && s[i] != c)
		i++;

	while (s[i] != '\0')
	{
		++i;
		value[j] = s[i];
		j++;
	}
	value[j] = '\0';

	return (value);
}
