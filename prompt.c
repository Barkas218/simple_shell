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
	char *buff = NULL, **argv = NULL;
	int flag = 1, err_count = 0;
	int status = EXIT_SUCCESS;

	built_in_t built_in_arr[] = {
		{"exit", ourexit},
		{"env", _printenv},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", _cd},
		{NULL, NULL}
	};

	(void)signal(SIGINT, sign_handler);
	(void) built_in_arr;

	while (flag)
	{
		if (isatty(STDIN_FILENO))
			_puts("$ ");

		err_count++;

		buff = read_input();

		argv = token_buff(buff, " \t\r\n\a");

		if (argv[0])
			status = shell_execute(argv, built_in_arr);

		if (status != EXIT_SUCCESS)
			_error_handler(status, err_count, argv);

		free(argv);
		free(buff);

		if (!isatty(STDIN_FILENO))
			return (EXIT_SUCCESS);
	}
	return (status);
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
		free(buff);
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
 * read_input - read input form stdin
 * Retirn: pointer to buffer read
 */
char *read_input()
{
	char *buff = NULL;
	size_t size = 1024;

	if (getline(&buff, &size, stdin) == EOF)
	{
		_puts("\n");
		free(buff);
		exit(EXIT_SUCCESS);
	}
	buff[_strlen(buff) - 1] = '\0';
	return (buff);
}

/**
 * sign_handler - handles the abscensce of a sign
 * @sig: integer
 */
void sign_handler(int sig)
{
	(void) sig;
	_puts("\n");
	_puts("$ ");
	fflush(stdout);
}
