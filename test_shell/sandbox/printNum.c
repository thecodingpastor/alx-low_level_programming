#include "shelly.h"
/**
 * printNum - prints numbers
 * @num:number to be printed
 * Return: int
 */
int printNum(int num)
{
	int digits = 0, i;

	if (num < 0)
		_putchar('-'), num = -num, digits++;
	if (num == 0)
		_putchar('0'), digits++;
	else
	{
		int temp = num, index = 0;
		char buffer[20];

		while (temp > 0)
		{
			int digit = temp % 10;

			buffer[index] = '0' + digit;
			temp /= 10, index++, digits++;
		}
		for (i = index - 1; i >= 0; i--)
			_putchar(buffer[i]);
	}
	return (digits);
}
