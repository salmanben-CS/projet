#ifndef MAIN_H
#define MAIN_H
#define EXIT_CODE 1080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * struct builtin_command - Structure for built-in commands
 * @name: The name of the command
 * @function: The function pointer to the command's implementation
 *
 * Description: This structure represents a built-in command and
 * associates its name with its corresponding function.
 */
struct builtin_command
{
    char *name;
    int (*function)(char **array_of_tokens);
};

void prompt(void);
void sigint_handler(int signal);
ssize_t _getline(char **input,
                 size_t *number_of_malloc_bytes_allocated, int status);
char **array_maker(char *input, char *delimiter);
int _fork(char *command, char **array_of_tokens);
char *_which(char *filename);
int _print_env(void);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *malloc_char(char **string, size_t size_of_malloc, char *error_message);
