#include "main.h"

/**
 * get_env - Retrieves the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Description: This function searches for the specified environment variable
 * name and returns its corresponding value.
 *
 * Return: On success, returns a pointer to the value of the environment variable.
 *         If the variable is not found, returns NULL.
 */
char *get_env(const char *name)
{
    unsigned int env_index, envar_length;
    char *env_var;
    char *env_var_cpy;

    for (env_index = 0; __environ[env_index]; env_index++)
    {
        if (strncmp(__environ[env_index], name, strlen(name)) == 0)
        {
            envar_length = strlen(__environ[env_index]) - (strlen(name));
            env_var = malloc(sizeof(char) * envar_length);
            if (env_var == NULL)
            {
                perror("get_env() Error: env_var malloc failed");
                return (NULL);
            }
            malloc_char(&env_var_cpy, strlen(__environ[env_index]) + 1,
                        "get_env() malloc error");
            strcpy(env_var_cpy, __environ[env_index]);
            strncpy(env_var, env_var_cpy += (strlen(name) + 1), envar_length);
            free(env_var_cpy -= (strlen(name) + 1));
            return (env_var);
        }
    }
    return (NULL);
}
