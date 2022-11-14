#include "shell.h"

/**
 * __exit - exits code with status
 * @status: status of code
 */

void __exit(char *status)
{
	if (status)
		exit(atoi(status));
	else
		exit(0);
}

/**
 * printenv - prints environmental variables
 */

void printenv(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}

/**
 * _chdir - changes the current directory
 * @path: path to the new directory
 */

void _chdir(char *path)
{
	if (path)
	{
		if (_strcmp(path, "-"))
			path = "/root";
		
		if (chdir(path) != 0)
			perror("Error");
	}
	else
		chdir("/home");
}
