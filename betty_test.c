#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(void)
{
    char *line;
    char *args[64];
    int status;

    while (1)
    {
        printf("$ ");

        line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        if (!line)
	{
            perror("malloc error");
            exit(EXIT_FAILURE);
        }

        if (!fgets(line, BUFFER_SIZE, stdin)) 
	{
            free(line);
            break;
        }

        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Tokenize the line into arguments
        char *token;
        token = strtok(line, " ");
        int i = 0;
        while (token != NULL) 
	{
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // Fork a child process
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork error");
            exit(EXIT_FAILURE);
        }
	    else if (pid == 0) 
	{
            // Child process
            if (execvp(args[0], args) == -1) 
	    {
                perror("execvp error");
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        } 
	    else 
	    {
            // Parent process
            waitpid(pid, &status, 0);
        }

        free(line);
    }

    return 0;
}
