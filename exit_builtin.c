#include "main.h"

/**
 * exit_builtin - Built-in exit
 *
 * @array_of_tokens: Command array
 *
 * Return: 0 if failure, 1 if success
 */
int exit_builtin(char **array_of_tokens)
{
	if (array_of_tokens[1] != NULL)
		exit(atoi(array_of_tokens[1]));
	else
		return (EXIT_CODE);
}
