#include "shell.h"
/**
 * main - main function.
 *
 * Return: 0.
 */
char *line_ptr = NULL;
int main(void)
{
	char **str, *s;
	
	while(true)
	{
		prompt();
		s = get_line();
		str = parser(s, " \t\n");
		if (built_in(*str) == true)
		{
			execute_b(str);
		}
		if (built_in(*str) == false)
		{
			execute_e(*str, str, environ);
		}
		else
		{
			perror(" ");
			if (line_ptr)
				free(line_ptr);
			exit(EXIT_FAILURE);
		}
		if (line_ptr)
			free(line_ptr);
	}
	return (0);
}
char *get_line(void)
{
	size_t len = 0;
	FILE *stream = stdin;
	ssize_t n_char = getline(&line_ptr, &len, stream);
	
	if (n_char == -1)
	{
		if (feof(stream))
		{
			if (isatty(fileno(stream)))
			{
				write(1, "\n", 1);
			}
			exit(0);
		}
		perror("");
		exit(1);
	}
	line_ptr[n_char] = '\0';
	return (line_ptr);
}
/**
 * execute_b - executes built-in function.
 * @command: array to check from.
 */
void execute_b(char **command)
{
	if (strstr(*command, "exit") == *command)
	{
		if (*(command + 1))
			exitF(_atoi(*(command + 1)));
		else
			exitF(0);
	}
	if (strstr(*command, "env") == *command)
	{
		env();
	}
	/*if (strstr(*command, "cd") == *command)
	{
		if (cd_command(command) == -1)
		{
			perror(" ");
		}
	}*/
}
/**
 * execute_e - execute the command line
 * @cmd: the command line
 * @argv: argument vector.
 * @envp: the environment argument.
 */
void execute_e(char *cmd, char *argv[], char *envp[])
{
	int status;
	pid_t child;
	char *path;path = checker(cmd);
	
	if (path == NULL)
	{
		return;
	}
	child = fork();
	if (child == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		execute(path, argv, envp);
	}
	else
	{
		wait(&status);
	}
	if ((path != NULL) && (path != cmd))
	{
		free(path);
		path  = NULL;
	}
}
