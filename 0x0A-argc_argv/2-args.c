#include <stdio.h>

/**
 * main -  that prints all arguments it receives.
 * @argc: count
 * @argv: values
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
