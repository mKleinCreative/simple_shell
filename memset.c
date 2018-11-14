#include "shell.h"
/**
 * _memset - fills memory with a constant byte
 * @s: memory area pointed to.
 * @b: byte to fill memory with.
 * @n: size of memory area to fill
 * Return: pointer to s
 */
char *_memset(void *s, int b, size_t n)
{
	unsigned char *p;

	p = s;
	while (n--)
		*p++ = (unsigned char)b;
	return (s);
}
