#include "shell.h"

/**
 * _strcat - concatenates two strings.
 * @dest: the destination string.
 * @src: the source string to be appended to the destination.
 *
 * Return: pointer to the resulting string @dest.
 */

char *_strcat(char *dest, const char *src)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; ++i)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings.
 * @str1: the first string to be compared.
 * @str2: the second string to be compared.
 *
 * Return: an integer less than, equal to, or greater than zero if @str1 is
 * found, respectively, to be less than, to match, or be greater than @str2.
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return ((int)(*str1) - (int)(*str2));
}

/**
 * _strcpy - copies a string.
 * @dst: the destination buffer.
 * @src: the source string to be copied.
 *
 * Return: a pointer to the destination string @dst.
 */

char *_strcpy(char *dst, const char *src)
{
	size_t a = 0;

	while (src[a] != '\0')
	{
		dst[a] = src[a];
		a++;
	}

	dst[a] = '\0';

	return (dst);
}

/**
 * _strdup - duplicates a string.
 * @str: the string to be duplicated.
 *
 * Return: a pointer to newly allocated memory containing a duplicate of @str.
 * NULL if insufficient memory is available or @str is NULL.
 */

char *_strdup(const char *str)
{
	char *new_str;
	size_t len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));

	if (!new_str)
	{
		return (NULL);
	}

	_strncpy(new_str, str, len + 1);

	return (new_str);
}

/**
 * _strlen - calculates the length of a string.
 * @str: the input string.
 *
 * Return: Tte length of the string.
 */

size_t _strlen(const char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}
