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
	for(i=0; i<SIZE; i++)/*������д*/
	if(fwrite(&stud[i],sizeof(struct student_type),1,fp)!=1)	
	{
		printf("file write error\n");/*������*/
		fclose(fp); 
	} /*�ر��ļ�*/   

}
int main()
{
	int i;
	for(i=0;i<SIZE;i++)/*�Ӽ��̶���ѧ����Ϣ*/
	scanf("%s%d%d%s",stud[i].name,&stud[i].num,&stud[i].age,stud[i].addr);
	save( );
	return 0;
}
