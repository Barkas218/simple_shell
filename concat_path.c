#include "holberton.h"
/**
 * concat_path - concatenates the macro PATH with the
 * argv[0] command.
 * @command: from the commandline to be concatenated
 * Return: pointer to the concatenated string
 */
char *concat_path(char *command)
{
	char *concatstring;
	int len, iterator1, iterator2;

	for (len = 0; command[len] != '\0'; len++)
		;
	concatstring = malloc(sizeof(char) * (len + 6));
	if (concatstring == NULL)
	{
		printf("Error: impossible to allocate memory");
		exit(98);
	}
	for(iterator1 = 0; EXE_PATH[iterator1] != '\0'; iterator1++)
	{
		concatstring[iterator1] = EXE_PATH[iterator1];
	}
	for(iterator2 = 0; command[iterator2] != '\0'; iterator2++)
	{
		concatstring[iterator1 + iterator2] = command[iterator2];
	}
	concatstring[iterator1 + iterator2] = '\0';
	return(concatstring);
}
