#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

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

#define DELIM " \t\n"
extern char **environ;

char *read_line(void);
char **splinter(char *l);
int _exec(char **cmd, char **argv);

char *_strdup(const char *s);
int _strcmp(char *str1, char str2);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void free_array(char **array);

#endif