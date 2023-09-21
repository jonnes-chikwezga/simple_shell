#include "main.h"

char *path, *path_copy, *path_token, *command_path;
int command_length, directory_length;
struct stat file_info;

path = getenv("PATH");

if (path)
{
path_copy = strdup(path);
command_length = strlen(command);
path_token = strtok(path_copy, ":");

while (path_token != NULL)
{
directory_length = strlen(path_token);
command_path = malloc(command_length + directory_length + 2);
strcpy(command_path, path_token);
strcat(command_path, "/");
strcat(command_path, command);
strcat(command_path, "\0");

if (stat(command_path, &file_info) == 0)
{
free(path_copy);
return command_path;
}
else
{
free(command_path);
path_token = strtok(NULL, ":");
}
}
}

free(path_copy);

if (stat(command, &file_info) == 0)
{
return command;
}

return NULL;

