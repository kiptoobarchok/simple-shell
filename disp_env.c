#include "shell.h"

/**
  *display_environment_variables - function to display env
  */

void display_environment_variables(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_puts(*env);
		env++;
	}
}

/**
  *get_environment_variable - function to get PATH
  *@var: env variable
  *
  *Return: env
  */

char *get_environment_variable(const char *var)
{
	return (_getenv(var));
}

