#include "main.h"

/**
 * is_valid_path - Check if a filename has a valid path prefix
 *
 * Description: This function checks if a filename has a valid path prefix,
 * such as "../", "./", or "/".
 *
 * @filename: The filename to check
 *
 * Return: 1 if the path is valid, 0 otherwise
 */
int is_valid_path(char *filename)
{
	size_t length = strlen(filename);

	if (length >= strlen("../"))
		if (strncmp(filename, "../", strlen("../")) == 0)
			return (1);
	if (length >= strlen("./"))
		if (strncmp(filename, "./", strlen("./")) == 0)
			return (1);
	if (length >= strlen("/"))
		if (strncmp(filename, "/", strlen("/")) == 0)
			return (1);
	return (0);
}

/**
 * filepath_creator - Create a file path by concatenating directory and filename
 *
 * Description: This function creates a file path by concatenating a directory
 * path and a filename.
 *
 * @file_path: Pointer to store the created file path
 * @array_of_tokens: The array of directory paths
 * @filename: The filename to append to the directory path
 * @token_index: The index of the directory path in the array
 *
 * Return: void
 */
void filepath_creator(char **file_path, char **array_of_tokens,
		char *filename, int token_index)
{
	malloc_char(file_path,
			(strlen(array_of_tokens[token_index]) + strlen(filename) + 2),
			"_which Error: malloc failed for file_path");
	strcpy(*file_path, array_of_tokens[token_index]);
	strcat(*file_path, "/");
	strcat(*file_path, filename);
	strcat(*file_path, "\0");
}

/**
 * which_shell - Find the full path of a command
 *
 * Description: This function searches for the full path of a command by
 * looking in the directories listed in the PATH environment variable.
 *
 * @filename: The name of the command
 *
 * Return: The full path of the command if found, or NULL if not found
 */
char *which_shell(char *filename)
{
	struct stat sb;
	char *path_var, *delimiter, *file_path;
	char **array_of_tokens;
	int token_index, file_path_exist;

	delimiter = ":";
	path_var = _getenv("PATH");
	if (path_var != NULL)
	{
		array_of_tokens = array_maker(path_var, delimiter);
		if (array_of_tokens != NULL)
		{
			for (token_index = 0; array_of_tokens[token_index]; token_index++)
			{
				filepath_creator(&file_path, array_of_tokens, filename, token_index);
				file_path_exist = stat(file_path, &sb);
				if (file_path_exist == 0)
				{
					free_which(&path_var, array_of_tokens);
					return (file_path);
				}
				free(file_path);
			}
			free_which(&path_var, array_of_tokens);
		}
		else
			free(path_var);
	}
	file_path_exist = stat(filename, &sb);
	if (file_path_exist == 0 && is_valid_path(filename))
		return (strdup(filename));
	return (NULL);
}
