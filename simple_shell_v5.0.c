#include "header_shell.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/**
 * executeCommand - Execute the given command
 * @command: The command to execute
 * Return: void
 */
void executeCommand(char *command) 
{
    pid_t pid = fork();

    if (pid < 0) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        char *arguments[MAX_ARGUMENTS];
        char *token;
        int arg_count = 0;

        token = strtok(command, " ");
        while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
        {
            arguments[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        arguments[arg_count] = NULL;

        execvp(arguments[0], arguments);

        printf("Command not found: %s\n", command);
        exit(EXIT_FAILURE);
    } 
    else
    {
        waitpid(pid, NULL, 0);
    }
}

/**
 * runShell - Run the simple shell program
 * Return: void
 */
void runShell(void)
{
    char command[MAX_COMMAND_LENGTH];
    bool running = true;

    while (running)
    {
        displayPrompt();

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
        {
            running = false;
        } else {
            executeCommand(command);
        }
    }
}
