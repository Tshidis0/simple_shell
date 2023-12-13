#include "shell.h"
/**
 * main - entry point
 * @argc: argument command
 * @argv: argument value
 * Return: 1 on success or if fail
 */
int main(int argc, char **argv)
{
if (argc != 2)
{
fprintf(stderr, "Usage: simple_shell MyShell\n");
return (1);
}

FILE *f = fopen(argv[1], "r");
if (f == NULL)
{
fprintf(stderr, "Error opening file: %s\n" argv[1]);
return (1);
}

char line[1024];
while (fget(line, sizeof(line), f) != NULL)
{
char *args[1024];
int n_args = 0;

char *arg = strtok(line, " \t\n");
while (arg != NULL)
{
args[n_args++] = arg;
arg = strtok(NULL, " \t\n");
}

if (execvp(args[0], args) < 0)
{
fprintf(stderr, "Error executing command: %s\n", args[0]);
}
}
fclose(f);
return (0);
}
