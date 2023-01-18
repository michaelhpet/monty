/**
 * nan - checks if a string contains non-digit characters
 * @s: string to parse
 * Return: if all chars are digits, 1 otherwise
*/
int nan(char *s)
{
	int i = 0;

	while (*s)
	{
		if (*s == '-' && i == 0)
			continue;

		if (*s < 48 || *s > 57)
			return (1);
		s++;
	}

	return (0);
}
