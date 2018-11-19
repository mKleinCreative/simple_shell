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

int main(int argc __attribute__((unused)), char *argv[], char *envp[])
{
	int i, c;
	char *pathstr, *tmp;
	static char *my_envp[100] *search_path[10] *my_argv[100];

	tmp = (char *)malloc(sizeof(char) * 100);
	pathstr = (char *)malloc(sizeof(char) * 256);
	if (!pathstr)
	{
		free(pathstr);
		exit(1);
	}
	if (!tmp)
	{
		free(tmp);
		exit(1);
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);
	copy_envp(envp, my_envp);
	get_path_string(my_envp, pathstr);
	insert_pathstr_to_search(pathstr, search_path);
	clear(argv, my_envp);
	while ((c = _getchar) != EOF)
	{
		if (c == '\n')
		{
			if (tmp[0] == '\0')
			{
				write(STDOUT_FILENO, "(╯°□°)╯︵ ┻━┻ ===| ", 34);
			} else
			{
				run_shell(my_argv, my_envp, search_path, tmp);
				write(STDOUT_FILENO, "(╯°□°)╯︵ ┻━┻ ===| ", 34);
			}
			_memset(tmp, 0, 100);
		} else
		{
				_strncat(tmp, &c, 1);
		}
	}
	free(pathstr);
	for (i = 0; my_envp[i] != NULL; i++)
		free(my_envp[i]);
	for (i = 0; search_path[i] != '\0'; i++)
		free(search_path[i]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
