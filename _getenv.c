#include "holberton.h"
/**
 * _getenv - gets the environ variable
 * @name: name of the env variabl to look for
 * Return: pointer to the env variable
 **/
char *_getenv(char *name)
{
	int i = 0;
	char *token, *deli = "=";
	char *dup;

	while (environ[i] != NULL)
	{
		dup = _strdup(environ[i]);
		token = strtok(environ[i], deli);
		if (_strcmp(token, name) == 0)
		{
			token = strtok(NULL, deli);
			environ[i] = _strcpy(environ[i], dup);
			free(dup);
			return (token);
		}
		environ[i] = _strcpy(environ[i], dup);
		free(dup);
		i++;
	}
	return (NULL);
}
