#include "shell.h"
#include <unistd.h>

/**
  *execute_external_command - function to execute cmd
  *@args: arguement
  *@full_path: PATH
  *
  *Return: exit status
  */


int execute_external_command(char **args, char *full_path)
{
	pid_t pid;
	int res;
	int status = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		res = execve(full_path, args, environ);

		if (res == -1)
		{
			perror(args[0]);
			exit(127);
		}
	}

	wait(&status);

	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
	}

	return (status);
}

