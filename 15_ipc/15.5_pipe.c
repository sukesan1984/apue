#include "../apue.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
	char buf[4096];
	int fds[2];
	int res;
	int n;
	pid_t pid;

	res = pipe(fds);
	if (res < 0)
	{
		printf("pipe error\n");
		return (1);
	}
	if ((pid = fork()) < 0)
		err_sys("fork error\n");
	else if (pid > 0)
	//親から子へ送る場合
	{
		//親側は出力を閉じる
		close(fds[0]);
		write(fds[1], "hoge\n", 5);
	}
	else
	{
		close(fds[1]);
		//sleep(5);
		n = read(fds[0],  buf, 4096);
		//printf("%s\n", buf);
		write(STDOUT_FILENO, buf, n);
	}
	return (0);
}
