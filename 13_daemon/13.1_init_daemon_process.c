#include "../apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

void daemonize(const char *cmd)
{
	int 	i, fd0, fd1, fd2;
	pid_t	pid;
	struct rlimit rl;
	struct sigaction sa;

	/*
	* ファイル作成マスクをクリア
	*/
	umask(0);

	/*
	 * ファイル記述子の最大個数を取得
	 */
	if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
		err_quit("%s: can't get file limit", cmd);

	/*
	 * 制御端末から切断するためにセッションリーダになる
	 */
	if ((pid = fork()) < 0)
		err_quit("%s: can't fork", cmd);
	else if (pid != 0) /* 親側 */
		exit(0);
	setsid();

	/*
	 * 以降のオープンで制御端末を割り付けられないようにする
	 */
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0)
		err_quit("%s: can't ignore SIGHUP", cmd);
	if ((pid = fork()) < 0)
		err_quit("%s: can't fork", cmd);
	else if (pid != 0) /* 親側 */
		exit(0);
	/*
	 * カレントワーキングディレクトリをルートに変更し、
	 * ファイルシステムのアンマウントを邪魔しない
	 */
	if (chdir("/") < 0)
		err_quit("%s: can't change directory to /", cmd);

	/*
	 * オープンしてあるファイル記述子をクローズ
	 */
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);

	/*
	 * ログファイルを初期化
	 */
	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
		syslog(LOG_ERR, "unexpected file descriptors %d %d %d",
				fd0, fd1, fd2);
		exit(1);
	}
}
