#include "main.h"

/**
 * setenv - Set an environment variable
 *
 * Description: The setenv() function adds the variable name to the
 * environment with the value value, if name does not already exist.
 * If name does exist in the environment, then its value is changed
 * to value if overwrite is nonzero; if overwrite is zero, then the
 * value of name is not changed (and setenv() returns a success status).
 * This function makes copies of the strings pointed to by name and
 * value (by contrast with putenv(3)). The unsetenv() function deletes
 * the variable name from the environment. If name does not exist in the
 * environment, then the function succeeds, and the environment is unchanged.
 *
 * @name: name string
 * @value: value string
 * @overwrite: overwrite integer
 *
 * Return: -1 on failure, 0 on success
 */
int setenv(const char *name, const char *value, int overwrite)
{
	unsigned int envar_length;
	char *env_var;

	envar_length = strlen(name) + strlen(value) + 2;
	create_envar(&env_var, envar_length, name, value);
	_env_set_exists(env_var, envar_length, name, overwrite);
	if (_env_name_exists(name) != -1)
		_env_set_exists(env_var, envar_length, name, overwrite);
	else
		env_does_not_exists(env_var, envar_length, _env_length());
	return (0);
}
