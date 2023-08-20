#include "shell.h"
/**
 * built_in - check if it is a built-in or not.
 * @cmd: the command.
 * Return: the command to check.
 */
bool built_in(char *cmd)
{
	int i;
	const char *command[3] = {"exit", "env", "cd"};

	for (i = 0; i < 3; i++)
	{
		if (strstr(cmd, command[i]) == cmd)
		{
			return (true);
		}
	}
	return (false);
}
