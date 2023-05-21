#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
/**
 * main - Handle the PATH
 * Return:0
 */
int main(void)
{
char buffer[BUFFER_SIZE];
char *args[64];
int status = 1;
int length = strlen(buffer);
char *token = strtok(buffer, " ");
int i = 0;
while (status)
{
printf("$ ");
fgets(buffer, BUFFER_SIZE, stdin);

if (buffer[length - 1] == '\n')
{
buffer[length - 1] = '\0';
}

while (token != NULL)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;

if (fork() == 0)
{
execvp(args[0], args);
exit(EXIT_FAILURE);
}
else
{
wait(&status);
}
}

return (0);
}

