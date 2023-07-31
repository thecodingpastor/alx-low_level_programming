#include "main.h"

/**
 * _memcpy - a function that copies memory areas
 * @dest: arg 1
 * @src: arg 2
 * @n: arg 3
 *
 * Return: copied memory
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int a = 0, i = n;

	for (; a < i; a++)
	{
		dest[a] = src[a];
		n--;
	}

	return (dest);
}
