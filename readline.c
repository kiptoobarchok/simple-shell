#include "shell.h"

/**
  *read_input_line - function read a line input
  *
  *Return: line
  */


char *read_input_line(void)
{
	size_t buffer_size = 0;
	char *buffer = NULL;
	ssize_t line_length = getline(&buffer, &buffer_size, stdin);

	int i = line_length - 1;

	if (line_length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}

		free(buffer);
		exit(EXIT_SUCCESS);
	}

	while (i > 0 && is_whitespace(buffer[i]))
	{
		buffer[i] = '\0';
		i--;
	}

	return (buffer);
}

