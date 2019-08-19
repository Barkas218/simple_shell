#ifndef HOLBERTON_
#define HOLBERTON_
/* const Macros */

#define EXE_PATH "/bin/"
/*libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/* functions prototypes */
char *_strcat(char *dest, char *command);
int check_existence(char *file);
char **token_buff(char *buff, char *delimiter);
ssize_t _getline(char *buffer, size_t size);
int _strlen(char *str);
void write_to_stdout(char *str);
int _strcmp(char *s1, char *s2);
#endif
