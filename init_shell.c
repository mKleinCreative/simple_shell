#include "shell.h"

extern int errno;

/**
 * handle_signal - Handle signal
 * @signo: signo
 * Return: Nothing
 */
void handle_signal(int signo)
{
	(void)signo;
	write(STDOUT_FILENO, "\n(╯°□°)╯︵ ┻━┻ ===| ", 35);
	fflush(stdout);
}


/**
 * insert_pathstr_to_search - Insert pathstring to search
 * @pathstr: pathstr
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

/**
 * fill_argv - Fill argv
 * @tmp_argv: temporary argv
 * Return: Nothing
 */
void fill_argv(char *tmp_argv, char **my_argv)
{
	char *copy_argv;
	int index = 0;
	char ret[100];

	copy_argv = tmp_argv;
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
	_strncpy(my_argv[index], ret, _strlen(ret));
	_strncat(my_argv[index], "\0", 1);
}

/**
 * copy_envp - Copy envp
 * @envp: double pointer to envp
 * Return: Nothing
 */
void copy_envp(char **envp, char **my_envp)
{
	int index = 0;
	for (;envp[index] != NULL; index++)
	{
		my_envp[index] = (char *)malloc(sizeof(char) * (_strlen(envp[index]) + 1));
		_memcpy(my_envp[index], envp[index], _strlen(envp[index]));
	}
}

/**
 * call_execve - Call execve
 * @cmd: cmd
 * Return: Nothing
 */
void call_execve(char *cmd, char **my_envp, char **my_argv)
{
	int i;

	write(STDOUT_FILENO, cmd, _strlen(cmd));
	write(STDOUT_FILENO, "\n", 1);
	if (fork() == 0)
	{
		i = execve(cmd, my_argv, my_envp);
		write(STDERR_FILENO, "error executing\n", 18);
		if (i < 0)
		{
			write(STDERR_FILENO, "command not found\n", 18);
			exit(1);
		}
	} else
	{
		wait(NULL);
	}
}

/**
 * get_pathstring - Get pathstring
 * @tmp_envp: tmp_envp
 * @bin_path: bin_path
 * Return: Nothing
 */
void get_pathstring(char **tmp_envp, char *bin_path)
{
	int count = 0;
	char *tmp;
	while(1)
	{
		tmp = _strstr(tmp_envp[count], "PATH");
		if (tmp == NULL)
		{
			count++;
		} else
		{
			break;
		}
	}
        _strncpy(bin_path, tmp, _strlen(tmp));
}

/**
 * attach_path - Attach the path
 * @cmd: cmd
 * Return: 0
 */
int attach_path(char *cmd, char **search_path)
{
	char ret[100];
	int index;
	int fd;
	_memset(ret, 0, 100);
	for (index = 0; search_path[index] != NULL; index++)
	{
		_strncpy(ret, search_path[index], _strlen(ret));
		_strncat(ret, cmd, _strlen(cmd));
		if ((fd = open(ret, O_RDONLY)) > 0)
		{
			_strncpy(cmd, ret, _strlen(ret));
			close(fd);
			return (0);
		}
	}
	return (0);
}

/**
 * free_argv - Free argv
 * Return: Nothing
 */
void free_argv(char **my_argv)
{
	int index;
	for (index=0; my_argv[index] != NULL; index++)
	{
		_memset(my_argv[index], 0, _strlen(my_argv[index]) + 1);
		my_argv[index] = NULL;
		free(my_argv[index]);
	}
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: pointer to array of arguments
 * @envp: pointer to array of envp
 * Return: 0 (Success)
 */
int main(int argc, char *argv[], char *envp[])
{
	char c;
	int i, fd;
	char *tmp = (char *)malloc(sizeof(char) * 100);
	char *pathstr = (char *)malloc(sizeof(char) * 256);
	static char *my_envp[100];
	static char *search_path[10];
	static char *my_argv[100];
	char *cmd = (char *)malloc(sizeof(char) * 100);
	(void)argc;

	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);

	copy_envp(envp, my_envp);
	get_pathstring(my_envp, pathstr);
	insert_pathstr_to_search(pathstr, search_path);

	if (fork() == 0)
	{
		execve("/usr/bin/clear", argv, my_envp);
		exit(1);
	} else
	{
		wait(NULL);
	}
	/* print crab */
	write(STDOUT_FILENO, "   /\\ \n", 9);
	write(STDOUT_FILENO, " ( /   @ @    ()   welcome\n", 29);
	write(STDOUT_FILENO, "  \\  __| |__  /     to\n", 23);
	write(STDOUT_FILENO, "   -/    \"    \\    soft\n", 24);
	write(STDOUT_FILENO, "  /-|         |-\\  shell\n", 26);
	write(STDOUT_FILENO, " / /-\\        /-\\\\ \n", 21);
	write(STDOUT_FILENO, "   / /-`---'-\\ \\ \n", 20);
	write(STDOUT_FILENO, "   /         \\ \\ \n\n", 21);
	write(STDOUT_FILENO, "\n(╯°□°)╯︵ ┻━┻ ===| ", 35);
	fflush(stdout);
	while(c != EOF)
	{
		c = _getchar();
		switch(c)
		{
			case '\n': if (tmp[0] == '\0')
				{
					write(STDOUT_FILENO, "\n(╯°□°)╯︵ ┻━┻ ===| ", 35);
				} else
				{
					fill_argv(tmp, my_argv);
					_strncpy(cmd, my_argv[0], _strlen(my_argv[0]));
					_strncat(cmd, "\0", 1);
					if (index(cmd, '/') == NULL)
					{
						if (attach_path(cmd, search_path) == 0)
						{
							call_execve(cmd, my_envp, my_argv);
						} else
						{
							write(STDERR_FILENO, "command not found\n", 15);
						}
					} else
					{
						if ((fd = open(cmd, O_RDONLY)) > 0)
						{
							close(fd);
							call_execve(cmd, my_envp, my_argv);
						} else
						{
							write(STDERR_FILENO, "command not found\n", 15);
						}
					}
					free_argv(my_argv);
					write(STDOUT_FILENO, "\n(╯°□°)╯︵ ┻━┻ ===| ", 35);
					_memset(cmd, 0, 100);
				}
				_memset(tmp, 0, 100);
				break;
			default: _strncat(tmp, &c, 1);
				break;
		}
	}
	free(tmp);
	free(cmd);
	free(pathstr);
	for (i = 0; my_argv[i] != NULL; i++)
		free(my_argv[i]);
	for (i = 0; my_envp[i] != NULL; i++)
		free(my_envp[i]);
	for (i = 0; i < 10; i++)
		free(search_path[i]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
