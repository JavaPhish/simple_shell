#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"
#include <string.h>

/**
 * execution_handler - Executes the given command
 * @cmd: The command passed on by the user (not ready for execve)
 * @env: The environment variable from origin main
 *
 * Return: 1 on success, 0 if failure;
 */
int execution_handler(char *cmd, char **env)
{
	char *bin_path = find_path(env);
	char *path_with_cmd, *path_tokenizer, *path_to_free;
	char **arr_of_args;
	int path_attempts;

	arr_of_args = cmd_parser(cmd);
 /*
 * Attempts to execve with every file within the path
 * once it find the correct one (Correct one being the one containing
 * the requested command) it runs the command
 */
	path_tokenizer = strtok(bin_path, ":");
	path_to_free = path_tokenizer;
	path_attempts = 0;

	path_with_cmd = malloc(sizeof(cmd));
	_strcpy(path_with_cmd, cmd);

	while (path_tokenizer != NULL)
	{

		if (access(path_with_cmd, F_OK) == 0)
		{
			execve(path_with_cmd, arr_of_args, NULL);
			free(path_to_free);
			free(path_with_cmd);
			return (1);
		}
		path_with_cmd = str_concat(path_tokenizer, str_concat("/", arr_of_args[0]));
		if (path_attempts != 0)
			path_tokenizer = strtok(NULL, ":");
		path_attempts++;
	}
	write(1, arr_of_args[0], sizeof(arr_of_args));
	write(1, ": command not found\n", sizeof(": command not found\n"));
	free(path_to_free);
	free(path_with_cmd);

	return (0);
}
