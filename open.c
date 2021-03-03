#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	     
	    int fd; //描述符
	    fd = open(argv[1],O_RDONLY);
	    if(fd == -1)
	    {
	            perror("open failed");
	            exit(1);
	    }
	     return 0;
	     
	    /*
	    int fd;
	        fd = open(argv[1],O_WRONLY | O_CREAT,0666);
		    if(fd == -1)
			        {
					perror("open failed");
					exit(1);
				 }
		return 0;
	    */	
}
