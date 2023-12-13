#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void display_prompt() {
    printf("#cisfun$ ");
}

int execute_command(char *command) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execve(command, NULL, NULL) == -1) {
            perror("./shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        display_prompt();

        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle end of file (Ctrl+D)
            printf("\n");
            break;
        }

        // Remove the newline character at the end
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strlen(input) > 0) {
            if (access(input, X_OK) == 0) {
                execute_command(input);
            } else {
                fprintf(stderr, "./shell: No such file or directory\n");
            }
        }
    }

    return 0;
}

