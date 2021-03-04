#include <stdio.h>
#define SIZE 4
struct student_type
{
	char name[10];
	int num;
	int age;
	char addr[15];
}stud[SIZE];
void save( )
{
	FILE *fp;
	int i;
	if ((fp=fopen("stu-list","wb"))==NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for(i=0; i<SIZE; i++)/*二进制写*/
	if(fwrite(&stud[i],sizeof(struct student_type),1,fp)!=1)	
	{
		printf("file write error\n");/*出错处理*/
		fclose(fp); 
	} /*关闭文件*/   

}
int main()
{
	int i;
	for(i=0;i<SIZE;i++)/*从键盘读入学生信息*/
	scanf("%s%d%d%s",stud[i].name,&stud[i].num,&stud[i].age,stud[i].addr);
	save( );
	return 0;
}
