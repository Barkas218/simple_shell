#include "holberton.h"
/**
 * _strcat - concatenates two strings
 * @str1: first string
 * @str2: second string to be concatenated
 * Return: pointer to the concatenated string
 */
char *_strcat(char *str1, char *str2)
{
	char *concatstring;
	int len1 = _strlen(str1), len2 = _strlen(str2), iterator1, iterator2;

	concatstring = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concatstring == NULL)
	{
		printf("Error: impossible to allocate memory");
		exit(98);
	}
	for (iterator1 = 0; str1[iterator1] != '\0'; iterator1++)
	{
		concatstring[iterator1] = str1[iterator1];
	}
	for (iterator2 = 0; str2[iterator2] != '\0'; iterator2++)
	{
		concatstring[iterator1 + iterator2] = str2[iterator2];
	}
	concatstring[iterator1 + iterator2] = '\0';
	return (concatstring);
}
