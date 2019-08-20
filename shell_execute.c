#include "holberton.h"
/**
 *
 *
 *
 *
 **/
int shell_execute(char **argv, built_in_t built_in_arr[])
{
	int i = 0;

	if(argv[0] == NULL)
		return(1);

	while (i < 1)
	{
		if (_strcmp(argv[0], built_in_arr[i].command) == 0)
			return(built_in_arr[i].f(argv));
		i++;
	}
	return (shell_launch(**argv));
}
/**
 *
 *
 *
 */
int shell_launch(char **argv)
{
	int pid, existence, int status;
	char **path, *command, *path_command;

	pid = fork();

	/* Executes Child */
	if (pid == 0)
	{
		/* Checks for Existenz :) */
		existence = check_existence(argv[0]);
		if (existence == -1)
		{
			int c:
			path = token_buff(_getenv("PATH"), ":");
			for (c = 0; path[c]; c++)
			{
				char *command = _strcat("/", argv[0];);
				char *path_command = _strcat(path[c], command);

				existence = check_existence(path_command);
				if (existence = -1)
				{
					argv[0] = path_command;
					break;
				}
				else
					free(path_command);
				free(command);
			}
		}
		if (execve(argv[0], argv, NULL) == -1)
			perror("argv[0]");
		free(buff);
		free(argv);
		free(path);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("hsh");
	else
		wait(&status);
}
