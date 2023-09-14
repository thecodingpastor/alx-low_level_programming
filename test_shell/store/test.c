#include "main.h"

int main(int argc, char **argv)
{
    (void)argc;

    ssize_t numCharsRead;
    char *prompt = "$ ";
    char *linePointer = NULL, *linePointerCP = NULL, *token = NULL;
    const char *delimeter = " \n";
    size_t lineSize = 0;
    int numOfTokens = 0, i, j;

    while (true)
    {
        printf("%s", prompt);
        numCharsRead = getline(&linePointer, &lineSize, stdin);

        if (numCharsRead == -1)
        {
            printf("Exiting...\n");
            return (-1);
        }

        linePointerCP = malloc(sizeof(char) * numCharsRead);

        if (!linePointerCP)
        {
            perror("Mem alloc failed.\n");
            return (-1);
        }

        strcpy(linePointerCP, linePointer);

        token = strtok(linePointer, delimeter);

        while (linePointer)
        {
            numOfTokens += 1;
            token = strtok(NULL, delimeter);
        }
        numOfTokens += 1;

        argv = malloc(sizeof(char *) * numOfTokens);

        token = strtok(linePointerCP, delimeter);

        for (i = 0; token; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);
            token = strtok(NULL, delimeter);
        }
        argv[i] = NULL;

        printf("%s\n", linePointer);
        free(linePointer);
    }

    for (j = 0; j < numOfTokens - 1; j++)
    {
        printf("%s\n", argv[j]);
    }
    return (0);
}
