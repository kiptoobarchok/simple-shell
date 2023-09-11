#include "shell.h"

/**
  *main - entry point
  *Return: 0 sucess
  */

int main(void)
{
	char *path_var = NULL, *input_line = NULL, **args = NULL;
	int last_exit_status = 0;

	signal(SIGINT, SIG_IGN);

	path_var = get_environment_variable("PATH");

	if (path_var == NULL)
	{
		perror("Unable to retrieve PATH environment variable");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		display_prompt();
		input_line = read_input_line();

		if (*input_line != '\0')
		{
			args = split_input_line(input_line);
			if (args == NULL)
				continue;

			if (exec_builtin_command(args, input_line, &last_exit_status) == 0)
			{
				char *full_path = find_executable_path(args, path_var);

				execute_external_command(args, full_path);
				free(full_path);
			}
			free_args(args);
			free(input_line);
		}
	}
	free(path_var);
	path_var = NULL;
}

