#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

// 课程结构体
typedef struct course{
	char id[6];                 // 课程编号
	char name[20];              // 课程名称
    int credit;                 // 学分
    int period;                 // 学时
    char charateristics[10];    // 课程性质
    char teacher[20];           // 开课教师
    char time[20];              // 上课时间
    char place[20];             // 上课地点
    int limitation;             // 限制人数
    char ioc[20];               // "ioc" == "introduction of class"，课程简介
    char iom[20];               // "iom" == "information of material"，教材信息
	struct course *next;
} course;
// 学生结构体
typedef struct student{
	char id[10];                // 学号
	char department[10];        // 院系
	char major[10];             // 专业
	char name[20];              // 姓名
	char gender[10];            // 性别
	char phone_number[11];      // 电话
	char password[20];          // 密码
	char mailbox[10];           // 邮箱
	struct student *next;       
} student;
// 教师结构体
typedef struct teacher{
	char id[10];                // 工号
	char department[10];        // 院系
	char name[20];              // 姓名
	char mailbox[10];           // 邮箱
	char password[20];          // 密码
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
    // 测试数据
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
    np = (student *) malloc(sizeof(student));   // 动态分配内存，存放学生数据
    // printf("Please input id, department, major, name, gender, phone_number, password, mailbox: \n");
    // scanf("%s", &np->)
    
}