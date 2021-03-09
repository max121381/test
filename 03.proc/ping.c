#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t result;
	result = fork();
	int newret;
	if (result == -1)
	{
		perror("create child process failed");
		exit;
	}
	else if (result == 0)
	{
		printf("return:%d,child process!\n PID:%d\nPPID:%d\n",result,getpid(),getppid());
		newret = system("ls -l");
	}
	else
	{
		sleep(10);
		printf("return:%d,process!\n PID:%d\nPPID:%d\n",result,getpid(),getppid());
		newret = system("ping www.baidu.com");
	}
}
