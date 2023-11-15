#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

extern char *commands;
extern int exit_status;




extern char **environ;

/*printf function */
void _printf(const char *format, ...);
int _getchar(void);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
void Shell_Interactive(int isActive);
char *read_command(void);
int run_command(char **args);
char *_strcat(char *dest, char *src);
char **split_command(char *command);
int execution(char **args);
char *read_fstream(void);
ssize_t _getline(char **lineptr, size_t *n, int fd);
int concate_command(char *command);
void free_arr(char **arr);

char *_getenv(const char *name);
int cd_func(char **args);
int env_func(char **args);
int exit_func(char **args);
void error_size(char **size);
int _strlen(char *s);

#endif
