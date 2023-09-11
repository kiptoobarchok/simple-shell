#include "shell.h"

/**
  *change_directory - function to change dir
  *@new_dir: new directory
  *
  *Return: 0 success
  */

int change_directory(char *new_dir)
{
	char *home_dir = get_environment_variable("HOME");
	char *prev_dir = get_environment_variable("PWD");
	char current_dir[MAX_INPUT_LENGTH];

	if (new_dir == NULL || _strcmp(new_dir, "~") == 0)
	{
		new_dir = home_dir;
	} else if (_strcmp(new_dir, "-") == 0)
	{
		if (prev_dir != NULL)
		{
			new_dir = prev_dir;
			printf("%s\n", new_dir);
		}
		else
		{
			fprintf(stderr, "cd: no previous directory stored\n");
			return (1);
		}
	}
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("cd");
		return (1);
	}

	if (chdir(new_dir) != 0)
	{
		perror("cd");
		return (1);
	}

	if (setenv("PWD", current_dir, 1) != 0)
	{
		perror("setenv");
		return (1);
	}
	return (0);
}
