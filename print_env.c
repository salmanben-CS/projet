#include "main.h"

/**
 * print_env - Print the environment variables
 *
 * Description: This function prints the current environment variables.
 *
 * Return: 0 on success
 */
int print_env(void)
{
	unsigned int environ_index;

	for (environ_index = 0; __environ[environ_index]; environ_index++)
		printf("%s\n", __environ[environ_index]);
	return (0);
}
