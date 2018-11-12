/**
 * _strlen - returns the length of a string.
 * @s: string to find the length of.
 * Return: (Success)
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
