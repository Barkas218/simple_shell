#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void)
{
	char *buff;
	char *a = "exit\n";
	size_t flag = 1;
	size_t buffsize = 1024;
	int characters = 0, pid, secs, len;
	char *argv[] = {"/bin/ls", NULL};


	buff = malloc(sizeof(char) * buffsize);
	if (!buff)
	{
		exit(1);
	}
	printf("$ ");
	while (flag && (characters = getline(&buff, &buffsize, stdin)) != EOF)
	{
		if (strcmp(a, buff) == 0)
		{
			flag = 0;
			continue;
		}
		pid = fork();
		if (pid == 0) /* Executes child */
		{
			len = strlen(buff);
			buff[len - 1] = '\0';
			execve(buff, argv, NULL);
		}
		else
			wait (&secs);
		printf("$ ");
     	}
	return (0);
}
char **token_buff(char *buff)
{
	char *deli = " ";
	int iterator = 0;
	char *token;
	char **argv;

	argv = malloc(sizeof(char *) )
	while (token != NULL)
	{
		token = strtok(, deli);
		
	}
}
