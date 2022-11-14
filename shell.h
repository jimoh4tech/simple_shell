#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

int _puts(char *s);
int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, char *delim);
char *trim(char *s);
char *stripe_newline(char *s);
char *prompt(char *arg);
int check_cmd(char *s);
char *first_token(char *s);
void execute(char **argv, char *filename);
void parser(char **argv, char *filename);
void __exit(char *status);
void printenv(void);
size_t _getline(char **lineptr, size_t *n, FILE *stream);
void _chdir(char *path);
char **tokenize(char *s, char delim);
void free_grid(char **av);
char *before_delim(char *s, char c);
char *after_delim(char *s, char c);
char *_getenv(char *name);
int _envlen(void);
int getenv_pos(char *name);
char *concat_env(char *name, char *value);
int _setenv(char *name, char *value, int overwrite);

#endif /* SHELL_H */
