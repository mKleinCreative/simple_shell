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

	if (fork() == 0)
	{
		i = execve(cmd, my_argv, my_envp);
		if (i < 0)
		{
			write(STDERR_FILENO, cmd, _strlen(cmd));
			write(STDERR_FILENO, ": not found\n", 13);
			exit(1);
		}
	} else
	{
		wait(NULL);
	}
}
