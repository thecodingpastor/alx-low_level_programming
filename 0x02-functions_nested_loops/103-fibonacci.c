#include <stdio.h>

/**
 * main - prints the sum of the even-valued terms less than 4000000
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int t1, t2, sum, nextTerm;

	t1 = 1;
	t2 = 2;
	sum = 2;
	nextTerm = t1 + t2;

	while (nextTerm < 4000000)
	{
		if (nextTerm % 2 == 0)
		{
			sum = sum + nextTerm;
		}
		t1 = t2;
		t2 = nextTerm;
		nextTerm = t1 + t2;
	}
}
