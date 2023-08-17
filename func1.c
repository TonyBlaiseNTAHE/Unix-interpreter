#include "shell.h"

/**
 * _getline - reads an entire line form stream.
 * @lineptr: a pointer that store the address containning the text
 * @n: number of bytes for the buffer.
 * @stream: where to get the input from.
 * Return: number of character readed.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0, m;
	int ch;

	if (lineptr == NULL || *n == 0 || stream == NULL)
	{
		return (-1);
	}
	if (*lineptr == NULL && *n == 0)
	{
		*n = 100;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	while ((ch = fgetc(stream)) != EOF)
	{
		if (pos >= *n)
		{
			m = *n * 2;
			*lineptr = _realloc(*lineptr, *n, m);
			if (*lineptr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*n = m;
		}
		if (ch == '\n')
		{
			break;
		}
		/*if (ch == 0 || ch == EOF)
		{
			return (-1);
		}*/
		(*lineptr)[pos] = ch;
		pos++;
	}
	(*lineptr)[pos] = '\0';
	return (pos);
}
/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: pointer to the memory allocated previously.
 * @old_size: the old size in byte allocated previously.
 * @new_size: the new size needed to be allocated.
 * Return: pointer to the reallocated memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		ptr = malloc(new_size);
	if (new_size == old_size)
	{
		return (ptr);
	}
	free(ptr);
	ptr = malloc(new_size);
	return (ptr);
}
