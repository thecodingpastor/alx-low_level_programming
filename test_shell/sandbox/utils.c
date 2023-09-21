#include "shelly.h"
/**
 * prompt - displays the shelly prompter
 */
void prompt(void)
{
	printString("shelly_$ ");
}

/**
 * printString - prints string
 * @str: string to be printed
 * Return: number of strings printed
 */
int printString(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * handleError - prints errors
 * @msg: message to be printed
 * @exitApp: 1 or 0 to indicate exit after error
 */
void handleError(char *msg, bool exitApp)
{
	printString(msg);
	if (exitApp)
		exit(2);
}

/**
 * splitToTokens - splits arguments into tokens
 * @ms_cmd: pointer to the full commands string passed
 * @argv: arg vectors
 * @ms_delim: delimeter
 * Return: number of tokens.
 */
size_t splitToTokens(char *ms_cmd, char *argv[], char *ms_delim)
{
	size_t ms_numTokens = 0;
	char *ms_token = _strtok(ms_cmd, ms_delim);

	while (ms_token)
	{
		argv[ms_numTokens] = ms_token;
		ms_token = _strtok(NULL, ms_delim);
		ms_numTokens++;
	}
	argv[ms_numTokens] = NULL;
	return (ms_numTokens);
}
