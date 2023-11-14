#include "main.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * @env: NULL terminated arrays of strings
 * Return: returns an integer, 0- success, -1 failure
 */

int main(int ac , char **av,
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
			execCommand(line, av, ac);
		}
		free(line);
		handle_command_with_args(av, ac);
	}
	return (0);
}

/**
 * execCommand - entry point, execute the commands
 * @line: the input
 * @av: the argument vector
 */
void execCommand(char *line, char **av, int ac)
{
	char *token;
	char **args = (char **)malloc(MAX_ARGS * sizeof(char *));
	int i = 0;
	int j = 0;

	if (args == NULL)
	{
		perror("Memory Allocation error");
		exit(1);
	}

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	if (access(args[0], X_OK) == 0)
	{
		if (fork() == 0)
		{
			execve(args[0], args, NULL);
			perror("Execution error");
			exit(1);
		}
		else
			wait(NULL);
	}
	else
	{
		for (j = 0; args[j] != NULL; j++)
		{
			if (access(args[0], X_OK) == 0)
			{
				printf("%s ", line);
			}
			else
			{
				_printf("%s: No such file or directory\n", av[0]);
			}
		}
	}

	free(args);
}
