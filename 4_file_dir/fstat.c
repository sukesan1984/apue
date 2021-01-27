#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

void show_stat(struct stat *buf)
{
   	switch (buf->st_mode & S_IFMT) {
		case S_IFBLK:  printf("block device\n");            break;
		case S_IFCHR:  printf("character device\n");        break;
		case S_IFDIR:  printf("directory\n");               break;
		case S_IFIFO:  printf("FIFO/pipe\n");               break;
		case S_IFLNK:  printf("symlink\n");                 break;
		case S_IFREG:  printf("regular file\n");            break;
		case S_IFSOCK: printf("socket\n");                  break;
		default:       printf("unknown?\n");                break;
    }

   printf("I-node number:            %ld\n", (long) buf->st_ino);

   printf("Mode:                     %lo (octal)\n", (unsigned long) buf->st_mode);

   printf("Link count:               %ld\n", (long) buf->st_nlink);
   printf("Ownership:                UID=%ld   GID=%ld\n", (long) buf->st_uid, (long) buf->st_gid);

   printf("Preferred I/O block size: %ld bytes\n", (long) buf->st_blksize);
   printf("File size:                %lld bytes\n", (long long) buf->st_size);
   printf("Blocks allocated:         %lld\n", (long long) buf->st_blocks);

   printf("Last status change:       %s", ctime(&buf->st_ctime));
   printf("Last file access:         %s", ctime(&buf->st_atime));
   printf("Last file modification:   %s", ctime(&buf->st_mtime));
}

int main(int argc, char **argv)
{
	int fd;
	int res;
	char *path;
	struct stat buf;

	if (argc != 2)
		return (0);
	path = argv[1];
	fd = open(path, O_RDONLY);
	res = fstat(fd, &buf);
	if (res < 0)
	{
		printf("fstat error\n");
		return (1);
	}

	show_stat(&buf);

	return (0);
}
