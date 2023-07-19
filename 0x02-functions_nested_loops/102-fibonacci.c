#include <stdio.h>

/**
 * main - fibonacci to 50
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;
	unsigned long int t1, t2, nextTerm;

	t1 = 1;
	t2 = 2;
	nextTerm = t1 + t2;

	printf("%lu, %lu, %lu, ", t1, t2, nextTerm);

	for (i = 4; i <= 50; i++)
	{
		t1 = t2;
		t2 = nextTerm;
		nextTerm = t1 + t2;

		if (i != 50)
		{
			printf("%lu, ", nextTerm);
		} else
		{
			printf("%lu", nextTerm);
		}
	}
	printf("\n");
}
