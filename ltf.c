#include<stdio.h>
#include<stdlib.h>
# include<string.h> 
void menu1();
void menu2();
void checkAccountandPassword(struct student *np);//ѧ���˺��������// 




void menu1()
{
	printf("--------[ѡ��ϵͳ]--------\n");
	printf("\t1.ѧ����½\n");
	printf("\t2.��ʦ��¼\n");
	printf("\t3.�˳�ϵͳ\n");
	printf("--------------------------\n");

}
void menu2()
{
	printf("--------[ѧ������]--------\n");
	printf("\t1.ѧ����ʼѡ��\n");
	printf("\t2.��ѯ�γ���Ϣ\n");
	printf("\t3.��ѯѡ�ν��\n");
	printf("\t4.ɾ��ѡ�ν��\n");
	printf("\t5.������Ϣ����\n");
	printf("--------------------------\n");

}
void keydown()
{
	int choice = 0;
	scanf("%d",&choice);
	switch(choice)
	{
			case 1:
		printf("--------[ѧ����¼]------\n");
		checkAccountandPassword(ȱһ���׵�ַ);
		break;
	case 2:
		printf("--------[��ʦ��¼]------\n");
		break;
	case 3:
		printf("�����˳�");
		system("pause");
		exit(0);
		break;
	default:
		printf("������������\n");
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
	printf("�������ѧ��:\n");
	gets(id);
	fflush(stdin);
	printf("�����������\n");
	gets(password); 
	while(np!=NULL)
	{
		if(strcmp(id,np->id)!=0)
		{
			np=np->next;
		}
		else
		{
			printf("ѧ�Ų�ѯ����");
		}
		if(strcmp(password,np->password)!=0)
		{
			printf("�������");
		}
		else
		{
			printf("��½�ɹ���")��
			menu2();
			return; 
		}
	}
	
 }
 



course *search_cos(course *np, char CourseName[20])             //���ݿγ��������γ�                                          
{
	char CourseName[20];
	printf("������γ����ƣ�\n");
	gets(CourseName);
	while(np != NULL && strcmp(np->name, CourseName) != 0)	// ����������һ���ڵ㣬ֱ���ҵ��γ���Ϊֹ�����ߵ�����ĩβ

	{

		np = np->next;

	}

	if (np != NULL)					// ��ĩβ�����ҵ�

	{
		void print_cos(course *np); //��ӡ�γ����� 
		return np;

	}

	else

    {

        printf("Not Found!\n");

    }   

    return NULL;

}
course *search_cos(course *np,  char department[20])             //���ݿ���ѧԺ�����γ�                                          
{
	char department[20]�� 
	printf("������γ����ƣ�\n");
	gets(department);
	while(np != NULL && strcmp(np->department, CourseName) != 0)	// ����������һ���ڵ㣬ֱ���ҵ�����ѧԺΪֹ�����ߵ�����ĩβ

	{

		np = np->next;

	}

	if (np != NULL)					// ��ĩβ�����ҵ�

	{
		void print_cos(course *np); //��ӡ�γ����� 
		return np;

	}

	else

    {

        printf("Not Found!\n");

    }   

    return NULL;

}
void print_cos(course *np)  //  ��ӡĳ���γ̽��

{

    printf("ID: %s / Name: %s / Credit: %d / Period: %d / Characteristics: %s / Teacher: %s ", np->id, np->name, np->credit, np->period, np->characteristics, np->teacher);

    printf("Time: 202%d-202%dѧ���%dѧ�ڵ�%d�� ",np->year1, np->year2, np->semester, np->week, np->time);

    printf("Place: ��%d¥-%d ", np->building, np->room);

    printf("Limitation: %d / Selected: %d ", np->limitation, np->selected);

    printf("Introduction of course: %s / Information of material: %s \n", np->ioc, np->iom);

}

}
struct course *SelectSort1(struct course *s_fcourse) //����ѡ���������� 
{
	struct student *first; //���к��������ı�ͷָ��
	struct student *tail; //���к��������ı�βָ��
	struct student *p_min; //������ֵ��С�Ľڵ��ǰ���ڵ��ָ��
	struct student *min; //�洢��С�ڵ�
	struct student *p; //��ǰ�ȽϵĽڵ�
	first = NULL;
	while(head!=NULL)
	{
		for(p=head,min=head;p->next!=NULL;p=p->next)//�������нڵ� 
		{
			if(p->next->selected < min->selected)// �ҵ���С�ڵ� 
			{
				p_min = p;  //����ǰ���ڵ� 
				min = p->next;  //�õ���С�ڵ� 
			}
		}
		if(first==NULL)//��һ������Ϊ��ʱ 
		{
			first = min;//ͷΪ��Сֵ 
			tail = min;//βΪ��Сֵ 
		}
		else//�������������� 
		{
			tail->next=min;//��βnextָ����С 
			tail=min;//��βҲָ����С 
		}
		if(min==head)//ʹԭ������min���� 
		{
			head = head->next; 
		}
		else
		{
			p_min->next = min->next;//ǰ���ڵ�ָ��min����һ���ڵ㣬min�ɷ����ԭ���� 
		}
		if(first!=NULL)//ѭ����������βָ���nextΪNULL 
		{
			tail->next = NULL; 
		}
		head = first;
		return head;
	}
}



������=��������-ѡ������ 
struct course *SelectSort2(struct course *s_fcourse) //���ݿ��������� 
{
	struct student *first; //���к��������ı�ͷָ��
	struct student *tail; //���к��������ı�βָ��
	struct student *p_min; //������ֵ��С�Ľڵ��ǰ���ڵ��ָ��
	struct student *min; //�洢��С�ڵ�
	struct student *p; //��ǰ�ȽϵĽڵ�
	first = NULL;
	while(head!=NULL)
	{
		for(p=head,min=head;p->next!=NULL;p=p->next)//�������нڵ� 
		{
			if(((p->next->limitation)-(p->next->selected)) < ((min->limitation)-(min->selected)))// �ҵ���С�ڵ� 
			{
				p_min = p;  //����ǰ���ڵ� 
				min = p->next;  //�õ���С�ڵ� 
			}
		}
		if(first==NULL)//��һ������Ϊ��ʱ 
		{
			first = min;//ͷΪ��Сֵ 
			tail = min;//βΪ��Сֵ 
		}
		else//�������������� 
		{
			tail->next=min;//��βnextָ����С 
			tail=min;//��βҲָ����С 
		}
		if(min==head)//ʹԭ������min���� 
		{
			head = head->next; 
		}
		else
		{
			p_min->next = min->next;//ǰ���ڵ�ָ��min����һ���ڵ㣬min�ɷ����ԭ���� 
		}
		if(first!=NULL)//ѭ����������βָ���nextΪNULL 
		{
			tail->next = NULL; 
		}
		head = first;
		return head;
	}
}
