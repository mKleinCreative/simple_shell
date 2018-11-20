#include "shell.h"

/**
 * run_shell - compiles the command to run then executes the system process
 * @my_argv: argv input from init_shell
 * @my_envp: environment path from os
 * @search_path: tokenized paths to search through for commands
 * tokenized version of environment path
 * @tmp: input from STDIN stream
 */

void run_shell(char **my_argv, char **my_envp, char **search_path, char *tmp)
{
	int fd, i = 0;
	char *cmd;

	cmd = (char *) malloc(sizeof(char) * 100);
	if (!cmd)
		exit(1);
	fill_argv(tmp, my_argv);
	if (my_argv[i][0] == 0)
	{
		while (my_argv[i][0] == 0)
			i++;
	}
	_strncpy(cmd, my_argv[i], _strlen(my_argv[i]));
	_strncat(cmd, "\0", 1);
	if (_strchr(cmd, '/') == NULL)
	{
		if (attach_path(cmd, search_path) == 0)
		{
			call_execve(cmd, my_envp, my_argv);
		} else
		{
			write(STDERR_FILENO, cmd, _strlen(cmd));
			write(STDERR_FILENO, "No such file or directory\n", 27);
		}
	} else
	{
		fd = open(cmd, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			call_execve(cmd, my_envp, my_argv);
		} else
		{
			write(STDERR_FILENO, cmd, _strlen(cmd));
			write(STDERR_FILENO, "No such file or directory\n", 27);
			write(STDERR_FILENO, " not found\n", 12);
		}
	}
	free_argv(my_argv);
	free(cmd);
}
