#include "main.h"

/**
 * execute_command - Execute a shell command.
 *
 * This function takes an array of command arguments and attempts to execute
 * the specified command.
 *
 * @param command_args An array of strings representing the command and its arguments.
 *                    It should be a NULL-terminated array.
 */
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

