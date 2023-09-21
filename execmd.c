#include "main.h"

/**
 * execute_command - Execute a shell command.
 *
 * This function takes an array of command arguments and attempts to execute
 * the specified command.
 *
 * @param command_args An array of strings representing the command and its arguments.
 *                    The first element (command_args[0]) should be the command name,
 *                    followed by its arguments. The array must be NULL-terminated.
 */
void execute_command(char **command_args)
{
char *command = NULL;
char *actual_command = NULL;

if (command_args)
{
command = command_args[0];

actual_command = get_location(command);

if (execve(actual_command, command_args, NULL) == -1)
{
perror("shell: execution error");
}
}
}

