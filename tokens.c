#include "shell.h"

/**
 * count_tokens - function to count tokens in a string
 * @string: the input string
 *
 * Return: Number of tokens
 */

int count_tokens(char *string)
{
	int i;
	int flag = 1, counter = 0;

	for (i = 0; string[i]; i++)
	{
		if (string[i] != ':' && flag == 1)
		{
			counter += 1;
			flag = 0;
		}

		if (string[i + 1] == ':')
			flag = 1;
	}

	return (counter);
}

