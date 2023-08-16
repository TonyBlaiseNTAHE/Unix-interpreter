#ifndef _SHELL_H
#define _SHELL_H
#define MAX_ARGS 64
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
extern char **environ;
char *_which(char *fullpath, const char *command, const char *paths);
void prompt(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *read_input(void);
char **parse_input(char *input);
int execute(char **args);
int handle_builtin(char **args);
void handle_error(const char *msg);
char *_getenv(const char *name);
void env(void);
char *_strncpy(char *dest, char *scr, int n);
#endif
