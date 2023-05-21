#include "header_shell.h"
/**
 * executeCommand - fnc desc
 * @command:parameter
 * Return:void
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

execve(command, args, NULL);

printf("Command not found: %s\n", command);
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, NULL, 0);
}
}

