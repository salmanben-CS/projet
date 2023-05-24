#ifndef HEADER_SHELL_H
#define HEADER_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void displayPrompt(void);
void executeCommand(char *command);
void shell(void);
char* custom_strncpy(char* dest, char* src, int n);
char* custom_strncat(char* dest, char* src, int n);
char* custom_strchr(char* s, char c);
int digit(int c);
#endif /* HEADER_SHELL_H */

