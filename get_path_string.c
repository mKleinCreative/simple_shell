#include "shell.h"
static char *search_path[10];

void get_path_string(char **tmp_envp, char *bin_path)
{
	int count = 0;
	char *tmp;
	while(1) {
		tmp = _strstr(tmp_envp[count], "PATH");
		if(tmp == NULL) {
			count++;
		} else {
			break;
		}
	}
        strncpy(bin_path, tmp, _strlen(tmp));
}

void insert_path_str_to_search(char *path_str)
{
	int index=0;
	char *tmp = path_str;
	char ret[100];

	while(*tmp != '=')
		tmp++;
	tmp++;

	while(*tmp != '\0') {
		if(*tmp == ':') {
			_strncat(ret, "/", 1);
			search_path[index] = (char *) malloc(sizeof(char) * (_strlen(ret) + 1));
			_strncat(search_path[index], ret, _strlen(ret));
			_strncat(search_path[index], "\0", 1);
			index++;
			bzero(ret, 100);
		} else {
			_strncat(ret, tmp, 1);
		}
		tmp++;
	}
}
