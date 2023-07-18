#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Print alphabets using _putchar
 */

void print_alphabet(void);

void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		_putchar(letter);
	}

	_putchar('\n');
}
