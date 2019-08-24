#include "holberton.h"
/**
 * shell_execute - executes the built in commands
 * @argv: pointer to the argv
 * @built_in_arr: pointer to the struct with built in comm
 * Return: 1 on success
 **/
int shell_execute(char **argv, built_in_t built_in_arr[])
{
	int i = 0;

	if (argv[0] == NULL)
		return (1);

	while (i < 5)
	{		
		if (_strcmp(argv[0], built_in_arr[i].command) == 0)
		{
			return (built_in_arr[i].f(argv));
		}
		i++;
	}
	return (shell_launch(argv));
}
/**
 * shell_launch - creates the process to execute shell commands
 * @argv: pointer to argv
 * Return: 1 on success
 */
int shell_launch(char **argv)
{
	int pid, existence, status;
	char **path, *command, *path_command;
	char *env = NULL;

	pid = fork();
	if (pid == 0)
	{
		existence = check_existence(argv[0]);
		if (existence == -1)
		{
			int c;

			env = getenv("PATH");
			path = token_buff(env, ":");
			for (c = 0; path[c]; c++)
			{
				command = _strcat("/", argv[0]);
				path_command = _strcat(path[c], command);
				existence = check_existence(path_command);
				if (existence != -1)
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
			perror("Error");
		free(argv[0]);
		free(argv);
		free(path);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("hsh");
	else
		wait(&status);
	return (status);
}
