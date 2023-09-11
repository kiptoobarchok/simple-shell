#include "shell.h"

/**
 * _getenv - gets the value of an environment variable.
 * @name: the name of the environment variable to find.
 *
 * Return: a pointer to the value of the environment variable.
 * If the variable is not found, returns NULL.
 */

char *_getenv(const char *name)
{
	size_t name_len = _strlen(name);
	char *value;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			value = &environ[i][name_len + 1];
			return (value);
		}
	}

	return (NULL);
}
