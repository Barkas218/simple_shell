#ifndef HOLBERTON_
#define HOLBERTON_
/* const Macros */

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* functions prototypes */
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
#endif
