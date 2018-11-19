#include "shell.h"

/**
 * call_execve - Call execve
 * @cmd: command to call.
 * @my_envp: the environment paths
 * @my_argv: the command line arguements
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
		write(STDERR_FILENO, "error executing\n", 17);
		if (i < 0)
		{
			write(STDERR_FILENO, "command not found\n", 19);
			exit(1);
		}
	} else
	{
		wait(NULL);
	}
}
