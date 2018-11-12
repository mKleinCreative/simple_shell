#include "shell.h"

/**
 *
 *
 */

char c = '\0';

void handle_signal(int signo)
{
	(void)search_path;
	(void)signo;
	write(STDOUT_FILENO, "\n(╯°□°)╯︵ ┻━┻ ===| ", 36);
	fflush(stdout);
}
