#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: integer to be converted
 */
void print_binary(unsigned long int n)
{
	int i = 0, j = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			_putchar('1');
			j++;
		}
		else if (j)
			_putchar('0');
	}
	if (!j)
		_putchar('0');
}
