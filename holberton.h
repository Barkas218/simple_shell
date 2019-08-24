#ifndef HOLBERTON_
#define HOLBERTON_
/* const Macros */

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

/* Structs */

typedef struct built_in
{
	char *command;
	int (*f)(char **argv);
} built_in_t;

int ourexit(char **argv);
int _printenv(char **argv);
int _setenv(char ** argv);
int _cd(char **argv);
int _unsetenv(char **argv);

/* functions prototypes */
int shell_core(char *buff, size_t buffsize, char **argv, built_in_t buil_in_arr[]);
void sign_handler(int sig);
char *_strcat(char *dest, char *command);
int check_existence(char *file);
char **token_buff(char *buff, char *delimiter);
ssize_t _getline(char *buffer, size_t size);
int _strlen(char *str);
void write_to_stdout(char *str);
int _strcmp(char *s1, char *s2);
char *_getenv(char *key);
char *_strtok(char *s, char *deli);
unsigned int _strcspn(char *s1, char *s2);
char *_strchr(char *s, char b);
char *_strdup(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _atoi(char *s);
char *_strcpy(char *dest, char *src);
int shell_execute(char **argv, built_in_t built_in_arr[]);
int shell_launch(char **argv);
#endif
