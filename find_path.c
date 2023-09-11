#include "shell.h"
#include <unistd.h>

/**
  *custom_error- function to write input
  *@message: input
  ***/

void custom_error(const char *message)
{
	write(STDERR_FILENO, message, strlen(message));
	exit(EXIT_FAILURE);
}


/**
  *concat_strings - function to concatenate strings
  *@str1: first string
  *@str2: sec string
  *Return: concat str
 */
char *concat_strings(const char *str1, const char *str2)
{
	char *result = malloc(strlen(str1) + strlen(str2) + 2);

	if (!result)
		custom_error("Memory allocation failed.\n");
	_strcpy(result, str1);
	_strcat(result, "/");
	_strcat(result, str2);
	return (result);
}


/**
  *find_executable_path - function to find path
  *@args: arguements
  *@path_var: path variable
  *Return: PATH
  */

char *find_executable_path(char **args, char *path_var)
{
	struct stat s;
	char *path = NULL, *constructed_path = NULL, *token, *copy;
	int i = 0, counter = count_tokens(path_var), flag = 0;

	copy = _strdup(path_var);

	if (!copy)
		custom_error("Memory allocation failed.\n");
	token = _strtok(copy, ":=");

	while (token)
	{
		constructed_path = concat_strings(token, args[0]);

		if (stat(constructed_path, &s) == 0)
		{
			path = constructed_path;
			flag = 1;
			break;
		}
		if (i < counter - 2 && token[strlen(token) + 1] == ':')
		{
			if (stat(args[0], &s) == 0)
			{
				path = _strdup(args[0]);

				if (!path)
					custom_error("Memory allocation failed.\n");
				flag = 1;
				break;
			}
		} i++;
		token = _strtok(NULL, ":");
		free(constructed_path);
	}
	if (!flag)
		path = _strdup(args[0]);

	free(copy);
	return (path);
}

