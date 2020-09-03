#include<stdio.h>
#include<stdlib.h>
# include<string.h> 
void menu1();
void menu2();
void checkAccountandPassword(struct student *np);//学生账号密码检验// 




void menu1()
{
	printf("--------[选课系统]--------\n");
	printf("\t1.学生登陆\n");
	printf("\t2.教师登录\n");
	printf("\t3.退出系统\n");
	printf("--------------------------\n");

}
void menu2()
{
	printf("--------[学生功能]--------\n");
	printf("\t1.学生开始选课\n");
	printf("\t2.查询课程信息\n");
	printf("\t3.查询选课结果\n");
	printf("\t4.删除选课结果\n");
	printf("\t5.个人信息管理\n");
	printf("--------------------------\n");

}
void keydown()
{
	int choice = 0;
	scanf("%d",&choice);
	switch(choice)
	{
			case 1:
		printf("--------[学生登录]------\n");
		checkAccountandPassword(缺一个首地址);
		break;
	case 2:
		printf("--------[教师登录]------\n");
		break;
	case 3:
		printf("正常退出");
		system("pause");
		exit(0);
		break;
	default:
		printf("错误，重新输入\n");
		break;
	}
 } 
 int main()
 {
 	while(1)
 	{
 		menu1();
 		keydown();
 		system("pause");
 		system("cls");
	 }
	 return 0;
 }
 void checkAccountandPassword(struct student *np,id,password)
 {
 	char id[10],password[20];
    struct student;
	printf("输入你的学号:\n");
	gets(id);
	fflush(stdin);
	printf("输入你的密码\n");
	gets(password); 
	while(np!=NULL)
	{
		if(strcmp(id,np->id)!=0)
		{
			np=np->next;
		}
		else
		{
			printf("学号查询不到");
		}
		if(strcmp(password,np->password)!=0)
		{
			printf("密码错误");
		}
		else
		{
			printf("登陆成功！")；
			menu2();
			return; 
		}
	}
	
 }

