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

