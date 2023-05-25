#include "main.h"

/**
 * is_builtin - Check if a command is a built-in command
 *
 * Description: This function checks if the given command is a built-in command
 *              by comparing it with the list of built-in commands.
 *
 * @array_of_tokens: Command array
 *
 * Return: 1 if the command is a built-in command, 0 otherwise
 */
int is_builtin(char **array_of_tokens)
{
	int builtin_index;
	const struct builtin_command builtins[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL;
			builtin_index++)
	{
		if (strcmp(array_of_tokens[0],
					builtins[builtin_index].name) == 0)
			return (1);
	}
	return (0);
}

/**
 * builtin_handler - Execute a built-in command
 *
 * Description: This function executes the appropriate built-in command
 *              based on the given command.
 *
 * @array_of_tokens: Command array
 *
 * Return: 1 if the command was a built-in command and executed successfully,
 *         0 otherwise
 */
int builtin_handler(char **array_of_tokens)
{
	int builtin_index;
	const struct builtin_command builtins[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL;
			builtin_index++)
	{
		if (strcmp(array_of_tokens[0],
					builtins[builtin_index].name) == 0)
			return (builtins[builtin_index].function(array_of_tokens));
	}
	return (0);
}
