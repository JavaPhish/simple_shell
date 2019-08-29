#include "holberton.h"

/**
 * _strcpy - Non destructively copies a string
 * @dest: The pointer to copy to
 * @src: THe pointer to copy
 *
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *pdest = dest;
	char *src1 = src;

	while (*src1 != '\0')
	{
		*pdest = *src1;
		src1++;
		pdest++;
	}
	*pdest = *src1;
	return (dest);
}


/**
 * sizeof_string - Fetches the exact length of a string
 * @str: The string to evaluate
 *
 * Return: The length of the string
 */
int sizeof_string(char *str)
{
	int size_counter = 0;

	size_counter = 0;
	while (str[size_counter] != '\0')
		size_counter++;

	size_counter++;

	return (size_counter);
}

/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 *
 * Return: The difference in the strings
 */
int _strcmp(char *s1, char *s2)
{
	int loop = 0;

	loop = 0;
	while (loop > -1)
	{
		if (s1[loop] == '\0' && s2[loop] == '\0')
			return (0);

		if (s1[loop] != s2[loop])
		{
			if (s1[loop] > s2[loop])
				return (s1[loop] - s2[loop]);
			else
				return (-(s2[loop] - s1[loop]));
		}
		loop++;
	}

	return (0);
}

/**
 * _contains - Checks if a string contains a given set of chars
 * @str: The string to check through
 * @keyword: The key word to check for
 *
 * Return: 1 if the keyword is in the string, 0 if not (Or edge case)
 */
int _contains(char *str, char *keyword)
{
	int loop = 0;
	int check_loop = 0;

	check_loop = 0;

	if (str[0] == '\0')
		return (0);

	if (keyword[0] == '\0')
		return (0);

	if (!str)
		return (0);
	if (!keyword)
		return (0);

	for (loop = 0; str[loop] != '\0'; loop++)
	{
		if (keyword[check_loop] == '\0')
			return (1);

		if (str[loop] == keyword[check_loop])
			check_loop++;
		else
			check_loop = 0;

		if (str[loop + 1] == '\0' && keyword[check_loop] == '\0')
			return (1);
	}
	return (0);
}
