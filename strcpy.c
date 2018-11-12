#include <stdio.h>
/**
 * _strcpy - copies a string to the buffer
 * @dest: buffer destination to copy to.
 * @src: source string to copy from.
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}

