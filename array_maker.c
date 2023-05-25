#include "main.h"

/**
 * number_of_tokens - function that returns the number of tokens in a string
 *
 * Description: This function counts the number of tokens in a string
 *
 * @input: Input string
 * @delimiter: Delimiter string
 *
 * Return: The number of tokens if successful, -1 on failure
 */
size_t number_of_tokens(char *input, char *delimiter)
{
	char *token;
	size_t token_count;

	token_count = 0;
	token = strtok(input, delimiter);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delimiter);
	}
	return (token_count);
}

/**
 * array_maker - function that creates a NULL terminated array of tokens
 *
 * Description: This function creates a NULL terminated array of tokens
 * from a string delimited by a specified delimiter
 *
 * @input: Input string
 * @delimiter: Delimiter string
 *
 * Return: The array of tokens on success, NULL on failure
 */
char **array_maker(char *input, char *delimiter)
{
	char *input_cpy, *token;
	char **array_of_tokens;
	size_t token_count, token_index, token_free_index;

	array_of_tokens = NULL;
	malloc_char(&input_cpy, strlen(input) + 1,
			"array_maker() Error: input_cpy malloc failure");
	strcpy(input_cpy, input);
	token_count = number_of_tokens(input_cpy, delimiter);
	array_of_tokens = malloc_array(array_of_tokens, token_count + 1,
			"array_maker() Error: array_of_tokens malloc failure");
	strcpy(input_cpy, input);
	token = strtok(input_cpy, delimiter);
	for (token_index = 0; token_index < token_count; token_index++)
	{
		array_of_tokens[token_index] = (char *) malloc(sizeof(char) *
				strlen(token) + 1);
		if (array_of_tokens[token_index] == NULL)
		{
			for (token_free_index = 0;
					token_free_index < token_index;
					token_free_index++)
				free(array_of_tokens[token_free_index]);
			free(input_cpy);
			free(array_of_tokens);
			perror("array_maker() Error: array_of_tokens malloc failure");
			return (NULL);
		}
		strcpy(array_of_tokens[token_index], token);
		token = strtok(NULL, delimiter);
	}
	free(input_cpy);
	array_of_tokens[token_count] = NULL;
	return (array_of_tokens);
}
