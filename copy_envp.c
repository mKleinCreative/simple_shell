#include "shell.h"

/**
 * copy_envp - Makes a copy of the entire environment path
 * and stores it in an array so we can edit it without
 * affecting actual environment
 * @envp: double pointer to envp
 * @my_envp: array to store copy of envp
 * Return: Nothing
 */

void copy_envp(char **envp, char **my_envp)
{
	int index = 0;

	for (; envp[index] != NULL; index++)
	{
		my_envp[index] = (char *)malloc(sizeof(char) * (_strlen(envp[index]) + 1));
		_memcpy(my_envp[index], envp[index], _strlen(envp[index]));
	}
}
