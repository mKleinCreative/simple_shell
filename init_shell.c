#include "shell.h"

/**
 * handle_signal - Handle signal
 * @signo: signo
 * Return: Nothing
 */
void handle_signal(int signo)
{
	(void)signo;
	write(STDOUT_FILENO, "\n(╯°□°)╯︵ ┻━┻ ===| ", 35);
	fflush(stdout);
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: pointer to array of arguments
 * @envp: pointer to array of envp
 * Return: 0 (Success)
 */

int main(int argc, char *argv[], char *envp[])
{
	int i;
	char *tmp = (char *)malloc(sizeof(char) * 100);
	char c;
	char *pathstr = (char *)malloc(sizeof(char) * 256);
	static char *my_envp[100];
	static char *search_path[10];
	static char *my_argv[100];
	(void)argc;

	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);
	copy_envp(envp, my_envp);
	get_path_string(my_envp, pathstr);
	insert_pathstr_to_search(pathstr, search_path);
	clear(argv, my_envp);
	while (c != EOF)
	{
		c = _getchar();
		switch (c)
		{
			case '\n':
				if (tmp[0] == '\0')
				{
					write(STDOUT_FILENO, "\n(╯°□°)╯︵ ┻━┻ ===| ", 35);
				} else
					run_shell(my_argv, my_envp, search_path, tmp);
				_memset(tmp, 0, 100);
				break;
			default:
				_strncat(tmp, &c, 1);
				break;
		}
	}
	free(pathstr);
	for (i = 0; my_envp[i] != NULL; i++)
		free(my_envp[i]);
	for (i = 0; i < 10; i++)
		free(search_path[i]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
