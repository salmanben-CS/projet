#include "main.h"

/**
 * getline_shell - reads a line of input from the shell
 *
 * Description: Reads a line of input from the shell prompt
 *
 * @input: pointer to store the input line
 * @number_of_malloc_bytes_allocated: pointer to track the allocated memory
 * @status: the exit status
 *
 * Return: -1 on failure, number of characters read on success
 */
ssize_t getline_shell(char **input, size_t *number_of_malloc_bytes_allocated, int status)
{
	ssize_t number_of_characters_read;

	prompt();
	number_of_characters_read = getline(input, number_of_malloc_bytes_allocated, stdin);
	if (number_of_characters_read == -1)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (number_of_characters_read);
}
