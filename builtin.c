#include "shell.h"

/**
  * exec_builtin_command - function to execute command
  * @args: argument
  * @input_line: input entered
  * @last_exit_status: exit status
  *
  * Return: 1 for success, 0 for failure
  */

int exec_builtin_command(char **args, char *input_line, int *last_exit_status)
{
	if (_strcmp(args[0], "env") == 0)
	{
		display_environment_variables();

		free_args(args);

		return (1);
	}

	else if (_strcmp(args[0], "exit") == 0)
	{
		int exit_code = (args[1] != NULL) ? atoi(args[1]) : *last_exit_status;

		free_args(args);
		free(input_line);
		exit(exit_code);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		if (args[1] != NULL && change_directory(args[1]) == 0)
		{
			free_args(args);

			return (1);
		}
	}
	return (0);
}
