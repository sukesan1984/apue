#include <unistd.h>
int ft_write(int fd, char *str, int size)
{
	int res;

	res = 0;
	while (*str)
	{
		res += write(fd, str++, 1);
	}
	return (res);
}
