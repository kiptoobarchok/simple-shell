#include "shell.h"

/**
 * _strncmp - compare two strings up to a maximum of n characters.
 * @str1: the first string.
 * @str2: the second string.
 * @n: the maximum number of characters to compare.
 *
 * Return: an integer less than, equal to, or greater than zero if the first n
 * characters of @str1 are found, respectively, to be less than, to match,
 * or be greater than the first n characters of @str2.
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
	{
		/*If n is 0, no characters to compare, so return equal*/
		return (0);
	}

	while (*str1 != '\0' && *str2 != '\0' && n > 1)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}

		str1++;
		str2++;
		n--;
	}

	/*Compare the last characters */
	return ((*str1 - *str2));
}

/**
 * _strtok - splits string.
 * @str: the input string.
 * @delim: the string containing delimiter characters.
 *
 * Return: a pointer to the next token found in the input string, or NULL.
 */

char *_strtok(char *str, const char *delim)
{
	static char *s; /* Local buffer to track the progress */
	int i;          /* Delimiter index */
	char *token;

	if (str != NULL)
		s = str;

	else if (*s == '\0')
	{
		return (NULL);
	}
	while (*s != '\0')
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*s == delim[i])
			break;
		}
		if (delim[i] == '\0')
			break;
		s++;
	}
	token = s;

	while (*s != '\0')
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
		if (*s == delim[i])
		{
			*s = '\0';
			s++;
			return (token);
		}
		}
		s++;
	}
	s = "\0";
	return (token);
}

/**
 * _strncpy - copy up to n characters from source string to dest buffer.
 * @dest: the destination buffer where the copied string will be stored.
 * @src: the source string to be copied.
 * @n: the maximum number of characters to copy.
 *
 * Return: a pointer to the destination buffer.
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
  *_puts- function to write characters
  *@str: string characters
  */

void _puts(const char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}

