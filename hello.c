#include <stdio.h>
int main()
{
	FILE * f;
	char buf[100];	
	if ((f = fopen("./log","w+")) == NULL)
	{
		printf("log file open failed.\n");
		return 1;
	}
	printf("hello world!\n");
	fprintf(f, "hello,world!\n");
	fgets(buf ,99 ,f);
	printf("%s", buf);
	fclose(f);
	return 0;
}
