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
 



course *search_cos(course *np, char CourseName[20])             //根据课程名搜索课程                                          
{
	char CourseName[20];
	printf("请输入课程名称：\n");
	gets(CourseName);
	while(np != NULL && strcmp(np->name, CourseName) != 0)	// 不断搜索下一个节点，直到找到课程名为止，或者到链表末尾

	{

		np = np->next;

	}

	if (np != NULL)					// 非末尾，即找到

	{
		void print_cos(course *np); //打印课程内容 
		return np;

	}

	else

    {

        printf("Not Found!\n");

    }   

    return NULL;

}
course *search_cos(course *np,  char department[20])             //根据开课学院搜索课程                                          
{
	char department[20]； 
	printf("请输入课程名称：\n");
	gets(department);
	while(np != NULL && strcmp(np->department, CourseName) != 0)	// 不断搜索下一个节点，直到找到开课学院为止，或者到链表末尾

	{

		np = np->next;

	}

	if (np != NULL)					// 非末尾，即找到

	{
		void print_cos(course *np); //打印课程内容 
		return np;

	}

	else

    {

        printf("Not Found!\n");

    }   

    return NULL;

}
void print_cos(course *np)  //  打印某个课程结点

{

    printf("ID: %s / Name: %s / Credit: %d / Period: %d / Characteristics: %s / Teacher: %s ", np->id, np->name, np->credit, np->period, np->characteristics, np->teacher);

    printf("Time: 202%d-202%d学年第%d学期第%d周 ",np->year1, np->year2, np->semester, np->week, np->time);

    printf("Place: 教%d楼-%d ", np->building, np->room);

    printf("Limitation: %d / Selected: %d ", np->limitation, np->selected);

    printf("Introduction of course: %s / Information of material: %s \n", np->ioc, np->iom);

}

}
struct course *SelectSort1(struct course *s_fcourse) //根据选课人数排序 
{
	struct student *first; //排列后有序链的表头指针
	struct student *tail; //排列后有序链的表尾指针
	struct student *p_min; //保留键值更小的节点的前驱节点的指针
	struct student *min; //存储最小节点
	struct student *p; //当前比较的节点
	first = NULL;
	while(head!=NULL)
	{
		for(p=head,min=head;p->next!=NULL;p=p->next)//遍历所有节点 
		{
			if(p->next->selected < min->selected)// 找到最小节点 
			{
				p_min = p;  //保留前驱节点 
				min = p->next;  //得到最小节点 
			}
		}
		if(first==NULL)//第一次链表为空时 
		{
			first = min;//头为最小值 
			tail = min;//尾为最小值 
		}
		else//链表中已有数据 
		{
			tail->next=min;//表尾next指向最小 
			tail=min;//表尾也指向最小 
		}
		if(min==head)//使原链表中min脱离 
		{
			head = head->next; 
		}
		else
		{
			p_min->next = min->next;//前驱节点指向min的下一个节点，min可分离出原链表 
		}
		if(first!=NULL)//循环结束后令尾指针的next为NULL 
		{
			tail->next = NULL; 
		}
		head = first;
		return head;
	}
}



课余量=限制人数-选课人数 
struct course *SelectSort2(struct course *s_fcourse) //根据课余量排序 
{
	struct student *first; //排列后有序链的表头指针
	struct student *tail; //排列后有序链的表尾指针
	struct student *p_min; //保留键值更小的节点的前驱节点的指针
	struct student *min; //存储最小节点
	struct student *p; //当前比较的节点
	first = NULL;
	while(head!=NULL)
	{
		for(p=head,min=head;p->next!=NULL;p=p->next)//遍历所有节点 
		{
			if(((p->next->limitation)-(p->next->selected)) < ((min->limitation)-(min->selected)))// 找到最小节点 
			{
				p_min = p;  //保留前驱节点 
				min = p->next;  //得到最小节点 
			}
		}
		if(first==NULL)//第一次链表为空时 
		{
			first = min;//头为最小值 
			tail = min;//尾为最小值 
		}
		else//链表中已有数据 
		{
			tail->next=min;//表尾next指向最小 
			tail=min;//表尾也指向最小 
		}
		if(min==head)//使原链表中min脱离 
		{
			head = head->next; 
		}
		else
		{
			p_min->next = min->next;//前驱节点指向min的下一个节点，min可分离出原链表 
		}
		if(first!=NULL)//循环结束后令尾指针的next为NULL 
		{
			tail->next = NULL; 
		}
		head = first;
		return head;
	}
}
