#include "shell.h"

void execute(char **argv)
{
	pid_t pid;
	int status;
	(void)search_path;

	if ((pid = fork()) < 0)
	{
		write(STDOUT_FILENO, "*** ERROR: forking child process failed\n", 48);
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) < 0)
		{
			write(STDERR_FILENO, "*** ERROR: exec failed\n", 24);
			exit(1);
		}
	}
	else
	{
		while (wait(&status) != pid)
			;
	}
}
