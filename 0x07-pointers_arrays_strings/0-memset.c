#include "main.h"

/**
 * _memset - fills memory with a constant byte.
 *
 * @s: arg 1
 * @b: arg 2
 * @n: arg 3
 *
 * Return: changed array
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}

	return (s);
}
