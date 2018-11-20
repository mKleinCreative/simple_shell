#include "shell.h"

char *remove_spaces(char *text);

/**
 * fill_argv - Tokenizes tmp buffer and stores result in my_argv
 * @tmp_argv: stream of data from input to put into argv
 * @my_argv: command line input.
 * Return: Nothing
 */

void fill_argv(char *tmp_argv, char **my_argv)
{
	char *copy_argv;
	int index = 0;
	char ret[100];

	copy_argv = remove_spaces(tmp_argv);
	_memset(ret, 0, 100);
	while (*copy_argv != '\0')
	{
		if (index == 10)
			break;
		if (*copy_argv == ' ')
		{
			if (my_argv[index] == NULL)
				my_argv[index] = (char *)malloc(sizeof(char) * _strlen(ret) + 1);
			else
			{
				_memset(my_argv[index], 0, _strlen(my_argv[index]));
			}
			_strncpy(my_argv[index], ret, _strlen(ret));
			_strncat(my_argv[index], "\0", 1);
			_memset(ret, 0, 100);
			index++;
		} else
		{
			_strncat(ret, copy_argv, 1);
		}
		copy_argv++;
	}
	my_argv[index] = (char *)malloc(sizeof(char) * _strlen(ret) + 1);
	if (!my_argv[index])
		free(my_argv);
	_strncpy(my_argv[index], ret, _strlen(ret));
	_strncat(my_argv[index], "\0", 1);
}
