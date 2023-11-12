#include "main.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * @env: NULL terminated arrays of strings
 * Return: returns an integer, 0- success, -1 failure
 */

int main(int ac __attribute__((unused)), char **av,
	 char **env __attribute__((unused)))
{
	while (1)
	{
		char *line = NULL;
		size_t size;
		ssize_t read;

		_printf("#cisfun$ ");
		read = getline(&line, &size, stdin);
		if (read == -1)
		{
			perror("GETERROR");
			return (1);
		}

		if (read > 1)
		{
			line[read - 1] = '\0';
			execCommand(line, av);
		}
		free(line);
	}
	return (0);
}

/**
 * execCommand - entry point, execute the commands
 * @line: the input
 * @av: the argument vector
 */
void execCommand(char *line, char **av)
{
	if (access(line, X_OK) == 0)
	{
		char **args = (char **)malloc(2 * sizeof(char *));

		if (args == NULL)
		{
			perror("Memory Allocation error");
			exit(1);
		}

		args[0] = line;
		args[1] = NULL;

		if  (fork() == 0)
		{
			execve(line, args, NULL);
			perror("Execution error");
			exit(1);
		}
		else
			wait(NULL);

		free(args);
	}
	else
		_printf("%s: No such file or directory\n", av[0]);
}
