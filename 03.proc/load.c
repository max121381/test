#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	printf("I'm load:%d\n", getpid());
	pid = fork();
	if(pid == 0)
	{
		execl("/home/max/01.C/03.proc/proc","proc",NULL);
	}
	else
	{
		printf("I finished:%d\n",getpid());
		wait(NULL);
	}
	return 0;	
}
