/**
 * _strcat - concatenates two strings
 * @dest: string to concatenate to
 * @src: string to add on to dest
 * Return: new string provided
 */
char *_strcat(char *dest, char *src)
{
	int destLength, j;

	destLength = 0;
	while (dest[destLength] != '\0')
		destLength++;
	for (j = 0; src[j] != '\0'; j++)
		dest[destLength + j] = src[j];
	dest[destLength + j] = '\0';
	return (dest);
}
