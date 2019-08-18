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
	int characters = 0, pid, secs, len, existence;
	char **argv = 0, **paths = 0;

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
			argv = token_buff(buff, " ");

			/* test for existence */

			existence = check_existence(argv[0]);
			if (existence == -1)
			{
				int c;

				paths = token_buff(getenv("PATH"), ":");
				for (c = 0; paths[c]; c++)
				{
					char *command = _strcat("/", argv[0]);
					char *path_command = _strcat(paths[c], command);

					existence = check_existence(path_command);
					if (existence != -1)
					{
						argv[0] = path_command;
						break;
					}
					else
						free(path_command);
					free(command);
				}
			}
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
			free(buff);
			free(argv);
			free(paths);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait (&secs);
		}
	}
	free(buff);
	free(argv);
	free(paths);
	return (0);
}
char **token_buff(char *buff, char *delimit)
{
	int buffsize = 64, iterator = 0;
	char **tokens = malloc(sizeof(char *) * buffsize);
	char *stoken;

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

int check_existence(char *path)
{
	int fd = access(path, F_OK & X_OK);

	if (fd == -1)
		return (-1);
	return (1);
}
