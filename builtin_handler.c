#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
#include <string.h>
#include <unistd.h>

/**
 * builtin_handler - Handles the execution of built in functions
 * @cmd: the commnd the user is attempting to run
 * @envp: The environment variables
 *
 * Return: 1 if a builtin was found and ran, 0 if not
 */
int builtin_handler(char *cmd, char *envp[])
{
	char **parsed_cmd;

	parsed_cmd = cmd_parser(cmd);

	if (_strcmp(parsed_cmd[0], "env") == 0)
	{
		print_env(envp);
		return (1);
	}
	else
	if (_strcmp(parsed_cmd[0], "exit") == 0)
	{
		exit(1);
		return (1);
	}
	else
	if (_strcmp(parsed_cmd[0], "cd") == 0)
	{

		if (change_directory(parsed_cmd, envp) == 1)
			return (1);

		return (0);
	}

	return (0);
}

/**
 * find_home_dir - Finds the home directory for use in cd
 * @envp: The variables to parse through
 *
 * Return: The home directory
 */
char *find_home_dir(char *envp[])
{
	int loop;
	char *home_path;
	char *rm_home;

	for (loop = 0; envp[loop] != NULL; loop++)
	{
		if (_contains(envp[loop], "HOME=") == 1)
			rm_home = envp[loop];
	}

	home_path = malloc((sizeof(rm_home) - 5) * sizeof(char));

	loop = 5;
	while (rm_home[loop] != '\0')
	{
		home_path[loop - 5] = rm_home[loop];
		loop++;
	}

	return (home_path);
}

/**
 * change_directory - the builtin cd command
 * @parsed_cmd: the command along with parameters
 * @envp: The environment variables
 *
 * Return: 1 on success
 */
int change_directory(char **parsed_cmd, char *envp[])
{
	if (parsed_cmd[1] == NULL)
	{
		chdir(find_home_dir(envp));
		return (1);
	}
	else
	if (_strcmp(parsed_cmd[1], "-") == 0)
		chdir("..");
	else
	if (access(parsed_cmd[1], F_OK) == 0)
		chdir(parsed_cmd[1]);
	else
	if (parsed_cmd[2] != NULL)
	{
		write(1, "bash: cd: too many arguments\n",
		      sizeof("bash: cd: too many argument\n"));
	}
	else
	{
		write(1, "bash: cd: ", sizeof("bash: cd: ") * sizeof(char));
		write(1, parsed_cmd[1], sizeof_string(parsed_cmd[1]));
		write(1, ": No such file or directory\n",
		sizeof(": No such file or directory\n") * sizeof(char));
	}

	return (1);
}

/**
 * print_env - Prints the environment variables
 * @envp: The environment to print
 *
 * Return: 1 on success
 */
int print_env(char *envp[])
{
	int loop;

	loop = 0;
	while (envp[loop] != NULL)
	{
		write(1, envp[loop], sizeof_string(envp[loop]));
		write(1, "\n", 1);
		loop++;
	}
	return (1);
}
