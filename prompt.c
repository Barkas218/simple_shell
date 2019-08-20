#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "holberton.h"

int main(void)
{
	char *buff;
	size_t buffsize = 1024;
	char **argv = 0;

	built_in_t built_in_arr[] = {
	{"exit", ourexit},
	{NULL, NULL}
	};

	buff = malloc(sizeof(char) * buffsize);
	if (!buff)
	{
		exit(1);
	}
	write_to_stdout("$ ");
	while (getline(&buff, &buffsize, stdin) != EOF)
	{
		buff[_strlen(buff) - 1] = '\0';
		argv = token_buff(buff, " ");

		shell_execute(argv, built_in_arr);
		write_to_stdout("$ ");
	}
	free(buff);
	free(argv);
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
	stoken = _strtok(buff, delimit);
	while (stoken != NULL)
	{
		tokens[iterator] = stoken;
		iterator++;
		stoken = _strtok(NULL, delimit);
	}
	tokens[iterator] = NULL;
	return (tokens);
}

void write_to_stdout(char *str)
{
	write(1, str, _strlen(str));
}

int check_existence(char *path)
{
	int fd = access(path, F_OK & X_OK);

	if (fd == -1)
		return (-1);
	return (1);
}
