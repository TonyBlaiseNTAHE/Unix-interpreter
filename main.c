#include "shell.h"

int main(void) {
    char *read;
    char **argv = NULL;
    char *envp[] = {NULL};
    int status;
    pid_t child;
    int i;

    while (1) {
        prompt();
        read = read_input();
        if (read == NULL) {
            perror("read error");
            return 1;
        }

        /* Free the memory allocated for previous argv */
        if (argv != NULL) {
            for (i = 0; argv[i] != NULL; i++) {
                free(argv[i]);
            }
            free(argv);
        }

        argv = parsing(read);
        if (argv == NULL) {
            perror("parsing error");
            return 1;
        }

        child = fork();
        if (child == -1) {
            perror("fork error");
        } else if (child == 0) {
            execve(argv[0], argv, envp);
            /* Handle execve failure */
            perror("execve error");
            exit(1);
        } else {
            wait(&status);
        }

        free(read); /* Free the memory allocated by read_input */

       /* Free memory allocated by parsing function*/
        for (i = 0; argv[i] != NULL; i++) {
            free(argv[i]);
        }
        free(argv);
    }

    return 0;
}
