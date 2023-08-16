#include "shell.h"

/**
 * main - main function.
 *
 * Return: 0.
 */
int main(void)
{
	char *input;
	char **args;
	int res;

	while (1)
	{
		prompt();
		input = read_input();
		if (input == NULL)
		{
			printf("Goodbye!\n");
			exit(EXIT_SUCCESS);
		}
		args = parse_input(input);
		if (args[0] != NULL)
		{
			res = handle_builtin(args);
			if (res == -1)
			{
				res = execute(args);
			}
		}
		free(input);
		free(args);
	}
	return (0);
}
