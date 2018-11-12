#include <stdlib.h>

/**
 * _strncat - concates 2 strings with n as limiter
 * @dest: string to concatenate to
 * @src: string to concatenate from
 * @n: how many bytes to take from src
 * Return: mutated dest string
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_len, i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
