#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "holberton.h"

/**
 * main - contains the loop and input handler for the rest of the shell
 * @argc: Casted to void(Unused)
 * @argv: Casted to void(Unused)
 * @envp: Used to find the path containing system commands
 *
 * Return: 1 on success, 0 on screw up
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buffer = NULL;
	char *strtok_address = NULL;
	size_t buffer_size = 0;
	int chars_printed = 0;
	pid_t pid;
	int status = 0;
	(void)argc;

	while (chars_printed != EOF)
	{
		if (isatty(STDIN_FILENO) == 1 && isatty(STDOUT_FILENO))
			write(1, "$ ", sizeof(char) * 2);

		chars_printed = getline(&buffer, &buffer_size, stdin);

		strtok_address = buffer;
		buffer = strtok(buffer, "\n");
		if (buffer != NULL)
		{
			if (builtin_handler(buffer, envp) == 0)
			{
				pid = fork();

				if (pid == 0 && chars_printed != EOF)
					execution_handler(buffer, envp, argv[0]);
				else
					do
						waitpid(pid, &status, WUNTRACED);
					while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}
		}
	}

	free(strtok_address);
	exit(0);

	return (0);
}
