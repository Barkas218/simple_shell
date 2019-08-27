#include "holberton.h"
/**
 *
 *
 *
 *
*
int _getchar(void)
{
	char buff[1];
	size_t buffsize = 1;
	int read = 0;

	read = read(STDIN_FILENO, &buff, buffsize);
	if (read == EOF)
	{
		perror("Error");
		return (EOF)
	}
	return (buff[0]);
}
**
 *
 *
 *
 *
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{

}*/
