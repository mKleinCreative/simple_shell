#include "shell.h"
#include <string.h>

static char *my_argv[100], *my_envp[100];
static char *search_path[10];


void parse(char *line, char **argv)
{
	while (*line != '\0')
	{
		while (*line == ' ' || *line == '\t' || *line == '\n')
			*line++ = '\0';
		*argv++ = line;
		while (*line != '\0' && *line != ' ' &&
			*line != '\t' && *line != '\n')
			line++;
	}
	*argv ='\0';
}

void execute(char **argv)
{
	pid_t pid;
	int status;

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

int main(int ac, char **av, char **env)
{
	char *lineptr = NULL;
	size_t size = 0;
	char *argv[64];
	int is_on = 1;
	(void)ac;

	/* print crab */
	write(STDOUT_FILENO, "   /\\ \n", 9);
	write(STDOUT_FILENO, " ( /   @ @    ()   welcome\n", 29);
	write(STDOUT_FILENO, "  \\  __| |__  /     to\n", 23);
	write(STDOUT_FILENO, "   -/    \"    \\    soft\n", 24);
	write(STDOUT_FILENO, "  /-|         |-\\  shell\n", 26);
	write(STDOUT_FILENO, " / /-\\        /-\\\\ \n", 21);
	write(STDOUT_FILENO, "   / /-`---'-\\ \\ \n", 20);
	write(STDOUT_FILENO, "   /         \\ \\ \n\n", 21);
	while (is_on) {
		write(STDOUT_FILENO, " (╯°□°)╯︵ ┻━┻ ===| ", 36);
		if (getline(&lineptr, &size, stdin) == EOF)
		    is_on = 0;
		parse(lineptr, argv);
		if (strcmp(argv[0], "exit") == 0)
			exit(0);
		execute(argv);
		signal(SIGINT, SIG_IGN);
		signal(SIGINT, handle_signal);
		printf("\n");
	}
	free(*argv);
	free(lineptr);
	return (0);
}
