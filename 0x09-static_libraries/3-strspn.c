#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: agr 1
 * @accept: arg 2
 *
 * Return: Returns the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int a = 0;
	int b = 0;

	while (*s)
	{
		for (b = 0; accept[b]; b++)
		{
			if (*s == accept[b])
			{
				a++;
				break;
			} else if (accept[b + 1] == '\0')
			{
				return (a);
			}
		}
		s++;
	}
	return (a);
}

