#include "main.h"

/**
 * prompt_shell - short description
 *
 * Description: long description
 *
 * Return: -1 on failure greater than 0 on success
 */
void prompt_shell(void)
{
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", strlen("$ "));
}
