#include "shell.h"

/**
 * parse_input - parsing input.
 * @input: input from user.
 * Return: pointer to a pointer.
 */
char **parse_input(char *input)
{
	char **args;
	char *tokens;
	int i = 0;

	args = malloc(MAX_ARGS * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	tokens = strtok(input, " \t\n\r");
	while (tokens != NULL && i < MAX_ARGS - 1)
	{
		args[i] = tokens;
		tokens = strtok(NULL, " \t\n\r");
		i++;
	}
	args[i] = NULL;
	return (args);
}
