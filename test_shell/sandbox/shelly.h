#ifndef SHELLY_H
#define SHELLY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define STR_LEN 300
extern char **ms_env;

void prompt(void);
void handleError(char *msg, bool exitApp);
int printString(char *str);
size_t splitToTokens(char *ms_cmd, char *argv[]);
ssize_t execCommand(char *cmd, char *argv[]);
ssize_t findCommand(char *argv[]);
void checkExitChangedir(int argc, char *argv[]);
void redirection(int argc, char *argv[]);
void checkForFullPath(char *argv[], char *envp[]);
void lessThanMode(int argc, char *argv[], int i);
void greaterThanMode(int argc, char *argv[], int i);
void greater2Mode(int argc, char *argv[], int i);

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strtok(char **str, char delim);
int _atoi(char *str);
char *_strcat(char *dest, char *src);
#endif
