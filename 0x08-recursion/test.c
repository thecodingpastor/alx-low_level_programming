#include "main.h"

void puts_recursion(char *str)
{
	if (*str)
	{
		puts_recursion(str + 1), _putchar(*str);
	}
}

int main(void)
{
	puts_recursion("Mike");
	return (0);
}
