#include "main.h"
char *shell_prompt = "$ ";
char *user_input = NULL;
char *user_input_copy = NULL;
size_t input_buffer_size = 0;
ssize_t characters_read;
const char *delimiter = " \n";
int num_tokens = 0;
char *token;
int i;

(void)argc;

while (1)
{
printf("%s", shell_prompt);
characters_read = getline(&user_input, &input_buffer_size, stdin);
/* Check for getline failure or user exit */
if (characters_read == -1)
{
printf("Exiting shell..\n");
return -1;
}

user_input[strcspn(user_input, "\n")] = '\0';

if (strcmp(user_input, "exit") == 0)
{
printf("Exiting Shell..\n");
break;
}

user_input_copy = malloc(sizeof(char) * characters_read);
if (user_input_copy == NULL)
{
perror("tsh: memory allocation error");
return -1;
}

strcpy(user_input_copy, user_input);
token = strtok(user_input, delimiter);

while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delimiter);
}
num_tokens++;

argv = malloc(sizeof(char *) * num_tokens);
token = strtok(user_input_copy, delimiter);

for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * strlen(token));
strcpy(argv[i], token);
token = strtok(NULL, delimiter);
}
argv[i] = NULL;

execmd(argv);
}

free(user_input);
free(user_input_copy);

return 0;

