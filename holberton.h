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
char *concat_path(char *command);

char **token_buff(char *buff);
#endif
