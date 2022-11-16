#include "shell.h"

/**
 * execute - runs commands
 * @argv: args vector
 * @filename: name of the file
 */

void execute(char **argv, char *filename)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror(filename);
		exit(1);
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror(filename);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}

}

/**
 * parser - helps to parse commands
 * @argv: pointer to the string
 * @filename: filename
 */

void parser(char **argv, char *filename)
{
	if (_strcmp(argv[0], "ls"))
	{
		argv[0] = "/bin/ls";
		execute(argv, filename);
	}
	else if (_strcmp(argv[0], "exit"))
		__exit(argv[1]);
	else if (_strcmp(argv[0], "env"))
		printenv();
	else if (_strcmp(argv[0], "cd"))
		_chdir(argv[1]);
	else if (_strcmp(argv[0], "setenv"))
		_setenv(argv[1], argv[2], 0);
	else
	{
		execute(argv, filename);
	}
}

/**
 * tokenize - splits string into array of strings
 * using the appropriate delimiter
 * @s: pointer to the string
 * @delim: the delimeter
 *
 * Return: pointer to the array token
 */

char **tokenize(char *s, char delim)
{
	int cur = 0, i = 0, idx = 0;
	char **tokens, *token;

	tokens = malloc(sizeof(char *) * 10);
	if (!tokens)
		exit(1);

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		while (s[i] != delim && s[i] != '\0')
		{
			token[cur] = s[i];
			cur++;
			i++;
		}
		token[cur] = '\0';
		cur = 0;
		tokens[idx] = token;
		idx++;
		token = NULL;
	}
	tokens[idx] = NULL;
	return (tokens);
}

/**
 * free_grid - frees allocated memory location
 * @av: poimter to the array to be freed
 */

void free_grid(char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

/**
 * first_token - returns the string before space
 * @s: point to the commads string
 *
 * Return: pointer to the string before space
 */

char *first_token(char *s)
{
	unsigned int i = 0;
	char *token;

	token  = malloc(sizeof(char) * 10);
	if (!token)
		exit(1);

	for (i = 0; s[i] != '\0' && s[i] != ' '; i++)
		token[i] = s[i];

	token[i] = '\0';
	return (token);
}
