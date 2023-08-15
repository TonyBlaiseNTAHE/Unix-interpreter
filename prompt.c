#include "shell.h"

/**
 * prompt - print prompt.
 */
void prompt(void)
{
	int signal = 1;

	signal = isatty(0);
	if (signal == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}
