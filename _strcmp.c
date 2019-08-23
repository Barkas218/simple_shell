#include "holberton.h"
/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: 0 if match, anything else if they don't match
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, c = 0, greater;
	int len1, len2;

	if (!s1 || !s2)
		return (-1);

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (!len1 || !len2)
		return (-1);

	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] == s2[i])
		{
			c++;
		}
		i++;
	}
	greater = len1 > len2 ? len1 : len2;
	if (c == greater)
		return (0);
	return (-1);
}
