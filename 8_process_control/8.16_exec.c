#include "../apue.h"
#include <sys/wait.h>

char *argv[] = {"myarg1", "MYARG2", NULL};
char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL };

int main(void)
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		if (execle("/Users/kosuketakami/.local/bin/echoall", "echoall", "myarg1", "MYARG2", (char *)0, env_init) < 0)
				err_sys("execle error");
		//if (execve("/Users/kosuketakami/work/github/apue/8_process_control/echoall", argv, env_init) < 0)
		//	err_sys("execve error");
	}

	if (waitpid(pid, NULL, 0) < 0)
		err_sys("wait error");

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		if (execlp("echoall", "echoall", "only 1 arg", (char*)0) < 0)
			err_sys("execlp error");
	}
	exit(0);
}
