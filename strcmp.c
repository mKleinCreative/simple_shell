/**
 * _strcmp - compares two strings.
 * @s1: first string in comparison
 * @s2: second string in comparison
 * Return: (Success)
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; ; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] < s2[i] ? -1 : 1);
		}
		if (s1[i] == '\0')
		{
			return (0);
		}
	}
}

