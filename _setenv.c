#include "holberton.h"

int _setenv(char **argv)
{
	int i = 0, exist = 0, len = 0;
	char *copy, *tok;

	while (environ[len])
		len++;

	while (environ[i])
	{
		copy = _strdup(environ[i]);
		tok = strtok(copy, "=");

		if (!_strcmp(argv[1], tok))
		{
			tok = strcat(tok, "=");
			tok = strcat(tok, argv[2]);
			environ[i] = tok;

			exist = 1;
		}
		i++;
		free(copy);
	}

	if (!exist)
	{
		
	}

	return (0);
}
