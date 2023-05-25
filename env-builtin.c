#include "main.h"

/**
 * env_builtin - Print environment variables
 *
 * @array_of_tokens: Command array
 *
 * Return: 0 for failure, 1 for success
 */
int env_builtin(__attribute((unused)) char **array_of_tokens)
{
	int environment_index;

	for (environment_index = 0; __environ[environment_index]; environment_index++)
	{
		write(STDOUT_FILENO, __environ[environment_index],
				strlen(__environ[environment_index]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}
	return (environment_index);
}
