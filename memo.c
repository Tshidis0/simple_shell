#include "shell.h"
/**
 * _realloc - relloactes the memory using malloc and free
 * @ptr: pointer to previous memory
 * @old_size: size in bytes of allocated space for ptr
 * @new_size: bytes of the new memory
 * Return: pointer to newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
unsigned int i;

void *new_ptr;

if (ptr == NULL)
return (malloc(new_size));

if (new_size == 0)
{
free(ptr);
return (NULL);
}

if (new_size == old_size)
return (ptr);

new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);

if (new_size > old_size)
new_size = old_size;

for (i = 0; i < new_size; i++)
*((char *)new_ptr + i) = *((char *)ptr + i);

free(ptr);

return (new_ptr);
}

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements in array
 * @size: size of bytes
 * Return: pointer to allocated element or NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
char *ptr;
unsigned int count;

if (nmemb == 0 || size == 0)
{
return (NULL);
}

ptr = malloc(nmemb * size);
if (ptr == NULL)
{
return (NULL);
}
count = 0;
while (count < nmemb * size)
{
ptr[count] = 0;
count++;
}
return (ptr);
}

/**
 * _memcpy - function that copies memory area
 * @dest: return of memory
 * @src: bytes from memory area
 * @n: function copies
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;

for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[i] = src[i];
}
for (; i < n; i++)
{
dest[i] = '\0';
}
return (dest);
}
/**
 * print_string - a string to be free
 * @ptr: double pointer
 */
void print_string(char **ptr)
{
char **str = ptr;

if (!ptr)
return;
while (*ptr)
free(*ptr++);
free(str);
}
