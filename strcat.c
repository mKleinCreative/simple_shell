/**
 * _strcat - concatenates two strings
 * @dest: string to concatenate to
 * @src: ascii code to add on to dest
 * Return: new string provided
 */
char *_strcat(char *dest, int src)
{
	int destLength;

	src = (char)src;
	destLength = 0;
	while (dest[destLength] != '\0')
		destLength++;
	dest[destLength] = src;
	dest[destLength + 1] = '\0';
	return (dest);
}
