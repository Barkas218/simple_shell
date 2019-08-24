#include "holberton.h"
/**
 * _setenv - sets a new enviromental variable
 * @argv: pointer to the input commands
 * Return: 1 on success
 */
int _setenv(char **argv)
{
	int i = 0, exist = 0, len = 0;
	char *copy, *tok = 0, *val = 0;
	char **new_env;

	while (environ[len])
		len++;
	while (environ[i])
	{
		copy = _strdup(environ[i]);
		tok = _strtok(copy, "=");

		if (!_strcmp(argv[1], tok))
		{
			tok = _strcat(tok, "=");
			val = _strcat(tok, argv[2]);
			environ[i] = tok;
			exist = 1;
			free(tok);
			free(copy);
			free(val);
			break;
		}
		i++;
		free(copy);
	}
	if (!exist)
	{
		tok = _strcat(argv[1], "=");
		tok = _strcat(tok, argv[2]);
		new_env = malloc(sizeof(char *) * (len + 1));
		for (i = 0; i < len; i++)
			new_env[i] = environ[i];
		new_env[len] = tok;
		new_env[len + 1] = NULL;
		environ = new_env;
	}
	return (0);
}
