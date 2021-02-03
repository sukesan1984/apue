#include <stdio.h>

int main()
{
	char	*path;
	char	buf[4096];
	char	*res;
	FILE	*file;

	//res = gets(buf);
	path  = "test";
	file = fopen(path, "r");
	do
	{
		res = fgets(buf, 4096, file);
		if (res)
			printf("read: %s\n", buf);
		printf("6: %c\n", buf[6]);
	} while (res);

	return (0);
}
