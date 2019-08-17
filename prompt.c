#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "holberton.h"

int main (void)
{
	char *buff;
	char *a = "exit\n";
	size_t flag = 1;
	size_t buffsize = 1024;
	int characters = 0, pid, secs, len, count;
	char **argv;
	char dest[64] = EXE_PATH;
	buff = malloc(sizeof(char) * buffsize);
	if (!buff)
	{
		exit(1);
	}
	while (flag)
	{
		printf("$ ");
		characters = getline(&buff, &buffsize, stdin);
		if (!strcmp(a, buff) || characters == EOF)
		{
			flag = 0;
			continue;
		}
		pid = fork();
		if (pid == 0) /* Executes child */
		{
			len = strlen(buff);
			buff[len - 1] = '\0';
			argv = token_buff(buff);
			argv[0] = concat_path(argv[0]);
			printf("%s\n", argv[0]);
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
			free(buff);
			free(argv);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait (&secs);
		}
	}
	free(buff);
	free(argv);
	return (0);
}
char **token_buff(char *buff)
{
	int buffsize = 64, iterator = 0;
	char **tokens = malloc(sizeof(char *) * buffsize);
	char *stoken, *delimit = " ";

	if (tokens == NULL)
	{
		perror("Not possible to allocate memory");
		exit(98);
	}
	stoken = strtok(buff, delimit);
	while (stoken != NULL)
	{
		tokens[iterator] = stoken;
		iterator++;
		stoken = strtok(NULL, delimit);
	}
	tokens[iterator] = NULL;
	return (tokens);
}
