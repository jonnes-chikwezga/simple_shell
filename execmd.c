#include "main.h"
/**
 * execmd - Entry Point
 * @argv: command arguments typed by user
 *
 */
void execmd(char **argv)
{
char *command = NULL, *actual_command = NULL;

if (argv)
{
command = argv[0];

actual_command = get_location(command);

if (execve(actual_command, argv, NULL) == -1)
{
perror("Error:");
}
}
}
