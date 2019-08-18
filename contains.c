/**
 * _contains - Checks if a string contains a given set of chars
 * @str: The string to check through
 * @keyword: The key word to check for
 *
 * Return: 1 if the keyword is in the string, 0 if not (Or edge case)
 */
int _contains(char *str, char *keyword)
{
	int loop, check_loop;

	check_loop = 0;

	if (!str)
		return (0);
	if (!keyword)
		return (0);

	for (loop = 0; str[loop] != '\0'; loop++)
	{
		if (keyword[check_loop] == '\0')
			return (1);

		if (str[loop] == keyword[check_loop])
		{
			check_loop++;
		}
		else
		{
			check_loop = 0;
		}


		if (str[loop + 1] == '\0' && keyword[check_loop] == '\0')
			return (1);

	}

	return (0);

}
