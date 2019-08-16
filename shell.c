#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"

int main(void)
{
	char *buffer;
	size_t running = 1;
	size_t size = 1024;
	char e[] = "exit\n";
	int line;
	int pid;
	char **argv;
	int status;
	int i;

	buffer = malloc(sizeof(char) * size);

	if (!buffer)
	{
		printf("Error: can not allocate memory for buffer");
		exit(1);
	}

	while (running)
	{
		printf("User$ ");

		line = getline(&buffer, &size, stdin);

		if (!strcmp(buffer, e) || line == EOF)
		{
			running = 0;
			continue;
		}

		pid = fork();

		if (!pid)
		{
			buffer[strlen(buffer) - 1] = '\0';

			argv = split_commands(buffer);

			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");

			return (0);
		}
		else
		{
			wait(status);
			/* free resources here ? */
		}
	}
	free(buffer);
	return (0);
}

char **split_commands(char *buffer)
{
	char **argv;
	char *token, *copy;
	char deli[2] = " ";
	int words = 0;
	int i = 0, j = 0, k = 0, len;

	copy = strdup(buffer);

	/* get amount of words */

	token = strtok(copy, deli);

	while (token)
	{
		words++;
		token = strtok(NULL, deli);
	}

	/* allocate pointer to words words */

	argv = malloc(sizeof(char *) * words);

	if (!argv)
	{
		printf("Error");
		return (NULL);
	}

	/* allocate words */
	free(copy);

	copy = strdup(buffer);

	token = strtok(copy, deli);

	while (token)
	{
		len = strlen(token);
		*(argv + i) = malloc(sizeof(char) * (len + 1));
		if (!*(argv + i))
		{
			printf("Error: couldn't allocate memory for arguments");
			
			for (k = 0; k < i; k++)
				free(*(argv + k));
			free(argv);
			return (NULL);
		}
		for (j = 0; j < len; j++)
			*(*(argv + i) + j) = *(token + j);
		token = strtok(NULL, deli);
		i++;
	}
	*(argv + i) = NULL;
	free(copy);
	return (argv);
}
