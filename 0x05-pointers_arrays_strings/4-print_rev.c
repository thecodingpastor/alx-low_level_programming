#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: string to be reversed
 */

void print_rev(char *s)
{
	const char *end = s;

	while (*end != '\0')
	{
		end++;
	}
	end--;

	while (end >= s)
	{
		_putchar(*end);
		end--;
	}
	_putchar('\n');
}
