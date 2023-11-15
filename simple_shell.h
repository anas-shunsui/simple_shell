#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>

extern char **environ;

/* Functions */
void _debut(void);
void non_intermode(char *token, int *status);
ssize_t read_cmd(char **l, size_t *sizeof_l);
void _exit_status(int my_stat, char **sngl_cmd, char **token,
int *status);
void _custom_exit(int my_stat, char **cmds,
char *l, int *status);

/* execute */
void _exec(char **cmds, char **environ, int *status);
int _search(char *cmd, char **path);
void child_process(int *status);
char *_getenv(const char *path);
int _atoi(char *str);

/* toknizer and delimiters */
char **splinter_string(char *s, char *del);

/* Error messages */
void _werror(char *cmd);
void _wexit_werror(char *num);
void _environ_var(void);
void _getline_error(char *l);

/* strings*/
char *_strdup(const char *src);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);


/* memory leak*/
void free_array(char **array);

#endif
