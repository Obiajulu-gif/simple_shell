#include "main.h"

/**
 * _strcmp - Entry point of the compare function
 * @s1: the first string to compare with the second
 * @s2: the second string for comparison
 * Return: the return type is an int, 0 if equal
 * negative if s1 is less than s2
 * positive is s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}

	if (*s1 == '\0' && *s2 != '\0')
		return (-1);
	else if (*s1 != '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}

/**
 * _strtok - Entry point
 * @str: the string to be tokenized
 * @delim: the delimiter
 * Return: a char
 */
char *_strtok(char *str, const char *delim)
{
	static char *nextToken;
	char *tokenStart;
	char *tokenEnd;

	if (str != NULL)
	{
		nextToken = str;
	}
	else if (nextToken == NULL)
	{
		return (NULL);
	}

	tokenStart = nextToken;
	tokenEnd = _strpbrk(nextToken, delim);

	if (tokenEnd != NULL)
	{
		*tokenEnd = '\0';
		nextToken = tokenEnd + 1;
	}
	else
	{
		nextToken = NULL;
	}

	return (tokenStart);
}


/**
 * *_strpbrk - searches a string for any of a set of bytes
 * @s: string to search
 * @accept: stringcontaining the bytes to look for
 *
 * Return: pointer to the byte in s that matches one of the bytes in accept
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, const char *accept)
{
	int i, j;

	for (i = 0; *s != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (*s == accept[j])
			{
				return (s);
			}
		}
		s++;
	}

	return (NULL);
}
