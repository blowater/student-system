#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

// �γ̽ṹ��
typedef struct course{
	char id[6];                 // �γ̱��
	char name[20];              // �γ�����
    int credit;                 // ѧ��
    int period;                 // ѧʱ
    char charateristics[10];    // �γ�����
    char teacher[20];           // ���ν�ʦ
    char time[20];              // �Ͽ�ʱ��
    char place[20];             // �Ͽεص�
    int limitation;             // ��������
    char ioc[20];               // "ioc" == "introduction of class"���γ̼��
    char iom[20];               // "iom" == "information of material"���̲���Ϣ
	struct course *next;
} course;
// ѧ���ṹ��
typedef struct student{
	char id[10];                // ѧ��
	char department[10];        // Ժϵ
	char major[10];             // רҵ
	char name[20];              // ����
	char gender[10];            // �Ա�
	char phone_number[11];      // �绰
	char password[20];          // ����
	char mailbox[10];           // ����
	struct student *next;       
} student;
// ��ʦ�ṹ��
typedef struct teacher{
	char id[10];                // ����
	char department[10];        // Ժϵ
	char name[20];              // ����
	char mailbox[10];           // ����
	char password[20];          // ����
	struct teacher *next;
} teacher;


student *create_student(char id[10],
                        char department[10],
                        char major[10],
                        char name[10],
                        char gender[10],
                        char phone_number[11],
                        char password[20],
                        char mailbox[10]);

int main()
{
    // ��������
    char ids[N][10]={"1","2","3","4","5"};
    char department[N][10]={"1","2","3","4","5"};
    char major[N][10]={"1","2","3","4","5"};
    char name[N][20]={"1","2","3","4","5"};
    char gender[N][10]={"1","2","1","2","1"};
    char phone_number[11]={"1","2","3","4","5"};
    char password[N][20]={"1","2","3","4","5"};
    char mailbox[N][10]={"1","2","3","4","5"};


    student *fnode=NULL,*fonode=NULL,*newnode=NULL,*np=NULL;
    int i;
    int key;

    
}

student *create_student(char id[10],
                        char department[10],
                        char major[10],
                        char name[10],
                        char gender[10],
                        char phone_number[11],
                        char password[20],
                        char mailbox[10])
{
    student *np;
    np = (student *) malloc(sizeof(student));   // ��̬�����ڴ棬���ѧ������
    // printf("Please input id, department, major, name, gender, phone_number, password, mailbox: \n");
    // scanf("%s", &np->)
    
}