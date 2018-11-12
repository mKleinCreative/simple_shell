#include "shell.h"

/**
 *
 *
 */

char c = '\0';

void handle_signal(int signo)
{
	(void)signo;
	write(1, "\n(╯°□°)╯︵ ┻━┻ ===| ", 37);
	fflush(stdout);
}
