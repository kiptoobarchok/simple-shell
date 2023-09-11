#include "shell.h"


/**
  *display_prompt- function to show prompt
  */

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

/**
  *is_whitespace - function to check for white space
  *@character: character
  *
  *Return: character
  */

int is_whitespace(char character)
{
	return (character == ' ' || character == '\t' ||
			character == '\n' || character == '\v' ||
			character == '\f' || character == '\r');
}

