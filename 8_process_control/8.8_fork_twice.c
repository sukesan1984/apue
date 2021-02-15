#include "../apue.h"
#include <sys/wait.h>

int main(void)
{
	pid_t parent;
	pid_t pid;

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		if ((pid = fork()) < 0)
			err_sys("fork error");
		else if (pid > 0)
		{
			sleep(1);
			printf("first child(%ld), parent pid = %ld\n", (long)getpid(), (long)getppid());
			exit(0); // 最初の子
		}
		// 二番目の子（孫）
		// 孫はinitが親になる
		// 以後、動作を続けるが、終了したらinitが状態を見てくれる
		//parent = getpid();
		//printf("parent 1 nanoka?: %d\n", parent);
		sleep(5);
		printf("second child(%ld), parent pid = %ld\n", (long)getpid(), (long)getppid());
		exit(0);
	}
	// 最初の子を待つ
	if (waitpid(pid, NULL, 0) != pid)
		err_sys("waitpid error");
	sleep(10);
	printf("my(%ld), parent pid = %ld\n", (long)getpid(), (long)getppid());
	exit(0);
}
