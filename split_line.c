#include "shell.h"

/**
  *split_input_line - function to split lines to tokens
  *@input_line: line to be tokenized
  *
  *Return: tokens
  */

char **split_input_line(char *input_line)
{
	int i = 0;
	char *token, *delimiter = " \n";
	char **result;

	int token_count = count_tokens(input_line);

	if (token_count == 0)
	{
		free(input_line);
		return (NULL);
	}

	result = (char **)malloc((token_count + 1) * sizeof(char *));

	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = _strtok(input_line, delimiter);

	while (token != NULL)
	{
		result[i] = _strdup(token);

		if (result[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = _strtok(NULL, delimiter);
		i++;
	}
	result[i] = NULL;

	return (result);
}

