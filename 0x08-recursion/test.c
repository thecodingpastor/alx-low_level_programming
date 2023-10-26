#include  "main.h"

int handle_recursion(int num, int i)
{
	if (i * i > num)
		return (-1);
	else if (i * i == num)
		return (i);
	return handle_recursion(num, i + 1);
}

int _sqrt_recursion(int n)
{
        if (n < 0)
        {
                return (-1);
        }
        return (handle_recursion(n, 0));
}

int main(void)
{
        int r;

        r = _sqrt_recursion(1);
        printf("%d\n", r);
        r = _sqrt_recursion(1024);
        printf("%d\n", r);
        r = _sqrt_recursion(16);
        printf("%d\n", r);
        r = _sqrt_recursion(17);
        printf("%d\n", r);
        r = _sqrt_recursion(25);
        printf("%d\n", r);
        r = _sqrt_recursion(-1);
        printf("%d\n", r);
        return (0);
}
