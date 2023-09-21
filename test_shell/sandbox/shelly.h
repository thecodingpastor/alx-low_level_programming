#ifndef SHELLY_H
#define SHELLY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#define INITIAL_BUFFER_SIZE 128
#define MAX_PATH_LENGTH 4096
extern int global_argc;
extern char **global_argv;

int _putchar(char c);
void prompt(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void handleError(char *msg, bool exitApp);
int printString(char *str);
size_t splitToTokens(char *ms_cmd, char *argv[], char *ms_delim);
ssize_t execCommand(int argc, char *argv[], char *envp[], int count);
void redirection(int argc, char *argv[]);
void checkForFullPath(char *argv[], char *envp[]);
void lessThanMode(int argc, char *argv[], int i);
void greaterThanMode(int argc, char *argv[], int i);
void greater2Mode(int argc, char *argv[], int i);
void checkExitChangedir(int argc, char *argv[]);
int printNum(int num);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strtok(char *str, char *c);

#endif
