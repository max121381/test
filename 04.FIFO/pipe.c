#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	pid_t result;
	int ret;
	result = fork();
	int newret;
	if(result<0)
	{
		perror("create child process failed");
		exit(1);
	}
	else if (result == 0)
	{
		raise(SIGSTOP);
		exit(0);
	}
	else
	{
		printf("PID:%d\n",result);
		if((waitpid(result,NULL,WNOHANG)) == 0)
		{
			if(ret = kill(result,SIGKILL)==0)
				printf("KILL return:%d,SIGKILL PID:%d\n",ret,result);
			else
			{
				perror("kill failed");
			}
		}
	}
}
