#include "../apue.h"
#include <pwd.h>


static void my_alarm(int signo)
{
	struct passwd	*rootptr;

	printf("in signal handler\n");
	if ((rootptr = getpwnam("root")) == NULL)
		err_sys("getpwnam(root) error");
}

int main(void)
{
	struct passwd *ptr;

	signal(SIGALRM, my_alarm);
	for (;;) {
		alarm(1);
		if ((ptr = getpwnam("kosuketakami")) == NULL)
			err_sys("getpwnam error");
		if (strcmp(ptr->pw_name, "kosuketakami") != 0)
			printf("return value corrupted!, pw_name = %s\n",
					ptr->pw_name);
		sleep(2);
	}
}
