#include "holberton.h"

int _unsetenv(char **argv)
{
	int i = 0, exist = 0, len = 0;
	char *tok;
	char **new_env;

	while (environ[i])
	{
		tok = _strtok(environ[i], "=");
		if (!_strcmp(tok, argv[1]))
		{
			exist = 1;
		}
		len++;
	}

	if (exist)
	{
		new_env = malloc(sizeof(char *) * (len - 1));
		for (i = 0; i < len; i++)
		{
			tok = _strtok(environ[i], "=");
			if (!_strcmp(tok, argv[1]))
				continue;
			new_env[i] = environ[i];
		}
		new_env[len - 1] = NULL;
	}
	return (1);
}
