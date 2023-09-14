#include "stdio.h"
#include "string.h"

int main(void)
{
    char command[] = "ls -l /home/user";
    char *token;
    char *delimeter = " ";

    token = strtok(command, delimeter);

    while (token)
    {
        printf("Token: %s\n", token);
        strtok(NULL, delimeter); // to continue tokenization
	token++;
    }

    return (0);
}
