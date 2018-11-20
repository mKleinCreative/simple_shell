#include "shell.h"

/**
 * free_argv - Free argv
 * @my_argv: compiled command line input.
 * Return: Nothing
 */
void free_argv(char **my_argv)
{
	int index;

	for (index = 0; my_argv[index] != NULL; index++)
	{
		_memset(my_argv[index], 0, _strlen(my_argv[index]) + 1);
		my_argv[index] = NULL;
		free(my_argv[index]);
	}
}
