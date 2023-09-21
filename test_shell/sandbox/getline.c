#include "shelly.h"
/**
 * _getline - mimics standard getline
 * @linePointer: pointer to the line
 * @n: size
 * @stream: stream
 * Return: integer
 */
ssize_t _getline(char **linePointer, size_t *n, FILE *stream)
{
	int c;
	size_t i = 0;

	if (linePointer == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*linePointer == NULL || *n == 0)
	{
		*n = INITIAL_BUFFER_SIZE, *linePointer = (char *)malloc(*n);

		if (*linePointer == NULL)
			return (-1);
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= (*n - 1))
		{
			size_t new_size = *n * 2;
			char *new_ptr = (char *)realloc(*linePointer, new_size);

			if (new_ptr == NULL)
				return (-1);
			*linePointer = new_ptr, *n = new_size;
		}
		(*linePointer)[i++] = (char)c;

		if (c == '\n')
		{
			(*linePointer)[i] = '\0';
			return (i);
		}
	}
	if (i == 0)
		return (-1);
	(*linePointer)[i] = '\0';
	return (i);
}
