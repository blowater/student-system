//  ѧ�����ܣ�

//  ��һҳ������ţ�
//  1.��½������ѧ�ź������½ϵͳ��
//  2.ѧ��ѡ�Σ�����ϵͳ�ṩ�Ŀγ̽����������ѡ�����Ȥ�Ŀγ̡�
//          a.ͬһ��ѧ�������Ż���ſγ�֮��ʱ�䲻�ܳ�ͻ
//          b.�涨һ��ѧ��һ��ѧ�������ѡ3�ſ�
//          c.ÿ�ſγ�ѡ���������ܳ�����������
//  3.��ѯ�γ�
//          a.���ݿγ�����ѯ
//          b.���ݿ���ѧԺ��ѯ
//          c.���ݿ������������пγ�
//          d.����ѡ�������������пγ�

//  �ڶ�ҳ����������
//  4.��ѯѡ�ν��
//          a.�鿴ѧ������ѡ�޹��Ŀγ�
//  5.ɾ��ѡ�ν��
//          a.��δ����֮ǰѧ������ɾ���Լ���ѡ�ν��
//  6.������Ϣ����
//          a.�Ը�����Ϣ�еĵ绰�����뼰��������޸�


//  ��ʦ���ܣ�

//  ����ҳ����������
//  1.��½�����빤�ź������½ϵͳ��
//  2.ѡ�ι���
//          a.�鿴ѡ�������
//                      ����ѯ��ʦ�Լ�������̵Ŀγ̵�ѡ�������ѡ�������Ϳγ���ϸ��Ϣ��
//                      ����ѯѡ��ĳ�ſγ̵�ѧ����Ϣ������ѧ��������γ����ƣ�
//          b.ɾ��ѡ�Σ�
//                      ��ѡ�ν��������ĳ�ſγ̵�ѡ����������30����ɾ���ÿγ̣�����ѡ��ÿγ̵�ѧ��ѡ����Ϣɾ��
//  3.ͳ��ѡ����Ϣ��
//          a.ͳ�ƽ�ʦ�Լ�������Ŀγ���Ŀ
//          b.��ѡ�������������п�����Ŀγ�

//  ����ҳ��������
//  4.�γ̹�����Խ�ʦ�Լ�����Ŀγ�
//          a.��ѯ���п���Ŀγ̡����ݿγ�����ѯ
//  5.��ӿγ̣����һ���µĿγ�
//          a.ͬһ����ʦ���Ͽ�ʱ�䲻�ܳ�ͻ
//          b.�γ������γ̺Ų����ظ�
//          c.ͬһ����ʦһ��ѧ�����ֻ�ܿ�����ѡ�޿�
//          d.�γ̵���������������ѡ��80�˺�100��
//  6.�޸Ŀγ̣�
//          a.��һ�ſγ���δ��ѧ��ѡ��ʱ�������޸ģ��̲ġ��γ̼�顢����������
//          b.��ʼѡ�κ󣬿����޸ģ�����������
//  7.ɾ���γ̣�
//          a.δ��ʼѡ�Σ����Խ���ɾ��������
//  8.������Ϣ����
//          a.�Ը�����Ϣ�е����뼰��������޸�


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
//  �γ̽ṹ��
typedef struct course{
	char id[6];                 //  �γ̱�ţ�6λ���֣�
	char name[20];              //  �γ�����
    int credit;                 //  ѧ�֣���ȡ��Χ����1-4��
    int period;                 //  ѧʱ
    char charateristics[10];    //  �γ�����
    char teacher[20];           //  ���ν�ʦ
    char time[20];              //  �Ͽ�ʱ�䣨��ֹʱ���ʽΪ����202*-202*ѧ���*ѧ�ڵ�*�ܡ���
                                //  �Ͽξ���ʱ��Σ�ȫ�칲��10��ʱ��Σ���8:00-11:50ÿ50����һ��ʱ��Σ�����1��30-5��20ÿ50����һ��ʱ��Σ���6��30-8��20û50����һ��ʱ��Ρ��μ���Ϣ��Ϊ10���ӡ���

    char place[20];             //  �Ͽεص㣨�Ͽεص��ʽ����¥��-����š�1��ʾ��һ¥��2��ʾ�̶�¥�������Ϊ3Ϊ���֡���
    int limitation;             //  ����������80��100�ˣ�
    char ioc[20];               //  "ioc" == "introduction of class"���γ̼��
    char iom[20];               //  "iom" == "information of material"���̲���Ϣ
	struct course *next;
} course;




//  ѧ���ṹ��
typedef struct student{
	char id[10];                //  ѧ�ţ�10λ���֣�
	char department[10];        //  Ժϵ
	char major[10];             //  רҵ
	char name[20];              //  ����
	char gender[10];            //  �Ա�
	char phone_number[11];      //  �绰��11λ���֣�
	char password[20];          //  ����
	char mailbox[10];           //  ���䣨����***@***.***�Ĺ淶��
    course *s_course;           //  ����ѧ�����ѧ����ѡ�γ̵�ͷָ��
	struct student *next;       
} student;



//  ��ʦ�ṹ��
typedef struct teacher{
	char id[10];                //  ���ţ�10λ���֣�
	char department[10];        //  Ժϵ
	char name[20];              //  ����
	char mailbox[10];           //  ����
	char password[20];          //  ����
    course *t_course;           //  ���ӽ�ʦ��ý�ʦ���ڿγ̵�ͷָ��
	struct teacher *next;   
} teacher;


student *create_std(char id[][10],
                        char department[][10],
                        char major[][10],
                        char name[][20],
                        char gender[][10],
                        char phone_number[][11],
                        char password[][20],
                        char mailbox[][10]);
void print_std(student *np);
void traversal_std(student *fnode);
student *insertBegining(student *fnode, student *newnode);

int main()
{
    // ��������
    char id[N][10]={"1","2","3","4","5"};
    char department[N][10]={"1","2","3","4","5"};
    char major[N][10]={"1","2","3","4","5"};
    char name[N][20]={"1","2","3","4","5"};
    char gender[N][10]={"1","2","1","2","1"};
    char phone_number[N][11]={"1","2","3","4","5"};
    char password[N][20]={"1","2","3","4","5"};
    char mailbox[N][10]={"1","2","3","4","5"};


    student *fstudent=NULL,*fostudent=NULL,*new_student=NULL,*np=NULL;
    int i;
    int key;

    for(i=0;i<5;i++)
    {
        new_student = create_std(id,department,major,name,gender,phone_number,password,mailbox);
        fstudent = insertBegining(fstudent, new_student);
    }
    traversal_std(fstudent);

    return 0;
}

student *create_std(char id[][10],
                        char department[][10],
                        char major[][10],
                        char name[][20],
                        char gender[][10],
                        char phone_number[][11],
                        char password[][20],
                        char mailbox[][10])  
{
    static int i = 0;
    student *np;
    np = (student *) malloc(sizeof(student));   // ��̬�����ڴ棬���ѧ������
    strcpy(np->id, id[i]);
    strcpy(np->department, department[i]);
    strcpy(np->major, major[i]);
    strcpy(np->name, name[i]);
    strcpy(np->gender, gender[i]);
    strcpy(np->phone_number, phone_number[i]);
    strcpy(np->password, password[i]);
    strcpy(np->mailbox, mailbox[i]);
    np->next = NULL;
    i++;
    return np;
}

void print_std(student *np)
{
    printf("ID: %s / Department: %s / Major: %s / Name: %s / Gender: %s / Phone number: %s / Password: %s / Mailbox: %s\n", np->id, np->department, np->major, np->name, np->gender, np->phone_number, np->password, np->mailbox);
}

void traversal_std(student *fnode)
{
    student *np = fnode;
    while(np != NULL)
    {
        print_std(np);
        np = np->next;
    }
}

student *insertBegining(student *fnode, student *newnode)
{
    newnode->next = fnode;
    fnode = newnode;
    return fnode;
}