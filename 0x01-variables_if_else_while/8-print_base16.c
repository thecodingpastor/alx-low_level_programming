#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int a;

	for (a = 0; a < 16; a++)
	{
		if (a >= 10)
		{
			putchar('a' + (a - 10));
		} else
		{
			putchar('0' + a);
		}
	}
	putchar('\n');

	return (0);
}
