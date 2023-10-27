#include <stdio.h>

/**
 * main - pritnts itsname
 * @argc: number of args passed
 * @argv: string  array of values
 *
 * Return: Always 0 (Succes)
 */

int main(int argc, char *argv[])
{
	if (argc > 0)
		printf("%s\n", argv[0]);
	return (0);
}
