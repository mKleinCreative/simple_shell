#include "shell.h"

/**
 * get_path_string - Get pathstring
 * @tmp_envp: tmp_envp
 * @bin_path: bin_path
 * Return: Nothing
 */

void get_path_string(char **tmp_envp, char *bin_path)
{
	int count = 0;
	char *tmp;

	while (1)
	{
		tmp = _strstr(tmp_envp[count], "PATH");
		if (tmp == NULL)
		{
			count++;
		} else
			break;
	}
	_strncpy(bin_path, tmp, _strlen(tmp));
}
