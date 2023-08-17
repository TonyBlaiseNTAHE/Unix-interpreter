#include "shell.h"

/**
 * prompt - display a prompt.
 *
 */
void prompt(void)
{
	int status = 1;

	status = isatty(STDIN_FILENO);
	if (status == 1)
	{
		printf("$ ");
	}
}
