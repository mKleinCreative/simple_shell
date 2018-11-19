/**
 *  _strchr - locates character c in string s
 * @s: string to search for c in.
 * @c: character to find.
 * Return: pointer to s or NULL if not found
 */

char *_strchr(char *s, char c)
{
	for (; *s != '\0'; ++s)
	{
		if (*s == c)
			return ((char *) s);
	}
	return ('\0');
}

