#include "main.h"


/**
 * display_prompt - entry point
 */
void display_prompt(void)
{
	_printf("#cisfun$ ");
	fflush(stdout);
}

/**
 * execute_command - entry point, execution of all my command
 * @command_line: the command line
 * @shell_name: shell name
 */
void execute_command(char *command_line, char *shell_name)
{
	pid_t pid;

	if (_strcmp(command_line, "exit") == 0)
	{
		_printf("Exiting shell.\n");
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(command_line, "exit") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			_printf("%s\n", *env);
			env++;
		}
		return;
	}
	pid = fork();

	if (pid == -1)
		perror("Forking error");
	else if (pid == 0)
	{
		char *args[MAX_ARGS];
		int i = 0;
		char *token = strtok(command_line, " ");

		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		execvp(args[0], args);
		perror(shell_name);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: an integer 0 or 1
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *command = NULL;

	while (1)
	{
		display_prompt();

		command = _getline();
		if (command == NULL)
		{
			_printf("\nExiting shell.\n");
			break;
		}

		execute_command(command, argv[0]);
	}

	return (0);
}
