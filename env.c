#include "shell.h"

/**
 * _getenv - returns a pointer to the environmen variable value
 * @name: name of the variable
 *
 * Return: pointer to the value or NULL if not present
 */

char *_getenv(char *name)
{
	char *tmp;
	unsigned int i = 0;

	while (environ[i])
	{
		tmp = before_delim(environ[i], '=');
		if (_strcmp(tmp, name))
			return (after_delim(environ[i], '='));
		i++;
	}
	return (NULL);
}

/**
 *_envlen - gets the len of env
 *
 * Return: length of envs
 */

int _envlen(void)
{
	unsigned int i = 0;

	while (environ[i])
		i++;

	return (i);
}

/**
 * getenv_pos - returns the position env
 * @name: name of the env
 *
 * Return: position of the env, or -1
 */

int getenv_pos(char *name)
{
	char *tmp;
	unsigned int i = 0;

	while (environ[i])
	{
		tmp = before_delim(environ[i], '=');
		if (_strcmp(tmp, name))

			return (i);
		i++;
	}
	return (-1);
}

/**
 * concat_env - merge env parameter
 * @name: name of th env
 * @value: value of the env
 *
 * Return: pointer to env name-value pair
 */

char *concat_env(char *name, char *value)
{
	unsigned int i = 0, j = 0;
	char *path;

	path = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
	if (!path)
		exit(1);

	while (name[i] != '\0')
	{
	  path[j] = name[i];
	  j++;
	  i++;
	}
	path[j] = '=';
	i = 0;
	while (value[i] != '\0')
	{
	  j++;
	  path[j] = value[i];
	  i++;
	}
	j++;
	path[j] = '\0';

	return (path);
}

/**
 * _setenv - set env variable
 * @name: name of the variable
 * @value: value of the variable
 * @overwrite: overwrite the variable
 *
 * Return: - on success, -1 on error
 */

int _setenv(char *name, char *value, int overwrite)
{
	int i = 0;

	if (_getenv(name))
	{
	  i = getenv_pos(name);
	  if (overwrite && i)
	    environ[i] = concat_env(name, value);
	}
	else
	{
	  i = _envlen();
	  if (overwrite && i)
	    environ[i] = concat_env(name, value);
	  environ[i + 1] = NULL;
	}    
	return (i);
}
