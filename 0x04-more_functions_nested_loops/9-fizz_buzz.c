#include <stdio.h>

/**
 * main - prints the numbers from 1 to 100
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 != 0)
		{
			printf("%s ", "Fizz");
		} else if (i % 5 == 0 && i % 3 != 0)
		{
			if (i == 100)
			{
				printf("Buzz");
			} else
			{
				printf("%s ", "Buzz");
			}
		} else if (i % 15 == 0)
		{
			printf("%s ", "FizzBuzz");
		} else
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return (0);
}
