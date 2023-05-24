#ifndef HEADER_SHELL_H
#define HEADER_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

void displayPrompt(void);
void executeCommand(char *command);
void shell(void);
char* custom_strncpy(char* dest, char* src, int n);
char* custom_strncat(char* dest, char* src, int n);
char* custom_strchr(char* s, char c);
int digit(int c);
int _exit(info_t *info);
int _cd(info_t *info);
int _help(info_t *info);
#endif /* HEADER_SHELL_H */

