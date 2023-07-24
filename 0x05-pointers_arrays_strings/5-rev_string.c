#include "main.h"

/**
 * rev_string - prints a string, in reverse, followed by a new line
 * @s: string to be reversed
 */

void rev_string(char *s)
{
	int length, half, i;

	char temp;

	for (length = 0; s[length] != '\0'; length++)
	;
	i = 0;
	half = length / 2;

	while (half--)
	{
		temp = s[length - i - 1];
		s[length - i - 1] = s[i];
		s[i] = temp;
		i++;
	}
}
