#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/**
 * main - Simple shell program that handles command lines with arguments.
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
pid_t pid;
	while (1)
	{
		printf("$ ");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';
pid = fork();
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

	return (0);
}

