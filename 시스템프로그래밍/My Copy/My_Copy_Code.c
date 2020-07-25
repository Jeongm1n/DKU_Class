//mycp program by 32164420 조정민, qll4359@naver.com
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#define MAX_BUF 128
int main(int argc, char* argv[])
{
	int fd1, fd2, read_size, write_size;
	char buf[MAX_BUF];
	struct stat st;
	if(argc!=3)
	{
		printf("Syntax Error\n");
		printf("USAGE : mycp <FILE_NAME> <COPY_NAME>");
		exit(-1);
	}
	stat(argv[1], &st);
	fd1 = open(argv[1], O_RDONLY);
	if(fd1<0)
	{
		printf("Can't open %s, Check the file!", argv[1]);
		exit(-1);
	}
	fd2 = open(argv[2], O_RDWR |O_CREAT| O_EXCL, st.st_mode);
	if(fd2<0)
	{
		printf("Can't Create %s", argv[2]);
		exit(-1);
	}
	while(1)
	{
		read_size=read(fd1, buf, MAX_BUF);
		write_size = write(fd2, buf, read_size);
		if(read_size==0)
			break;
	}
	close(fd1);
	close(fd2);
	return 0;
}
