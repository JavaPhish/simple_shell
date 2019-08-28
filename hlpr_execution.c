#include <stdio.h>
#include <stdlib.h>
#include "sandbox.h"
#include <string.h>

/**
 * cmd_parser - seperates each parameter into a slot in an array
 * @cmd_to_parse: The command for parse (for ex. "Ls - l")
 *
 * Return: The 2d array for execution
 */
char **cmd_parser(char *cmd_to_parse)
{
	char **parsed_command;
	char *counter, *row_alloc, *tok_cmd, *ptr_origin;
	int loop, byte_to_alloc;

	counter = malloc(sizeof_string(cmd_to_parse));
	ptr_origin = counter;
	_strcpy(counter, cmd_to_parse);
	counter = strtok(counter, " ");
	for (loop = 0; counter != NULL; loop++)
		counter = strtok(NULL, " ");
	loop++;
	parsed_command = malloc(sizeof(char *) * loop);
	row_alloc = malloc(sizeof_string(cmd_to_parse));
	ptr_origin = row_alloc;
	_strcpy(row_alloc, cmd_to_parse);
	row_alloc = strtok(row_alloc, " ");
	for (loop = 0; row_alloc != NULL; loop++)
	{
		byte_to_alloc = 0;
		while (row_alloc[byte_to_alloc] != '\0')
			byte_to_alloc++;
		parsed_command[loop] = malloc(byte_to_alloc + 1);
		row_alloc = strtok(NULL, " ");
	}
	tok_cmd = malloc(sizeof_string(cmd_to_parse));
	ptr_origin = tok_cmd;
	_strcpy(tok_cmd, cmd_to_parse);
	tok_cmd = strtok(tok_cmd, " ");
	for (loop = 0; tok_cmd != NULL; loop++)
	{
		_strcpy(parsed_command[loop], (char *)tok_cmd);
		tok_cmd = strtok(NULL, " ");
	}
	free(ptr_origin);
	free(tok_cmd);
	parsed_command[loop] = NULL;
	free(row_alloc);
	free(counter);
	return (parsed_command);
}

/**
 * find_path - Finds the full PATH variable and returns its contents
 * @env: The environment variables from main
 *
 * Return: The contents of PATH=
 */
char *find_path(char *env[])
{
	int loop;
	char *bin_path;

	if (!env)
		return (NULL);

	for (loop = 0; env[loop] != NULL; loop++)
	{
		if (_contains(env[loop], "PATH")
		&& _contains(env[loop], "_PATH") != 1
		&& _contains(env[loop], "WPATH") != 1)
		{
			bin_path = malloc(sizeof(env[loop]));
			bin_path = env[loop];
		}
	}

	bin_path = strtok(bin_path, "=");
	_strcpy(bin_path, strtok(NULL, "="));

	return (bin_path);
}

/**
 * str_concat - Concatenates two strings into one
 * @s1: the first string
 * @s2: The second string
 *
 * Return: a pointer to the concatenated strings
 */
char *str_concat(char *s1, char *s2)
{
	int str1Size, str2Size, loop;
	char *arr;

	str1Size = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(sizeof(char));
		s2[0] = '\0';
	}
	while (s1[str1Size] != '\0')
		str1Size++;
	str2Size = 0;
	while (s2[str2Size] != '\0')
		str2Size++;
	str2Size++;

	arr = malloc((str1Size + str2Size) * sizeof(char));

	if (!arr)
		return (NULL);

	for (loop = 0; loop < (str1Size + str2Size - 1); loop++)
	{
		if (loop > str1Size - 1)
			arr[loop] = s2[loop - str1Size];
		else
			arr[loop] = s1[loop];
	}

	return (arr);
}

/**
 * free_2d_array - Used for simplified freeing of 2d arrays
 * @arr: The pointer to free
 */
void free_2d_array(char **arr)
{
	int loop;

	loop = 0;
	while (arr[loop] != NULL)
		free(arr[loop]);

	free(arr);
}
