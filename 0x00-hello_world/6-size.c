#include <stdio.h>

/*
 * main - Entry
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("char size: %d", sizeof(char));
	printf("int size: %d", sizeof(int));
	printf("long int size: %d", sizeof(long int));
	printf("long long int size: %d", sizeof(long long int));
	printf("float size: %d", sizeof(float));
}
