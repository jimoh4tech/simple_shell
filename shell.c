#include "shell.h"

/**
 * check_cmd - checks of the user enters a valid command
 * @s: pointer to the user's command
 *
 * Return: 1 if valid, else 0
 */

int check_cmd(char *s)
{
	if (_strcmp(s, "ls") || _strcmp(s, "exit") || _strcmp(s, "env") ||
	    _strcmp(s, "/bin/ls") || _strcmp(s, "cd") || _strcmp(s, "setenv"))
	{
		return (1);
	}
	return (0);
}

/**
 * prompt - prints the prompt message
 *
 * Return: pointer to the string
 */

char *prompt(char *arg)
{
  char *line= NULL, *cmd;
	size_t len = 0, input = 0;

	do
	{
		_puts("$ ");
		input = _getline(&line, &len, stdin);
		cmd = first_token(line);
		if (feof(stdin))
		{
			_putchar('\n');
			exit(0);
		}
		if (!(check_cmd(cmd)) && input > 0)
		{
			_puts(arg);
			_puts(": 1: ");
			_puts(cmd);
			_puts(": not found\n");
			input = 0;
		}
	} while (input <= 1);
	return (stripe_newline(line));
}


/**
 * main - simple shell program
 *
 * Return: 1 on error, else 0;
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *line, *av[10], *token;
	size_t i = 0;

	while (!feof(stdin))
        {
		line = prompt(argv[0]);
	        
		i = 0;
		token = strtok(line, " ");
		while (token)
		{
		  av[i] = token;
		  token = strtok(NULL, " ");
		  i++;
		}
		av[i] = NULL;

		parser(av, argv[0]);
		/* free_grid(av); */
	}
	
	return (0);
}
