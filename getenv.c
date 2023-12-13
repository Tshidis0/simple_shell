#include "shell.h"
/**
 * _getenv - function get an environment variable
 * @name: variable name
 * Return: env variable or NULL
 */
char *_getenv(const char *name)
{
int i = 0, j, count, len;
char *copy = (char *name);

if (name == NULL || !name[i])
return (NULL);

len = _strlen(copy);
while (*(environ + i))
{
j = 0;
while (*(*(environ + i) + j) != '=')
{
if (*(*(environ + i) + j) == name[j])
count++;
j++;
}
if (count == len)
{
j++;
return (*(environ + i) + j);
}
i++;
count = 0;
}
return (NULL);
}
