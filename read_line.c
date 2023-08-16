#include "shell.h"

/**
 * read_input - read input from user.
 *
 * Return: a pointer
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = getline(&line, &len, stdin);

	if (nread <= 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
