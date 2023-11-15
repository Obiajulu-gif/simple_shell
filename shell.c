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
			line[read - 1] = '\n';
		}
		execCommand(line, av);
		free(line);
		handle_command_with_args(av, ac);
	}
	return (0);
}

/**
 * execCommand - execute the commands
 * @line: the input
 * @av: the argument vector
 */
void execCommand(char *line, char **av)
{
	char *token, **args = malloc(MAX_ARGS * sizeof(char *));
	int i = 0, executable = 0;

	if (!args)
		exit(1);

	token = strtok(line, " \t\n");
	while (token)
		args[i++] = token, token = strtok(NULL, " \t\n");
	args[i] = NULL;

	for (i = 0; args[i]; i++)
		if (access(args[i], X_OK) == 0)
			executable = 1;

	if (executable)
	{
		if (fork() == 0)
			execve(args[0], args, NULL), perror("Execution error"), exit(1);
		else
			wait(NULL);
	}
	else
		_printf("%s: No such file or directory\n", av[0]);

	free(args);
}
