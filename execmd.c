#include "main.h"

void execute_command(char **command_args)
{
char *command = NULL;
char *actual_command = NULL;

if (command_args)
{
command = command_args[0];

actual_command = find_command_path(command);

if (execve(actual_command, command_args, NULL) == -1)
{
perror("shell: execution error");
}
}
}

