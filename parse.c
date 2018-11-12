#include "shell.h"

void parse(char *line, char **argv)
{
	(void)search_path;
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
