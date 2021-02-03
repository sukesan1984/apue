#include <stdio.h>

int main(int argc, char **argv)
{
	char	buf[4096];
	char	*path;
	FILE	*file;
	FILE	*in_file;
	char	*res;
	int		result;

	if (argc != 2)
		return (0);
	path = argv[1];
	file = fopen(path, "w");
	in_file = fdopen(0, "r");
	do
	{
		res = fgets(buf, 4096, in_file);
		if (res)
		{
			result = fputs(buf, file);
			if (result == EOF)
				perror("error");
		}
	} while (res);
	fclose(file);
	fclose(in_file);

	return (0);
}
