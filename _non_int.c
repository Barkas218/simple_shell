#include "holberton.h"
/**
 * _non_int - executes the shell in non-interactive mode
 * @arr: array of structures to handle built in commands
 */
void _non_int(built_in_t arr[])
{
	char **argv;
	char *buff = 0;
	size_t buffsize = 1024;

	while (getline(&buff, &buffsize, stdin) != EOF)
	{
		argv = token_buff(buff, " \t\r\n\a");
		shell_execute(argv, arr);
		free(argv);
	}
	free(buff);
	exit(127);
}
