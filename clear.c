#include "shell.h"

/**
 * clear - clears command prompt and waits
 * @argv: command line input to send to clear
 * @my_envp: parsed environtment path.
 */
void clear(char **argv __attribute__((unused)), char **my_envp __attribute__((unused)))
{
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
