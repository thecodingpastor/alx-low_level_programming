#include "main.h"

/**
 * _strchr - locates a character in a string.
 * @s: arg 1
 * @c: arg 2
 *
 * Return: a pointer to the first occurrence of the character
 */

char *_strchr(char *s, char c)
{
	int a = 0;

	for (; s[a] >= '\0'; a++)
	{
		if (s[a] == c)
		{
			return (&s[a]);
		}
	}
	return (0);
}
