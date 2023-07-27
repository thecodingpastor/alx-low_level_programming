#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase.
 * @arg: variable to work on
 *
 * Return: a char
 */

char *string_toupper(char *arg)
{
	int i;

	i = 0;

	while (arg[i] != '\0')
	{
		if (arg[i] >= 'a' && arg[i] <= 'z')
		{
			arg[i] = arg[i] - 32;
		}
		i++;
	}
	return (arg);
}
