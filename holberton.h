#ifndef HOLBERTON_
#define HOLBERTON_
/* const Macros */

extern char **environ;
extern char *program_invocation_name;

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
/*int shell_core(char *buff, size_t buffsize, char **argv, built_in_t buil_in_arr[]);*/
void sign_handler(int sig);
char *read_input();

char *_strcat(char *dest, char *command);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char b);
char *_strdup(char *s);
unsigned int _strcspn(char *s1, char *s2);

int check_existence(char *file);
char **token_buff(char *buff, char *delimiter);
void _puts(char *str);
int _putchar(const char c);
void _printd(int n);

char *_getenv(char *key);
char *_strtok(char *s, char *deli);

int _atoi(char *s);

int shell_execute(char **argv, built_in_t built_in_arr[]);
int shell_launch(char **argv);

void _error_handler(int status, int err, char **argv);
#endif
