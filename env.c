#include "shell.h"
/**
 * env - print the enivornment.
 *
 * Return: nothing.
 */
void env(void)
{
	while (*environ)
	{
		printf("%s\n", *environ);
		environ++;
	}
}
