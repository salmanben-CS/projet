#include "header_shell.h"

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
        char *args[2];
        args[0] = command;
        args[1] = NULL;

        execvp(command, args);

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
        }
      else 
      {
            executeCommand(command);
        }
    }
}
