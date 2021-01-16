#include "../apue.h"

int main(void)
{
	printf("uid = %d, git = %d\n", getuid(), getgid());
	exit(0);
}
