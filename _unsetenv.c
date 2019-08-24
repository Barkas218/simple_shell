#include "holberton.h"
/**
 * _unsetenv - unsets an enviromental var
 * @argv: pointer to the buffer with the command line
 * Return: 1 on success
 */
int _unsetenv(char **argv)
{
	int i = 0, exist = 0, len = 0, j = 0;
	char *tok, *copy;
	char **new_env;

	while (environ[i])
	{
		copy = _strdup(environ[i]);
		tok = _strtok(copy, "=");
		if (!_strcmp(tok, argv[1]))
		{
			exist = 1;
		}
		len++;
		i++;
		free(copy);
	}

	if (exist)
	{
		new_env = malloc(sizeof(char *) * (len - 1));
		for (i = 0; i < len; i++)
		{
			copy = _strdup(environ[i]);
			tok = _strtok(copy, "=");
			if (!_strcmp(tok, argv[1]))
			{
				printf("-------------> Removing: %s\n", environ[i]);
				continue;
			}
			new_env[j] = environ[i];
			j++;
		}
		new_env[len - 1] = NULL;
		environ = new_env;
	}
	return (1);
}
