#include "shell.h"
static char *my_envp[100];
extern char **environ;

void copy_envp(char **envp)
{
	int index = 0;
	for (;envp[index] != NULL; index++)
	{
		my_envp[index] = (char *)malloc(sizeof(char) * (_strlen(envp[index]) + 1));
		_memcpy(my_envp[index], envp[index], _strlen(envp[index]));
	}
}

int attach_path(char *cmd)
{
	char ret[100];
	int index;
	int fd;
	_memset(ret, '0', 100);
	for(index=0; search_path[index] != NULL; index++) {
		_strcpy(ret, search_path[index]);
		_strncat(ret, cmd, _strlen(cmd));
		if((fd = open(ret, O_RDONLY)) > 0) {
			_strncpy(cmd, ret, _strlen(ret));
			close(fd);
			return (0);
		}
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	char *lineptr = NULL;
	size_t size = 0;
	int is_on = 1;
	char *path_str;
	(void)argc;

	path_str = (char *)malloc(sizeof(char) * 256);
	if (!path_str)
	{
		free(path_str);
		exit(1);
	}
	printf("\n envp[0] ==>%s\n", envp[0]);
	printf("\n environ ==>%p\n", environ);
	copy_envp(envp);
	get_path_string(my_envp, path_str);
	insert_path_str_to_search(path_str);
	argv[0] = path_str;
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
		write(STDOUT_FILENO, "(╯°□°)╯︵ ┻━┻ ===| ", 34);
		if (getline(&lineptr, &size, stdin) == EOF)
		    is_on = 0;
		parse(lineptr, argv);
		copy_envp(envp);
		get_path_string(my_envp, lineptr);
		insert_path_str_to_search(lineptr);
		if (strcmp(argv[0], "exit") == 0)
			exit(0);
		execute(argv);
		signal(SIGINT, SIG_IGN);
		signal(SIGINT, handle_signal);
	}
	free(path_str);
	free(lineptr);
	return (0);
}
