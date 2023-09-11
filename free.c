#include "shell.h"


/**
  *free_args- function to free memory
  *@args: arguement
  */


void free_args(char **args)
{
	int i;

	if (args == NULL)
		return;

	for (i = 0; args[i] != NULL; i++)

	{
		free(args[i]);
		args[i] = NULL;
	}

	free(args);
}

