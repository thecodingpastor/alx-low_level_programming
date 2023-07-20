#include <stdio.h>

/**
 * main - prints first 98 fibonacci sequence
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;
	unsigned long int t1, t2, nextTerm;

	t1 = 1;
	t2 = 1;
	nextTerm = t1 + t2;

	printf("%lu, %lu, %lu, ", t1, t2, nextTerm);

	for (i = 4; i <= 98; i++)
	{
		t1 = t2;
		t2 = nextTerm;
		nextTerm = t1 + t2;

		if (i != 98)
		{
			printf("%lu, ", nextTerm);
		} else
		{
			printf("%lu", nextTerm);
		}
	}
	printf("\n");
	return (0);
}
