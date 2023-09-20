#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

#define STR_LEN 300

// Function prototypes
void prompt(void);
void handleError(const char *msg);
int printString(const char *str);
size_t splitToTokens(char *ms_linePointer, char *argv[]);
ssize_t execCommand(char *argv[], char **envp);
ssize_t findCommand(char *argv[], char **envp);
void checkExitChangedir(int argc, char *argv[]);

// Custom _strtok function
char *_strtok(char **str, const char *delim) {
    char *start = *str;
    char *end;

    // Skip leading delimiters
    while (*start && strchr(delim, *start))
        start++;

    if (!*start)
        return NULL;

    end = start;

    // Find the end of the token
    while (*end && !strchr(delim, *end))
        end++;

    if (*end) {
        *end = '\0';  // Null-terminate the token
        *str = end + 1;  // Update the str pointer for the next call
    } else {
        *str = NULL;  // No more tokens
    }

    return start;
}

int printString(const char *str)
{
    return (write(STDOUT_FILENO, str, strlen(str)));
}

void prompt(void)
{
    printString("shelly_$ ");
}

void handleError(const char *msg)
{
    fprintf(stderr, "%s", msg);
    exit(2);
}

ssize_t findCommand(char *argv[], char **envp)
{
    ssize_t status = -1;
    char *tokenPath, *ourPath;
    char *pathDelim = ":";

    ourPath = getenv("PATH");
    if (ourPath == NULL)
    {
        perror("getenv PATH error");
        return (-1);
    }
    tokenPath = strtok(ourPath, pathDelim);

    while (tokenPath)
    {
        char newPath[STR_LEN];
        strcpy(newPath, tokenPath);
        strcat(newPath, "/");
        strcat(newPath, argv[0]);
        status = execve(newPath, argv, envp);

        if (status == -1)
            tokenPath = strtok(NULL, pathDelim);
    }
    return (status);
}

ssize_t execCommand(char *argv[], char **envp)
{
    pid_t ms_pid = fork();
    int status;

    if (ms_pid < 0)
    {
        perror("Fork error");
        return (-1);
    }
    else if (ms_pid == 0)
    {
        int in_fd = -1;
        int out_fd = -1;

        for (int i = 0; argv[i] != NULL; i++)
        {
            if (strcmp(argv[i], "<") == 0)
            {
                // Redirection for input
                if (argv[i + 1] != NULL)
                {
                    in_fd = open(argv[i + 1], O_RDONLY);
                    if (in_fd == -1)
                    {
                        perror("Input file open error");
                        exit(1);
                    }
                    dup2(in_fd, STDIN_FILENO);
                    close(in_fd);
                    argv[i] = NULL;
                }
                else
                {
                    handleError("Missing input file.\n");
                }
            }

            if (strcmp(argv[i], ">") == 0)
            {
                // Redirection for output
                if (argv[i + 1] != NULL)
                {
                    out_fd = open(argv[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
                    if (out_fd == -1)
                    {
                        perror("Output file open error");
                        exit(1);
                    }
                    dup2(out_fd, STDOUT_FILENO);
                    close(out_fd);
                    argv[i] = NULL;
                }
                else
                {
                    handleError("Missing output file.\n");
                }
            }

            if (strcmp(argv[i], "|") == 0)
            {
                handleError("Piping is not supported in this shell.\n");
            }
        }

        if (strchr(argv[0], '/'))
        {
            if (execve(argv[0], argv, envp) == -1)
                perror(argv[0]);
        }
        else
        {
            if (findCommand(argv, envp) == -1)
                perror(argv[0]);
        }
        exit(0);
    }
    else
    {
        wait(&status);
        return status;
    }
}

void checkExitChangedir(int argc, char *argv[])
{
    if (argc > 0)
    {
        if (strcmp(argv[0], "exit") == 0)
        {
            exit(0);
        }
        else if (strcmp(argv[0], "cd") == 0)
        {
            if (argc == 2)
            {
                if (chdir(argv[1]) == -1)
                {
                    perror("cd");
                }
            }
            else
            {
                fprintf(stderr, "Usage: cd <directory>\n");
            }
            return;
        }
    }
}



size_t splitToTokens(char *ms_linePointer, char *argv[])
{
    char *ms_delim = " \n";
    size_t ms_numTokens = 0;
    char *ms_token = _strtok(&ms_linePointer, ms_delim);

    while (ms_token)
    {
        argv[ms_numTokens] = ms_token;
        ms_token = _strtok(&ms_linePointer, ms_delim);
        ms_numTokens++;
    }
    argv[ms_numTokens] = NULL;
    return (ms_numTokens);
}

int main(int argc, char *argv[], char **envp)
{
    ssize_t ms_numCharsRead;
    char *ms_linePointer = NULL;
    size_t ms_lineSize = 0;

    while (true)
    {
        prompt();
        ms_numCharsRead = getline(&ms_linePointer, &ms_lineSize, stdin);
        if (ms_numCharsRead == -1)
        {
            handleError("See ya later...\n");
        }
        char *command_argv[STR_LEN];
        size_t numTokens = splitToTokens(ms_linePointer, command_argv);

        checkExitChangedir(numTokens, command_argv);

        if (numTokens > 0)
        {
            execCommand(command_argv, envp);
        }
        free(ms_linePointer);
        ms_linePointer = NULL;
        ms_lineSize = 0;
    }
    return (0);
}
