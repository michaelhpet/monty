/**
 * nan - checks if a string contains non-digit characters
 * @s: string to parse
 * Return: 0 if all chars are digits, 1 otherwise
*/
int nan(char *s)
{
	int i = 0;

	while (*s)
	{
		if (*s == '-' && i == 0)
		{
			s++, i++;
			continue;
		}

		if (*s < 48 || *s > 57)
			return (1);
		s++, i++;
	}

	return (0);
}
