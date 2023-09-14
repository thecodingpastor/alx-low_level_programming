#include "shelly.h"
/**
 * main - mimics unix shell
 * @argc: number of args passed in the command line
 * @argv: array of strings of args
 * Return: 0 or -1
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	ssize_t ms_numCharsRead;
	char *ms_linePointer = NULL, *ms_linePointerCP = NULL, *ms_token = NULL;
	size_t ms_lineSize = 0;
	int ms_numOfTokens = 0, i, j;

	while (true)
	{
		prompt();
		ms_numCharsRead = getline(&ms_linePointer, &ms_lineSize, stdin);

		if (ms_numCharsRead == -1)
		{
			handleError("\nSee ya later...");
			return (-1);
		}
		ms_token = strtok(ms_linePointer, " \n");

		while (ms_token != NULL)
		{
			printString(ms_token), printString("\n");
			ms_numOfTokens++, ms_token = strtok(NULL, " \n");
		}
	}
	free(ms_linePointer);
	return (0);
}
