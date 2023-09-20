#include "shelly.h"
/**
 * splitToTokens - splits arguments into tokens
 * @ms_cmd: pointer to the full commands string passed
 * @argv: arg vectors
 * Return: number of tokens.
 */

size_t splitToTokens(char *ms_cmd, char *argv[])
{
    char *ms_delim = " ";
    size_t ms_numTokens = 0;
    char *ms_token = strtok(ms_cmd, ms_delim);

    while (ms_token)
    {
        argv[ms_numTokens] = ms_token;
        ms_token = strtok(NULL, ms_delim);
        ms_numTokens++;
    }
    argv[ms_numTokens] = NULL;
    return (ms_numTokens);
}
