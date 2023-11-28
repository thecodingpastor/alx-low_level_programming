#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to be created.
 * @text_content: A pointer to string to write to file.
 * Return: 1 or -1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, l);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
