#include "main.h"
#include <stdio.h>

int _pow(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow(x, y - 1));
}

int main(void)
{
	int num = _pow(7,2);
	int num2 = _pow(1000, 0);
	int num3 = _pow(4,4);
int num4 = _pow(5, -4);

	printf("%d %d %d %d\n", num, num2, num3, num4);
	return (0);
}
