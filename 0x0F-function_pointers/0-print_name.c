#include "function_pointers.h"

/**
 * print_name - prints a name
 *
 * @name: arg1
 * @f: function pointer arg
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == 0 || f == 0)
		return;
	f(name);
}
