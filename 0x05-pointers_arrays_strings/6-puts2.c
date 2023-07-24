#include "main.h"

/**
 * puts2 - prints every other character of a string,
 * starting with the first character,
 * followed by a new line
 * @s: string to be processed
 */

void puts2(char *s)
{
	while (*s != '\0')
	{
		_putchar(*s);
		s = s + 2;
	}
	_putchar('\n');
}
