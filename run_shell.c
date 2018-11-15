#include "shell.h"

/**
 * run_shell - compiles the command to run then executes the system process
 * @my_argv: argv input from init_shell
 * @my_envp: environment path from os
 * @search_path: tokenized paths to search through for commands
 * @tmp: input from STDIN stream
 */

void run_shell(char **my_argv, char **my_envp, char **search_path, char *tmp)
{
	int fd;
	char *cmd = (char *)malloc(sizeof(char) * 100);

	if (!cmd)
	{
		free(cmd);
		exit(1);
	}
	fill_argv(tmp, my_argv);
	_strncpy(cmd, my_argv[0], _strlen(my_argv[0]));
	_strncat(cmd, "\0", 1);
	if (_strchr(cmd, '/') == NULL)
	{
		if (attach_path(cmd, search_path) == 0)
		{
			call_execve(cmd, my_envp, my_argv);
		} else
		{
			printf("cmd err === %s\n", cmd);
			write(STDERR_FILENO, "command not found\n", 19);
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
			write(STDERR_FILENO, "command not found\n", 19);
		}
	}
	free_argv(my_argv);
	write(STDOUT_FILENO, "\n(╯°□°)╯︵ ┻━┻ ===| ", 35);
	_memset(cmd, 0, 100);
}
