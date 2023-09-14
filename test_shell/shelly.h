#ifndef SHELLY_H
#define SHELLY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
int printString(const char *str);
void handleError(char *msg);
void prompt(void);

#endif
