#include "holberton.h"
/**
 * _printenv - prints the enviroment
 * @argv: pointer to the commands
 * Return: 1 on success
 */
int _printenv(char **argv)
{
	int i;
	(void) argv;

	for (i = 0; environ[i] != '\0'; i++)
	{
		write_to_stdout(environ[i]);
		write_to_stdout("\n");
	}
	return (0);
}
