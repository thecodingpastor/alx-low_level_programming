#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabets x 10 in lowercase
 */

void print_alphabet_x10(void)
{
	int num = 0;
	char letter;

	while (num < 10)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
		{
			_putchar(letter);
		}

		num++;

		_putchar('\n');
	}
}
