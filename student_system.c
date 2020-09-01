/*Desc: Student system
    �����˿γ���Ϣ�е��Ͽ�ʱ����Ͽεص�

Author: 
Date: 2020/9/1
*/


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
//  ��ʦ�ṹ��
typedef struct teacher{
	char id[10];                //  ���ţ�10λ���֣�
	char department[10];        //  Ժϵ
	char name[20];              //  ����
	char mailbox[10];           //  ����
	char password[20];          //  ���� 
	struct teacher *next;   
} teacher;

//  �γ̽ṹ��                                                
typedef struct course{
	char id[6];                 //  �γ̱�ţ�6λ���֣�
	char name[20];              //  �γ�����
    int credit;                 //  ѧ�֣���ȡ��Χ����1-4��
    int period;                 //  ѧʱ
    char characteristics[10];   //  �γ�����
    char teacher[20];           //  ���ν�ʦ
                                //  �Ͽ�ʱ�䣨��ֹʱ���ʽΪ����202*-202*ѧ���*ѧ�ڵ�*�ܡ���
    int year1;                  //  yearѡ��ΧΪ0-9
    int year2;
    int semester;               //  semesterѡ��ΧΪ1-2
    int week;                   //  weekѡ��ΧΪ01-20
                                //  �Ͽξ���ʱ��Σ�ȫ�칲��10��ʱ��Σ���8:00-11:50ÿ50����һ��ʱ��Σ�����1��30-5��20ÿ50����һ��ʱ��Σ���6��30-8��20û50����һ��ʱ��Ρ��μ���Ϣ��Ϊ10���ӡ���
    int time[10];               //  timeѡ��ΧΪ01-10
                                //  �Ͽεص㣨�Ͽεص��ʽ����¥��-����š�1��ʾ��һ¥��2��ʾ�̶�¥�������Ϊ3λ���֡���
    int building;               //  ¥��
    int room;                   //  �����
    int limitation;             //  ����������80��100�ˣ�
    int selected;               //  �γ���ѡ����
    char ioc[20];               //  "ioc" == "introduction of course"���γ̼��
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
	struct student *next;       
} student;

//  ��ʦ�����������
teacher *create_tch(char id[][10],                  //  ����һ����ʦ���
                    char department[][10],
                    char name[][20],
                    char mailbox[10],
                    char password[][20]);
void print_tch(teacher *np);                        //  ��ӡĳ����ʦ���
void traversal_tch(teacher *fnode);                 //  ��������ӡ���н�ʦ���
teacher *insertBeginning_tch(teacher *fnode, teacher *newnode); //  �����ʦ���ͷ��
void searchcource(course *np, char key);            //  �γ̹���a.��ѯ���п���Ŀγ̡����ݿγ�����ѯ

//  �γ������������
course *create_cos(char id[][6],                    // ���������ݵ���һ���γ̽��
                    char name[][20],
                    int credit[],
                    int period[],
                    char characteritics[][10],
                    char teacher[][20],
                    int year1[],
                    int year2[],
                    int semester[],
                    int week[],
                    int time[][10],
                    int building,
                    int room[],
                    int limitation[],
                    int selected[],
                    char ioc[][20],
                    char iom[][20]);
course *tch_create_cos(course *fnode);                              //  ��ʦ�ֶ������γ̽��
void print_cos(course *np);                         //  ��ӡĳ���γ̽��
void traversal_cos(course *fnode);                  //  ��������ӡ���пγ�
course *insertBeginning_cos(course *fnode, course *newnode);    //  ����γ�����ͷ��
int check_t_course(course *fnode, course *new_node);

//  ѧ�������������
student *create_std(char id[][10],                  //  ����һ��ѧ�����
                    char department[][10],
                    char major[][10],
                    char name[][20],
                    char gender[][10],
                    char phone_number[][11],
                    char password[][20],
                    char mailbox[][10]);
void print_std(student *np);                        //  ��ӡĳ��ѧ�����
void traversal_std(student *fnode);                 //  ��������ӡ����ѧ�����
student *insertBeginning_std(student *fnode, student *newnode);  //  ����ѧ������ͷ��

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


    student *fstudent=NULL,*fostudent=NULL,*new_student=NULL,*np_s=NULL;    //  ׼������ѧ����������
    teacher *fteacher=NULL,*foteacher=NULL,*new_teacher=NULL,*np_t=NULL;    //  ׼��������ʦ��������
    course *t_fcourse=NULL,*t_focourse=NULL,*t_new_course=NULL,*t_np_c=NULL;    // ׼��������ʦ����γ�����
    course *s_fcourse=NULL,*s_focourse=NULL,*s_new_course=NULL,*s_np_c=NULL;    // ׼������ѧ��ѡ�޿γ�����
    int i;
    int key;

    for(i=0;i<5;i++)
    {
        new_student = create_std(id,department,major,name,gender,phone_number,password,mailbox);
        fstudent = insertBeginning_std(fstudent, new_student);
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


void print_std(student *np) //  ��ӡĳ��ѧ�����
{
    printf("ID: %s / Department: %s / Major: %s / Name: %s / Gender: %s / Phone number: %s / Password: %s / Mailbox: %s\n", np->id, np->department, np->major, np->name, np->gender, np->phone_number, np->password, np->mailbox);
}

void traversal_std(student *fnode)  //  ��������ӡ����ѧ�����
{
    student *np = fnode;
    while(np != NULL)
    {
        print_std(np);
        np = np->next;
    }
}

student *insertBeginning_std(student *fnode, student *newnode)  //  ����ѧ������ͷ��  
{
    newnode->next = fnode;
    fnode = newnode;
    return fnode;
}
course *create_cos(char id[][6],                    // ���������ݵ���һ���γ̽��
                    char name[][20],
                    int credit[],
                    int period[],
                    char characteristics[][10],
                    char teacher[][20],
                    int year1[],
                    int year2[],
                    int semester[],
                    int week[],
                    int time[],
                    int building[],
                    int room[],
                    int limitation[],
                    int selected,
                    char ioc[][20],
                    char iom[][20])
{
    course *np;
    np = (course *) malloc(sizeof(course));
    /*
        ����


    */
    np->next = NULL;
    return np;
}
course *tch_create_cos(course *fnode)                    // ��ʦ�ֶ������γ̽��                
{
    course *np;
    np = (course *) malloc(sizeof(course));
    printf("������γ̱�ţ�\n");
    scanf("%s", &np->id);
    printf("������γ����ƣ�\n");
    scanf("%s", &np->name);
    printf("������γ�ѧ�֣�\n");
    scanf("%d", &np->credit);
    printf("������γ�ѧʱ��\n");
    scanf("%d", &np->period);
    printf("������γ����ʣ�\n");
    scanf("%s", &np->characteristics);
    printf("������γ̽�ʦ���ƣ�\n");
    scanf("%s", &np->teacher);
    printf("�γ���ʼ��202*ѧ�ꣿ\n");
    scanf("%d", &np->year1);
    printf("�γ̽�����202*ѧ�ꣿ\n");
    scanf("%d", &np->year2);
    printf("��*ѧ�ڣ�\n");
    printf("1.��һѧ��\n");
    printf("2.�ڶ�ѧ��\n");
    scanf("%d", &np->semester);
    printf("��*�ܣ�\n");
    scanf("%d", &np->week);
    printf("��ѡ��γ�ʱ���\n");
    printf("1.8:00-8:50\n");
    printf("2.9:00-9:50\n");
    printf("3.10:00-10:50\n");
    printf("4.11:00-11:50\n");
    printf("5.1:30-2:20\n");
    printf("6.2:30-3:20\n");
    printf("7.3:30-4:20\n");
    printf("8.4:30-5:20\n");
    printf("9.6:30-7:20\n");
    pritnf("10:30-8:20\n");
    scanf("%d", &np->time);        
    printf("��*¥��\n");
    scanf("%d", &np->building);
    printf("����ţ�\n");
    scanf("%d", &np->room);
    printf("��������ѡ��\n");
    printf("1.80\n");
    printf("2.100\n");
    scanf("%d", &np->limitation);
    printf("�γ̼�飺\n");
    scanf("%s", &np->ioc);
    printf("�̲���Ϣ��\n");
    scanf("%s", &np->iom);        
    np->next = NULL;
    int a=0;
    a = check_t_course(fnode,np);
    if (a == 0)
    {
        return np;
    }
    else if(a == 1)
    {
        printf("�γ�ʱ�����ѿ���γ̳�ͻ");
    }
    else if(a == 2)
    {
        printf("�γ������ѿ���γ��ظ�");
    }
    else if(a == 3)
    {
        printf("�γ̺����ѿ���γ��ظ�");
    }
    else if(a == 4)
    {
        printf("����һλ��ʦ��ѧ�ڿ���γ���������2��");
    }
    return NULL;
}

void print_cos(course *np)  //  ��ӡĳ���γ̽��
{
    printf("ID: %s / Name: %s / Credit: %d / Period: %d / Characteristics: %s / Teacher: %s / Time: 202%d-202%dѧ���%dѧ�ڵ�%d�� / Place: ��%d¥-%d / Limitation: %d / Selected: %d / Introduction of course: %s / Information of material: %s\n", np->id, np->name, np->credit, np->period, np->characteristics, np->teacher, np->year1, np->year2, np->semester, np->week, np->time, np->building, np->room, np->limitation, np->selected, np->ioc, np->iom);
}
void traversal_cos(course *fnode)   //  ��������ӡ���пγ�
{
    course *np = fnode; 
    while(np != NULL)
    {
        print_cos(np);
        np = np->next;
    }
}
course *insertBeginning_cos(course *fnode, course *newnode) //  ����γ�����ͷ��
{
    newnode->next = fnode;
    fnode = newnode;
    return fnode;
} 
int check_t_course(course *fnode, course *new_node)
{
    course *np;
    np = fnode;
    int i=0;
    while(np != NULL)
    {
        if (new_node->year1 == np->year1 
            && new_node->year2 == np->year2
            && new_node->semester == np->semester
            && new_node->week == np->week
            && new_node->time == np->time)
        {
            return 1;
        }    
        else if (new_node->name == np->name)
        {
            return 2;
        }
        else if (new_node->id == np->id)
        {
            return 3;
        }
        else if (new_node->year1 == np->year1
                && new_node->year2 == np->year2
                && new_node->semester == np->semester)
        {
            i++;
            if (i > 2)
            {
                return 4;
            }
        }
        else
        {
            np = np->next;
        }
    }
    return 0;
}
teacher *create_tch(char id[][10],                  //  ����һ����ʦ���
                    char department[][10],
                    char name[][20],
                    char mailbox[10],
                    char password[][20])
{
    teacher *np;
    np = (teacher *) malloc(sizeof(teacher));
    /*
        ����


    */
    np->next = NULL;
    return np;
}
void print_tch(teacher *np) //  ��ӡĳ����ʦ���
{
    printf("ID: %s / Department: %s / Name: %s / Mailbox: %s / Password: %s\n", np->id, np->department, np->name, np->mailbox, np->password);
}                        
void traversal_tch(teacher *fnode)  //  ��������ӡ���н�ʦ
{
    teacher *np = fnode; 
    while(np != NULL)
    {
        print_tch(np);
        np = np->next;
    }
}               
teacher *insertBeginning_tch(teacher *fnode, teacher *newnode)  //  �����ʦ����ͷ��
{
    newnode->next = fnode; 
    fnode = newnode;
    return fnode;
} 


void searchcource(cos *np, char key)

{

	while(np != NULL && np->name !=key)	// ����������һ���ڵ㣬ֱ���ҵ�nameΪֹ�����ߵ�����ĩβ

	{

		np = np->next;

	}

	if (np != NULL)					// ��ĩβ�����ҵ�

	{

	print_cos(course *np);

	}

	else

		printf("Not Found!\n");

}