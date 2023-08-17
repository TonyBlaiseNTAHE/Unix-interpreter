#include "shell.h"

/**
 * read_input - reads input from user.
 * 
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	int get;

	get = getline(&line, &len, stdin);
	if (get == -1)
	{
		perror("getline error");
	}
	return(line);
}
/**
 * parsing - divide input form user into tokens.
 * @args: the argument passed to the program.
 * Return: pointer to array of token.
 */
char **parsing(char *args) {
    char *token;
    char **array = NULL;
    int i = 0;

    if (args == NULL) {
        perror("input");
        return NULL;
    }

    /* Allocate memory for the initial array*/
    array = (char **)malloc(MAX * sizeof(char *));
    if (array == NULL) {
        perror("malloc error");
        return NULL;
    }

    token = strtok(args, DELM);
    while (token != NULL && i < MAX) {
        array[i] = strdup(token);
        if (array[i] == NULL) {
            perror("strdup error");
            return NULL;
        }
        token = strtok(NULL, DELM);
        i++;
    }
    array[i] = NULL; /* Add a NULL terminator at the end*/

    return array;
}
