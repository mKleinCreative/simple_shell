#include "shell.h"

/**
 * insert_pathstr_to_search - Tokenizes the different paths and inserts
 * them into a 2-D array
 * @pathstr: pathstr
 * @search_path: 2d array of all possible paths.
 * Return: Nothing
 */

void insert_pathstr_to_search(char *pathstr, char **search_path)
{
	int index = 0;
	char *tmp = pathstr;
	char ret[100];

	while (*tmp != '=')
		tmp++;
	tmp++;

	while (*tmp != '\0')
	{
		if (*tmp == ':')
		{
			_strncat(ret, "/", 1);
			search_path[index] = (char *) malloc(sizeof(char) * (_strlen(ret) + 1));
			_strncat(search_path[index], ret, _strlen(ret));
			_strncat(search_path[index], "\0", 1);
			index++;
			_memset(ret, 0, 100);
		} else
		{
			_strncat(ret, tmp, 1);
		}
		tmp++;
	}
}
