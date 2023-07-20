#include <stdio.h>

/**
 * main - prints first 98 fibonacci sequence
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int count;
	unsigned long int t1, t2, nextTerm;

	t1 = 1;
	t2 = 2;
	count = 2;

	printf("%lu, %lu, ", t1, t2);

	while (count < 98)
	{
		nextTerm = t1 + t2;
		if (count == 97)
		{
			printf("%lu", nextTerm);
		} else
		{
			printf("%lu, ", nextTerm);
		}
		t1 = t2;
		t2 = nextTerm;
		count++;
	}
	printf("\n");
	return (0);
}
