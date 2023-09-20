#include "shelly.h"

/**
 * handleError - prints errors
 * @msg: message to be printed
 */

void handleError(const char *msg)
{
	printString(msg);
	exit(2);
}
