#include "shelly.h"
/**
 * handleError - handles error msg printing
 * @msg: message to be printed
 */
void handleError(char *msg)
{
	printString(msg), printString("\n");
	exit(7);
}
