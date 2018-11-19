#include "shell.h"

/**
 * clear - clears command prompt and waits
 * @argv: command line input to send to clear
 * @my_envp: parsed environtment path.
 */
void clear(char **argv, char **my_envp)
{
	if (fork() == 0)
	{
		execve("/usr/bin/clear", argv, my_envp);
		exit(1);
	} else
	{
		wait(NULL);
	}
	write(STDOUT_FILENO, "\n(╯°□°)╯︵ ┻━┻ ===| ", 35);
	fflush(stdout);
}
