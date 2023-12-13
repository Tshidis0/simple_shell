#include "shell.h"
/**
 * builtin_cd - builtin command directory
 * @args: pointer to pointer argument
 * Return: 0 on success or 1 on fail
 */
int builtin_cd(char **args)
{
char *new_dir;

if (args[1] ==  NULL)
{
new_dir = getenv("HOME");
}
else if (strcmp(args[1], "-") == 0)
{
new_dir = getenv("OLDPWD");
printf("%s\n", new_dir);
}
else
{
new_dir = args[1];
}

char current_dir[1024];

if (getcwd(current_dir, sizeof(current_dir)) == NULL)
{
perror("getcwd");
return (1);
}
setenv("OLDPWD", current_dir, 1);

if (chdir(new_dir) != 0)
{
perror("cd");
return (1);
}
if (setenv("PWD", new_dir, 1) != 0)
{
perror("setenv");
return (1);
}
return (0);
}
/**
 * main - entry point
 * @argc: argument command
 * @argv: pointer to pointer argument value
 * Return: 1 on success or result on fail
 */
int main(int argc, char **argv)
{
if (argc < 2)
{
fprintf(stderr, "Usage: %s /simple_shell\n", argv[0]);
return (1);
}
int result = builtin_cd(argv);

return (result);
}
