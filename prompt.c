#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "holberton.h"
/**
 * main - integrates the functions to make the shell work
 * Return: 0 on success
 */
int main(void)
{
	char *buff;
	size_t buffsize = 1024;
	char **argv = 0;
	int flag = 1;

 	built_in_t built_in_arr[] = {
	{"exit", ourexit},
	{"env", _printenv},
	{NULL, NULL}
	};
 	(void)signal(SIGINT, sign_handler);
	buff = malloc(sizeof(char) * buffsize);
	if (!buff)
	{
		exit(1);
	}
	if(isatty(STDIN_FILENO) != 1)
	{
		if(getline(&buff, &buffsize, stdin) == EOF)
		{
			write_to_stdout("\n");
			flag = 0;
		}
		buff[_strlen(buff) - 1] = '\0';
		argv = token_buff(buff, " \t\r\n\a");
		shell_execute(argv, built_in_arr);
		free(buff);
		free(argv);
		return (0);
	}
	while (flag)
	{
		write_to_stdout("$ ");
		if (getline(&buff, &buffsize, stdin) == EOF)
		{
			write_to_stdout("\n");
			flag = 0;
			continue;
		}
		buff[_strlen(buff) - 1] = '\0';
		argv = token_buff(buff, " \t\r\n\a");
		shell_execute(argv, built_in_arr);
	}
	free(buff);
	free(argv);
	return (0);
}
/**
 * token_buff - splits the buffer into tokens
 * @buff: pointer to the buffer
 * @delimit: delimitator chosen
 * Return: double pointer to the tokens
 **/
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
/**
 * write_to_stdout - writes a string to the stdout
 * @str: pointer to the string to print
 **/
void write_to_stdout(char *str)
{
	write(1, str, _strlen(str));
}
/**
 * check_existence - checkes whether a file exists
 * @path: pointer to the path to search in
 * Return: 1 on success, -1 if failed
 */
int check_existence(char *path)
{
	int fd = access(path, F_OK & X_OK);

	if (fd == -1)
		return (-1);
	return (1);
}
/**
 * sign_handler - handles the abscensce of a sign
 * @sig: integer
 */
void sign_handler(int sig)
{
	(void) sig;
	write_to_stdout("\n");
	write_to_stdout("$ ");
	fflush(stdout);
}
