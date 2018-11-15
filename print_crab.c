#include "shell.h"
/**
 * print_crab - prints the soft shell logo!
 */

void print_crab(void)
{
	write(STDOUT_FILENO, "   /\\ \n", 9);
	write(STDOUT_FILENO, " ( /   @ @    ()   welcome\n", 29);
	write(STDOUT_FILENO, "  \\  __| |__  /     to\n", 23);
	write(STDOUT_FILENO, "   -/    \"    \\    soft\n", 24);
	write(STDOUT_FILENO, "  /-|         |-\\  shell\n", 26);
	write(STDOUT_FILENO, " / /-\\        /-\\\\ \n", 21);
	write(STDOUT_FILENO, "   / /-`---'-\\ \\ \n", 20);
	write(STDOUT_FILENO, "   /         \\ \\ \n\n", 21);
	write(STDOUT_FILENO, "\n(╯°□°)╯︵ ┻━┻ ===| ", 35);
}
