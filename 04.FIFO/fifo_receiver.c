#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define PIPEFILE "./fifo1"
#define BUFSIZE 100

int main()
{
	int fd, n;
	char buf[BUFSIZE];
	printf("before fifo open\n");
	if ((fd = open(PIPEFILE, O_RDONLY)) < 0 )
	{//�Զ��ķ�ʽ��FIFO
		perror("fifo open failed!\n");
		exit(-1);
	}
	else 
	{
		printf("fifo open sucessfully!\n");
	}
	printf("after fifo open\n");
	n = read(fd, buf, BUFSIZE);//��ȡFIFO�е�����
	buf[n] = '\0';
	printf("received message:%s\n", buf);
	close(fd);
	return 0;
}
