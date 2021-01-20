#ifndef _APUE_H
# define _APUE_H


# define MAXLINE 4096
# define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
# define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/termios.h>
#include <sys/ioctl.h>

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>


void err_ret(const char *, ...);
void err_sys(const char *, ...) __attribute__((noreturn));
void err_dump(const char *, ...);
void err_quit(const char *, ...);

#endif
