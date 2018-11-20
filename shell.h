#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
/* variables and typedefs */
typedef void (*sighandler_t)(int);
extern int errno;
/* functions */
char *remove_spaces(char *text);
void fill_argv(char *tmp_argv, char **my_argv);
char *_strcat(char *dest, int src);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
void get_path_string(char **tmp_evnp, char *bin_path);
void insert_pathstr_to_search(char *pathstr, char **search_path);
char *_memset(void *s, int b, size_t n);
char *_memcpy(char *dest, char *src, unsigned int n);
int attach_path(char *cmd, char **search_path);
void copy_envp(char **envp, char **my_envp);
int _strcmp(char *s1, char *s2);
void call_execve(char *cmd, char **my_envp, char **my_argv);
int _getchar(void);
void free_argv(char **my_argv);
void print_crab(void);
void clear(char **argv, char **my_envp);
void run_shell(char **my_argv, char **my_envp, char **search_path, char *tmp);
char *_strchr(char *s, char c);
#endif
