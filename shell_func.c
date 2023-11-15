#include "main.h"

void handle_command_with_args(char **args,
int num_args __attribute__((unused)))
{
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

