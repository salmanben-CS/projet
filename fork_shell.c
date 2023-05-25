#include "main.h"

/**
 * fork_shell - Execute a command by forking a child process
 *
 * Description: This function forks a child process and executes a command
 * using the `execve` system call. It takes the command and an array of tokens
 * as arguments.
 *
 * @command: String command
 * @array_of_tokens: Array of tokens
 *
 * Return: 0 on success, -1 on failure
 */
int fork_shell(char *command, char **array_of_tokens)
{
	pid_t pid;
	int status, is_execve_error;

	pid = fork();
	if (pid == -1)
	{
		perror("fork_shell() Error: fork child unable to create");
		return (-1);
	}
	if (pid == 0)
	{
		is_execve_error = execve(command, array_of_tokens, __environ);
		if (is_execve_error == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		free(command);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}
