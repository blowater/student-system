/*Desc: Student system
    ѧ��ѡ�Σ���ӿγ�
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
	char id[7];                 //  �γ̱�ţ�6λ���֣�
	char name[20];              //  �γ�����
    int credit;                 //  ѧ�֣���ȡ��Χ����1-4��
    int period;                 //  ѧʱ
    char characteristics[10];   //  �γ�����
    char teacher[20];           //  ���ν�ʦ
    char department[20];        //  ����ѧԺ
                                //  �Ͽ�ʱ�䣨��ֹʱ���ʽΪ����202*-202*ѧ���*ѧ�ڵ�*�ܡ���
    int year1;                  //  yearѡ��ΧΪ0-9
    int year2;
    int semester;               //  semesterѡ��ΧΪ1-2
    int week;                   //  weekѡ��ΧΪ01-20
                                //  �Ͽξ���ʱ��Σ�ȫ�칲��10��ʱ��Σ���8:00-11:50ÿ50����һ��ʱ��Σ�����1��30-5��20ÿ50����һ��ʱ��Σ���6��30-8��20û50����һ��ʱ��Ρ��μ���Ϣ��Ϊ10���ӡ���
    int time;                   //  timeѡ��ΧΪ01-10
                                //  �Ͽεص㣨�Ͽεص��ʽ����¥��-����š�1��ʾ��һ¥��2��ʾ�̶�¥�������Ϊ3λ���֡���
    int building;               //  ¥��
    int room;                   //  �����
    int limitation;             //  ����������80��100�ˣ�
    int selected;               //  ѡ������
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
    course *s_fcourse;          //  ѧ����ѡ�γ�����ͷָ��
	struct student *next;       
} student;

//  ��ʦ���������������
teacher *create_tch(char id[][10],                                      //  ����һ����ʦ���
                    char department[][10],
                    char name[][20],
                    char mailbox[][10],
                    char password[][20]);
void print_tch(teacher *np);                                            //  ��ӡĳ����ʦ���
void traversal_tch(teacher *fnode);                                     //  ��������ӡ���н�ʦ���
teacher *insertBeginning_tch(teacher *fnode, teacher *newnode);         //  �����ʦ���ͷ��



//  ��ʦ����γ������������
course *create_cos(char id[][7],                                        // ��ԭʼ���ݵ���һ���γ̽��
                    char name[][20],
                    int credit[],
                    int period[],
                    char characteritics[][10],
                    char teacher[][20],
                    char department[][20],
                    int year1[],
                    int year2[],
                    int semester[],
                    int week[],
                    int time[],
                    int building[],
                    int room[],
                    int limitation[],
                    int selected[],
                    char ioc[][20],
                    char iom[][20]);
course *tch_create_cos(course *t_fcourse);                              //  �ֶ�������ʦ����γ̽��
void print_cos(course *np);                                             //  ��ӡĳ���γ̽��
void traversal_cos(course *fnode);                                      //  ��������ӡ���пγ�
course *insertBeginning_cos(course *fnode, course *newnode);            //  ����γ�����ͷ��
int tch_check_course(course *fnode, course *new_node);                  //  ����ʦ�����¿γ��Ƿ���Ϲ���
course *search_cos(course *np, char key[20]);                           //  ����ID�����γ�


//  ѧ��ѡ�޿γ������������
int std_check_cos(course *fnode, course *new_node);                     //  ���ѧ��ѡ���¿γ��Ƿ���Ϲ���
course *std_create_cos(course *np);                                     //  ����ѧ��ѡ�޿γ̽��

//  ѧ�����������������
student *create_std(char id[][10],                                      //  ����һ��ѧ�����
                    char department[][10],
                    char major[][10],
                    char name[][20],
                    char gender[][10],
                    char phone_number[][11],
                    char password[][20],
                    char mailbox[][10]);
void print_std(student *np);                                            //  ��ӡĳ��ѧ�����
void traversal_std(student *fnode);                                     //  ��������ӡ����ѧ�����
student *insertBeginning_std(student *fnode, student *newnode);         //  ����ѧ������ͷ��
//  ѧ�����ܣ�
//      1.��½
void menu1(student *fstudent,teacher *fteacher, course *t_fcourse, course *s_fcourse);
void studentmenu1(student *fstudent);
int std_checkAccountandPassword(student *np);                    //  ѧ���˺��������
//      2.ѧ��ѡ��
course *std_select_cos(course *s_fcourse, course *t_fcourse);     
//  ��ʦ���ܣ�
//      1.��½
void teachermenu1(teacher *fteacher);
int tch_checkAccountandPassword(teacher *np);                    //  ��ʦ�˺��������
//      5.��ӿγ�
course *tch_add_cos(course *t_course); 

/*
int main()
{
    // ѧ����������
    char s_id[N][10]={"1","2","3","4","5"};
    char s_department[N][10]={"1","2","3","4","5"};
    char s_major[N][10]={"1","2","3","4","5"};
    char s_name[N][20]={"1","2","3","4","5"};
    char s_gender[N][10]={"1","2","1","2","1"};    
    char s_phone_number[N][11]={"1","2","3","4","5"};
    char s_password[N][20]={"1","2","3","4","5"};
    char s_mailbox[N][10]={"1","2","3","4","5"};
    //  ��ʦ��������
    char t_id[N][10]={"1","2","3","4","5"};
    char t_department[N][10]={"1","2","3","4","5"};
    char t_name[N][20]={"1","2","3","4","5"};
    char t_mailbox[N][10]={"1","2","3","4","5"};
    char t_password[N][20]={"1","2","3","4","5"};
    //  �γ̲�������
    char c_id[N][7]={"1","2","3","4","5"};
    char c_name[N][20]={"1","2","3","4","5"};  
    int c_credit[N]={1,2,3,4,5};
    int c_period[N]={1,2,3,4,5}; 
    char c_characteristics[N][10]={"1","2","3","4","5"};  
    char c_teacher[N][20]={"1","2","3","4","5"};  
    char c_department[N][20]={"1","2","3","4","5"};
    int c_year1[N]={1,2,3,4,5}; 
    int c_year2[N]={1,2,3,4,5}; 
    int c_semester[N]={1,2,3,4,5};
    int c_week[N]={1,2,3,4,5};
    int c_time[N]={1,2,3,4,5};
    int c_building[N]={1,2,3,4,5};
    int c_room[N]={1,2,3,4,5};
    int c_limitation[N]={10,20,30,40,50};
    int c_selected[N]={1,2,3,4,5};
    char c_ioc[N][20]={"1","2","3","4","5"}; 
    char c_iom[N][20]={"1","2","3","4","5"};  
*/
    // student *fstudent=NULL/*ѧ������ͷָ��*/,*fostudent=NULL,*new_student=NULL,*np_s=NULL;    //  ׼������ѧ����������
    // teacher *fteacher=NULL/*��ʦ����ͷָ��*/,*foteacher=NULL,*new_teacher=NULL,*np_t=NULL;    //  ׼��������ʦ��������
    // course *t_fcourse=NULL/*��ʦ�γ�����ͷָ��*/,*t_focourse=NULL,*t_new_course=NULL,*t_np_c=NULL;    // ׼��������ʦ����γ�����
    // course *s_fcourse=NULL/*ѧ���γ�����ͷָ��*/,*s_focourse=NULL,*s_new_course=NULL,*s_np_c=NULL;    // ׼������ѧ��ѡ�޿γ�����
/*
    int i;
    int key;


    for(i=0;i<5;i++)
    {
        new_student = create_std(s_id,s_department,s_major,s_name,s_gender,s_phone_number,s_password,s_mailbox);
        fstudent = insertBeginning_std(fstudent, new_student);
    }
    traversal_std(fstudent);

    for(i=0;i<5;i++)
    {
        new_teacher = create_tch(t_id,t_department,t_name,t_mailbox,t_password);
        fteacher = insertBeginning_tch(fteacher, new_teacher);
    }
    traversal_tch(fteacher);
    
    for(i=0;i<5;i++)
    {
        t_new_course = create_cos(c_id,c_name,c_credit,c_period,c_characteristics,c_teacher,c_department,c_year1,c_year2,c_semester,c_week,c_time,c_building,c_room,c_limitation,c_selected,c_ioc,c_iom);
        t_fcourse = insertBeginning_cos(t_fcourse, t_new_course);
    }
    
    traversal_cos(t_fcourse);
    t_new_course = tch_create_cos(t_fcourse);
    t_fcourse = insertBeginning_cos(t_fcourse, t_new_course); 
    traversal_cos(t_fcourse);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    

    s_fcourse = std_select_cos(s_fcourse, t_fcourse);

    return 0;
}
*/

int main()
{
    int i;
    int key;

    // ѧ����������
    char s_id[N][10]={"1","2","3","4","5"};
    char s_department[N][10]={"1","2","3","4","5"};
    char s_major[N][10]={"1","2","3","4","5"};
    char s_name[N][20]={"1","2","3","4","5"};
    char s_gender[N][10]={"1","2","1","2","1"};    
    char s_phone_number[N][11]={"1","2","3","4","5"};
    char s_password[N][20]={"1","2","3","4","5"};
    char s_mailbox[N][10]={"1","2","3","4","5"};
    //  ��ʦ��������
    char t_id[N][10]={"1","2","3","4","5"};
    char t_department[N][10]={"1","2","3","4","5"};
    char t_name[N][20]={"1","2","3","4","5"};
    char t_mailbox[N][10]={"1","2","3","4","5"};
    char t_password[N][20]={"1","2","3","4","5"};
    //  �γ̲�������
    char c_id[N][7]={"1","2","3","4","5"};
    char c_name[N][20]={"1","2","3","4","5"};  
    int c_credit[N]={1,2,3,4,5};
    int c_period[N]={1,2,3,4,5}; 
    char c_characteristics[N][10]={"1","2","3","4","5"};  
    char c_teacher[N][20]={"1","2","3","4","5"};  
    char c_department[N][20]={"1","2","3","4","5"};
    int c_year1[N]={1,2,3,4,5}; 
    int c_year2[N]={1,2,3,4,5}; 
    int c_semester[N]={1,2,3,4,5};
    int c_week[N]={1,2,3,4,5};
    int c_time[N]={1,2,3,4,5};
    int c_building[N]={1,2,3,4,5};
    int c_room[N]={1,2,3,4,5};
    int c_limitation[N]={10,20,30,40,50};
    int c_selected[N]={1,2,3,4,5};
    char c_ioc[N][20]={"1","2","3","4","5"}; 
    char c_iom[N][20]={"1","2","3","4","5"};  

    teacher *fteacher=NULL, *new_teacher=NULL;
    student *fstudent=NULL, *new_student=NULL;
    course *t_fcourse=NULL,*t_focourse=NULL,*t_new_course=NULL,*t_np_c=NULL;    // ׼��������ʦ����γ�����
    course *s_fcourse=NULL,*s_focourse=NULL,*s_new_course=NULL,*s_np_c=NULL;    // ׼������ѧ��ѡ�޿γ�����
    
    for(i=0;i<5;i++)
    {
        new_teacher = create_tch(t_id,t_department,t_name,t_mailbox,t_password);
        fteacher = insertBeginning_tch(fteacher, new_teacher);
    }
    traversal_tch(fteacher);

    for(i=0;i<5;i++)
    {
        new_student = create_std(s_id,s_department,s_major,s_name,s_gender,s_phone_number,s_password,s_mailbox);
        fstudent = insertBeginning_std(fstudent, new_student);
    }
    traversal_std(fstudent);
    for(i=0;i<5;i++)
    {
        t_new_course = create_cos(c_id,c_name,c_credit,c_period,c_characteristics,c_teacher,c_department,c_year1,c_year2,c_semester,c_week,c_time,c_building,c_room,c_limitation,c_selected,c_ioc,c_iom);
        t_fcourse = insertBeginning_cos(t_fcourse, t_new_course);
    }
    traversal_cos(t_fcourse);

	menu1(fstudent,fteacher,t_fcourse,s_fcourse);

	return 0; 

}
teacher *create_tch(char id[][10],                      //  ����һ����ʦ���
                    char department[][10],
                    char name[][20],
                    char mailbox[][10],
                    char password[][20])
{
    static int i = 0;
    teacher *np;
    np = (teacher *) malloc(sizeof(teacher));
    strcpy(np->id, id[i]);
    strcpy(np->department, department[i]);
    strcpy(np->name, name[i]);
    strcpy(np->password, password[i]);
    strcpy(np->mailbox, mailbox[i]);
    np->next = NULL;
    i++;
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
course *create_cos(char id[][7],                    // ���������ݵ���һ���γ̽��
                    char name[][20],
                    int credit[],
                    int period[],
                    char characteristics[][10],
                    char teacher[][20],
                    char department[N][20],
                    int year1[],
                    int year2[],
                    int semester[],
                    int week[],
                    int time[],
                    int building[],
                    int room[],
                    int limitation[],
                    int selected[],
                    char ioc[][20],
                    char iom[][20])
{
    static int i = 0;
    course *np;
    np = (course *) malloc(sizeof(course));
    strcpy(np->id, id[i]);
    strcpy(np->name, name[i]);
    np->credit = credit[i];
    np->period = period[i];
    strcpy(np->characteristics, characteristics[i]);
    strcpy(np->teacher, teacher[i]);
    np->year1 = year1[i];
    np->year2 = year2[i];
    np->semester = semester[i];
    np->week = week[i];
    np->time = time[i];
    np->building = building[i];
    np->room = room[i];
    np->limitation = limitation[i];
    np->selected = selected[i];
    strcpy(np->ioc, ioc[i]);
    strcpy(np->iom, iom[i]);
    np->next = NULL;
    i++;
    return np;
}
course *tch_create_cos(course *t_fcourse)                    // ��ʦ�ֶ������γ̽��                
{
    course *np;
    np = (course *) malloc(sizeof(course));
    printf("������γ̱�ţ�\n");
    scanf("%s", np->id);
    printf("������γ����ƣ�\n");
    scanf("%s", np->name);
    printf("������γ�ѧ�֣�\n");  
    scanf("%d", &np->credit);
    printf("������γ�ѧʱ��\n");
    scanf("%d", &np->period);
    printf("������γ����ʣ�\n");
    scanf("%s", np->characteristics);
    printf("������γ̽�ʦ���ƣ�\n");
    scanf("%s", np->teacher);
    printf("�����뿪��ѧԺ��\n");
    gets(np->department);
    printf("�γ���ʼ��\n");
    printf("202*ѧ�ꣿ\n");
    scanf("%d", &np->year1);
    printf("��*ѧ�ڣ�\n");
    printf("1.��һѧ��\n");
    printf("2.�ڶ�ѧ��\n");
    scanf("%d", &np->semester);
    printf("��*�ܣ�\n");
    scanf("%d", &np->week);
    printf("�γ̽�����\n");
    printf("202*ѧ�ꣿ\n");
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
    printf("10:30-8:20\n");
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
    scanf("%s", np->ioc);
    printf("�̲���Ϣ��\n");
    scanf("%s", np->iom);    
    np->next = NULL;
    int a=0;
    a = tch_check_course(t_fcourse,np);
    if (a == 0)
    {
        return np;
    }
    else if (a == 1)
    {
        printf("�γ�ʱ�����ѿ���γ̳�ͻ\n");
    }
    else if (a == 2)
    {
        printf("�γ������ѿ���γ��ظ�\n");
    }
    else if (a == 3)
    {
        printf("�γ̺����ѿ���γ��ظ�\n");
    }
    else if (a == 4)
    {
        printf("����һλ��ʦ��ѧ�ڿ���γ���������2��\n");
    }
    return NULL;
}

void print_cos(course *np)  //  ��ӡĳ���γ̽��
{
    printf("�γ̱��: %s / �γ�����: %s / ѧ��: %d / ѧʱ: %d / �γ�����: %s / ������ʦ: %s / ", np->id, np->name, np->credit, np->period, np->characteristics, np->teacher);
    printf("����ѧԺ: %s / ", np->department);
    printf("�γ���ʼ�ڣ�202%d-202%dѧ���%dѧ�ڵ�%d�� / ", np->year1, np->year2, np->semester, np->week, np->time);
    printf("�γ̽����ڣ�202%d-202%dѧ���%dѧ�ڵ�%d�� / ", np->year1, np->year2, np->semester, np->week, np->time);
    printf("�Ͽεص�: ��%d¥-%d / ", np->building, np->room);
    printf("��������: %d / ѡ������: %d / ", np->limitation, np->selected);
    printf("�γ̼��: %s / �̲���Ϣ: %s \n", np->ioc, np->iom);
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
int tch_check_course(course *t_fcourse, course *new_node)
{
    course *np;
    np = t_fcourse;
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


course *search_cos(course *np, char key[20])             // ����ID�����γ�                                           
{
	while(np != NULL && strcmp(np->id, key) != 0)	// ����������һ���ڵ㣬ֱ���ҵ�idΪֹ�����ߵ�����ĩβ
	{
		np = np->next;
	}
	if (np != NULL)					// ��ĩβ�����ҵ�
	{
		printf("Found a course with ID = %s!\n", key);
		return np;
	}
	else
    {
        printf("Not Found!\n");
    }   
    return NULL;
}
int std_check_cos(course *fnode, course *new_node)                //  ���ѧ��ѡ���¿γ��Ƿ���Ϲ���
{
    course *np;
    np = fnode;
    int i=0;
    if (new_node->selected > new_node->limitation)
    {
        return 2;
    }
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
        else if (new_node->year1 == np->year1
                && new_node->year2 == np->year2
                && new_node->semester == np->semester)
        {
            i++;
            if (i > 3)
            {
                return 3;
            }
        }        
        else
        {
            np = np->next;
        }
    }
    return 0;
}
course *std_create_cos(course *np)               //  ����ѧ��ѡ�޿γ̽��
{
    course *new_course;

    new_course = (course *) malloc(sizeof(course));
    strcpy(new_course->id, np->id);
    strcpy(new_course->name, np->name);
    new_course->credit = np->credit;
    new_course->period = np->period;
    strcpy(new_course->characteristics, np->characteristics);
    strcpy(new_course->teacher, np->teacher);
    strcpy(new_course->department, np->department);
    new_course->year1 = np->year1;
    new_course->year2 = np->year2;
    new_course->semester = np->semester;
    new_course->week = np->week;
    new_course->time = np->time;
    new_course->building = np->building;
    new_course->room = np->room;
    new_course->limitation = np->limitation;
    new_course->selected = np->selected;
    strcpy(new_course->ioc, np->ioc);
    strcpy(new_course->iom, np->iom);

    new_course->next = NULL;
    return new_course;
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
    np->s_fcourse = (course *) malloc(sizeof(course));  //  ����ѧ��ѡ������ͷ���
    np->s_fcourse->next = NULL;
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





 
//  ѧ������
//  1.��½
void menu1(student *fstudent,teacher *fteacher, course *t_fcourse, course *s_fcourse)
{
    int choice=0;
	printf("--------[ѡ��ϵͳ]--------\n");
	printf("\t1.ѧ����½\n");
	printf("\t2.��ʦ��¼\n");
	printf("\t3.�˳�ϵͳ\n");
	printf("--------------------------\n");
    int flag=0;
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("--------[ѧ����¼]------\n");
		flag = std_checkAccountandPassword(fstudent);
        if (flag == 1)
        {
            choice = 0;
            studentmenu1(fstudent);
            scanf("%d", &choice);
            if (choice == 1)
            {
                //  ѧ��ѡ��
                std_select_cos(s_fcourse, t_fcourse);
                traversal_cos(s_fcourse);
            }
            else if (choice == 2)
            {
                //  ��ѯ�γ�
            }
            else if (choice == 3)
            {
                //  ��ѯѡ�ν��
            }
            else if (choice == 4)
            {
                //  ɾ��ѡ�ν��
            }
            else if (choice == 5)
            {
                //  ������Ϣ����
            }
            else 
            {
                studentmenu1(fstudent);
            }
        }
        else
	    {
            menu1(fstudent,fteacher,t_fcourse,s_fcourse);
	    }   
	}
    else if (choice == 2)
	{
		printf("--------[��ʦ��¼]------\n");
        flag = tch_checkAccountandPassword(fteacher);
        if (flag == 1)
        {
            teachermenu1(fteacher);
            scanf("%d", &choice);
            if (choice == 1)
            {
                //  ѡ�ι���
            }
            else if (choice == 2)
            {
                //  ͳ��ѡ����Ϣ
            }
            else if (choice == 3)
            {
                //  �γ̹���
            }
            else if (choice == 4)
            {
                //  ��ӿγ�
                tch_add_cos(t_fcourse);  
                traversal_cos(t_fcourse);  
            }
            else if (choice == 5)
            {
                //  �޸Ŀγ�
            }
            else if (choice == 6)
            {
                //  ɾ���γ�
            }
            else if (choice == 7)
            {
                //  ������Ϣ����
            }
            else
            {
                teachermenu1(fteacher);
            }
        }
        else
        {
            menu1(fstudent,fteacher,t_fcourse,s_fcourse);
        }
	}
}

void studentmenu1(student *fstudent)
{
	printf("--------[ѧ������]--------\n");
	printf("\t1.ѧ��ѡ��\n");  
	printf("\t2.��ѯ�γ�\n");
	printf("\t3.��ѯѡ�ν��\n");
	printf("\t4.ɾ��ѡ�ν��\n");
	printf("\t5.������Ϣ����\n");
	printf("\t6.�����ϼ��˵�\n");
	printf("--------------------------\n");

}
int std_checkAccountandPassword(student *np)
{
	char id[10],password[20];
	printf("�������ѧ��:\n");
	scanf("%s", &id);
	printf("�����������:\n");
    scanf("%s", &password);
	while(np!=NULL)
	{
		if(strcmp(id,np->id)!=0)
		{
			np=np->next;
		}
        else
        {
            if(strcmp(password,np->password) == 0)
		    {
			    printf("��½�ɹ���\n");
                return 1;
		    }
            else
            {
                printf("�û������������\n");
                return 0;
            }
        }
	}
    return 0;
}
//  2.ѧ��ѡ��
course *std_select_cos(course *s_fcourse, course *t_fcourse)  
{
    course *np, *new_course;
    char key[20];
    traversal_cos(t_fcourse);
    traversal_cos(s_fcourse);
    printf("���������Ȥ�γ̵�ID��\n");
    scanf("%s", &key);
    np = search_cos(t_fcourse, key);
    np->selected++;
    int a=0;
    a = std_check_cos(s_fcourse, np);
    if (a == 0)
    {
        new_course = std_create_cos(np);
        s_fcourse = insertBeginning_cos(s_fcourse, new_course); //  ����γ�����ͷ��
    }
    else if (a == 1)
    {
        printf("�γ�ʱ������ѡ�޿γ�ʱ���ͻ\n");
        np->selected--;
    }
    else if (a == 2)
    {
        printf("�γ�����\n");
        np->selected--;
    }
    else if (a == 3)
    {
        printf("����һ��ѧ����ѧ��ѡ�޿γ���������3��\n");
        np->selected--;
    }
    traversal_cos(s_fcourse);
    return s_fcourse;
}
void teachermenu1(teacher *fteacher)
{
    printf("--------[��ʦ����]--------\n");
	printf("\t1.ѡ�ι���\n");  
	printf("\t2.ͳ��ѡ����Ϣ\n");
	printf("\t3.�γ̹���\n");
	printf("\t4.��ӿγ�\n");
	printf("\t5.�޸Ŀγ�\n");
	printf("\t6.ɾ���γ�\n");
    printf("\t7.������Ϣ����\n");
    printf("\t8.�����ϼ��˵�\n");
	printf("--------------------------\n");
}
int tch_checkAccountandPassword(teacher *np)                    //  ��ʦ�˺��������
{
    char id[10],password[20];
	printf("������Ĺ���:\n");
	scanf("%s", &id);
	printf("�����������:\n");
    scanf("%s", &password);
	while(np!=NULL)
	{
		if(strcmp(id,np->id)!=0)
		{
			np=np->next;
		}
        else
        {
            if(strcmp(password,np->password) == 0)
		    {
			    printf("��½�ɹ���\n");
                return 1;
		    }
            else
            {
                printf("�û������������\n");
                return 0;
            }
        }
	}
    return 0;
}
course *tch_add_cos(course *t_fcourse)     //  ��ʦ���ܡ�����ӿγ�
{
    course *t_new_course;
    traversal_cos(t_fcourse);
    t_new_course = tch_create_cos(t_fcourse);
    t_fcourse = insertBeginning_cos(t_fcourse, t_new_course); 
    traversal_cos(t_fcourse);
    return t_fcourse;
}