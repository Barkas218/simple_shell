#include "holberton.h"
/**
 * _exit - checks whether the input is the exit command
 * @argv: buffer with the commands
 * Return: Exit status
 */
int ourexit(char **argv)
{
	int status = 0, i;

	if (argv[1] == NULL)
		exit(status);

	for (i = 0; argv[1][i] != '\0'; i++)
	{
		if (argv[1][i] < 48 || argv[1][i] > 57)
			perror("Error: ");

	}
	status = _atoi(argv[1]);
	exit(status);
}
