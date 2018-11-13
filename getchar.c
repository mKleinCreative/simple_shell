#include "shell.h"
#ifndef BUFF_SIZE
#define BUFF_SIZE 1024
#endif
int _getchar(void)
{
    static char buff[BUFF_SIZE];
    static char *chr;
    static int pos = 0;  /* New static variable to track position */
    static int ret = 0;  /* Changed this to static */

    if (pos >= ret) { /* if all data in buffer has been returned */
            if ((ret = read(STDIN_FILENO, buff, BUFF_SIZE)) > 0)
            {
                    chr = buff;
                    pos = 0;
                    return *(chr + pos++); /* return one char and update pos */
            } else {  /* if no more to read from stdin */
                    return EOF;
            }
    } else { /* if data still in buffer */
            return *(chr + pos++); /* return one char and update pos */
    }
}
