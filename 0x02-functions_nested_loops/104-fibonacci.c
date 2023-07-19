#include <stdio.h>

/**
 * main - prints first 98 fibonacci sequence
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i, t1, t2, nextTerm;

	t1 = 1;
	t2 = 2;
	nextTerm = t1 + t2;

	printf("%d, %d, ", t1, t2);

	for (i = 3; i <= 98; i++)
	{
		t1 = t2;
		t2 = nextTerm;
		nextTerm = t1 + t2;

		if (i != 98)
		{
			printf("%d, ", nextTerm);
		} else
		{
			printf("%d", nextTerm);
		}
	}
	printf("\n");
	return (0);
}
