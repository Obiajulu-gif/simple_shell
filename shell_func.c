#include "main.h"

void handle_command_with_args(char **args, int num_args __attribute__((unused))){
    if (access(args[0], X_OK) == 0)
    {
        if (fork() == 0)
        {
            execve(args[0], args, NULL);
        }
        else
        {
            wait(NULL);
        }
    }
    else
    {
        perror("Error");
    }
}

char **split_line(char *line)
{
    int bufsize = MAX_LINE / 2 + 1;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        _printf("Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += MAX_LINE / 2 + 1;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                _printf("Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}
