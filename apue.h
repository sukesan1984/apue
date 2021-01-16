#ifndef _APUE_H
# define _APUE_H


# define MAXLINE 4096
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

#endif
