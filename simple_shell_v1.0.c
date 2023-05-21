#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100
/**
 * main - Write a UNIX command line interpreter.
 * Return:0
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
			char *args[2];

			args[0] = command;

args[1] = NULL;

			execve(command, args, NULL);


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

