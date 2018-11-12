#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
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
typedef void (*sighandler_t)(int);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
void get_path_string(char **tmp_evnp, char *bin_path);
void insert_path_str_to_search(char *path_str);
void handle_signal (int signo);
char *_memset(char *s, char b, unsigned int n);
int attach_path(char *cmd);
#endif
