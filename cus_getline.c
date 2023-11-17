#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * _getline - entry point
 * Return: a char
 */

#define BUFF_SIZE 1024

char *_getline()
{
	static char buffer[BUFF_SIZE];
	static size_t idx;
	static ssize_t bytesRead;
	size_t i;

	if (idx == bytesRead || bytesRead == 0)
	{
		bytesRead = read(STDIN_FILENO, buffer, BUFF_SIZE);

		if (bytesRead == -1 || bytesRead == 0)
		{
			return (NULL);
		}
		idx = 0;
	}

	for (i = idx; i < bytesRead; ++i)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			idx = i + 1;
			return (buffer);
		}
	}
	buffer[bytesRead] = '\0';
	idx = bytesRead;
	return (buffer);
}
