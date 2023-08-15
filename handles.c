#include "shell.h"

/**
 * handle_builtin - handles builtin function.
 * @args: argument.
 * Return: -1 if no built found.
 */
int handle_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	return (-1);
}
void handle_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
