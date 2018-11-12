/**
 * _strncpy - copies a string
 * @dest: buffer to copy to.
 * @src: string to copy.
 * @n: if there is no null bites in the first n of src,
 *	string in dest will not be null-terminated
 * Return: (Success)
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
