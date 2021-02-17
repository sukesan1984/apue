#include "../apue.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i;
	char **ptr;

	if (argc < 2)
	{
		printf("./a.out <args>");
		exit(0);
	}
	i = 0;
	while (i < argc)
		printf("argv[%d]: %s\n", i, argv[i++]);
	for (ptr = environ; *ptr != 0; ptr++)
		printf("%s\n", *ptr);
	exit(0);
}
