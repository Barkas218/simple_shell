#include "holberton.h"
/**
 *
 *
 *
 *
 **/
char *_getenv(char *name)
{
	int i = 0;
	char *token, *deli = "=";


	while (environ[i] != NULL)
	{
		token = _strtok(environ[i], deli);
		if (_strcmp(token, name) == 0)
		{
			return (_strtok(NULL, deli));
		}
		i++;
	}
	return (NULL);
}
