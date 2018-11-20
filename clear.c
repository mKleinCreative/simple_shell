#include "shell.h"

/**
 * clear - clears command prompt and waits
 * creates the shell process
 * @argv: command line input to send to clear
 * @my_envp: parsed environment path
 * fflushes at end to make sure nothing is in the stream
 */
void clear(char **argv __attribute__((unused)), char **my_envp)
{
	(void)my_envp;
	if (fork() == 0)
	{
		exit(1);
	} else
	{
		wait(NULL);
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "(╯°□°)╯︵ ┻━┻ ===| ", 34);
	fflush(stdout);
}
