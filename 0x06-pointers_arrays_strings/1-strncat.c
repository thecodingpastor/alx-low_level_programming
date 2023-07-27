#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: first string
 * @src: second string
 * @n: number of bytes toi use at most
 *
 * Return: a pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;

	while (dest[i] != '\0')
	{
		dest++;
	}

	j = 0;

	while (j < n && src[j] != '\0')
	{
		*dest = *src;
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
