#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line.
 * @str: string to be processed
 */

void puts_half(char *str)
{
	int length, i, half;

	length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	half = length / 2;

	for (i = half; i <= length; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

