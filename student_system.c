//  学生功能：

//  第一页（刘天放）
//  1.登陆：输入学号和密码登陆系统。
//  2.学生选课：根据系统提供的课程进行浏览并可选择感兴趣的课程。
//          a.同一名学生的两门或多门课程之间时间不能冲突
//          b.规定一个学生一个学期最多能选3门课
//          c.每门课程选课人数不能超过限制人数
//  3.查询课程
//          a.根据课程名查询
//          b.根据开课学院查询
//          c.根据课余量排序所有课程
//          d.根据选课人数排序所有课程

//  第二页（朱雨轩）
//  4.查询选课结果
//          a.查看学生曾经选修过的课程
//  5.删除选课结果
//          a.在未开课之前学生可以删除自己的选课结果
//  6.个人信息管理
//          a.对个人信息中的电话、密码及邮箱进行修改


//  教师功能：

//  第三页（陈晓阳）
//  1.登陆：输入工号和密码登陆系统。
//  2.选课管理：
//          a.查看选课情况：
//                      ·查询教师自己开设过短的课程的选课情况（选课人数和课程详细信息）
//                      ·查询选择某门课程的学生信息（根据学生姓名或课程名称）
//          b.删除选课：
//                      ·选课结束后，如果某门课程的选课人数少于30，则删除该课程，所有选择该课程的学生选课信息删除
//  3.统计选课信息：
//          a.统计教师自己开设过的课程数目
//          b.按选课人数排序所有开设过的课程

//  第四页（周恺）
//  4.课程管理：针对教师自己开设的课程
//          a.查询所有开设的课程、根据课程名查询
//  5.添加课程：添加一门新的课程
//          a.同一名教师的上课时间不能冲突
//          b.课程名及课程号不能重复
//          c.同一名教师一个学期最多只能开两门选修课
//          d.课程的上限人数有两种选择：80人和100人
//  6.修改课程：
//          a.在一门课程尚未有学生选择时，可以修改：教材、课程简介、限制人数；
//          b.开始选课后，可以修改：限制人数。
//  7.删除课程：
//          a.未开始选课，可以进行删除操作。
//  8.个人信息管理：
//          a.对个人信息中的密码及邮箱进行修改


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
//  课程结构体
typedef struct course{
	char id[6];                 //  课程编号（6位数字）
	char name[20];              //  课程名称
    int credit;                 //  学分（可取范围数字1-4）
    int period;                 //  学时
    char charateristics[10];    //  课程性质
    char teacher[20];           //  开课教师
    char time[20];              //  上课时间（起止时间格式为：“202*-202*学年第*学期第*周”，
                                //  上课具体时间段：全天共计10个时间段，早8:00-11:50每50分钟一个时间段；下午1：30-5：20每50分钟一个时间段；晚6：30-8：20没50分钟一个时间段。课间休息均为10分钟。）

    char place[20];             //  上课地点（上课地点格式：“楼号-房间号。1表示教一楼，2表示教二楼。房间号为3为数字。）
    int limitation;             //  限制人数（80和100人）
    char ioc[20];               //  "ioc" == "introduction of class"，课程简介
    char iom[20];               //  "iom" == "information of material"，教材信息
	struct course *next;
} course;




//  学生结构体
typedef struct student{
	char id[10];                //  学号（10位数字）
	char department[10];        //  院系
	char major[10];             //  专业
	char name[20];              //  姓名
	char gender[10];            //  性别
	char phone_number[11];      //  电话（11位数字）
	char password[20];          //  密码
	char mailbox[10];           //  邮箱（符合***@***.***的规范）
    course *s_course;           //  连接学生与该学生已选课程的头指针
	struct student *next;       
} student;



//  教师结构体
typedef struct teacher{
	char id[10];                //  工号（10位数字）
	char department[10];        //  院系
	char name[20];              //  姓名
	char mailbox[10];           //  邮箱
	char password[20];          //  密码
    course *t_course;           //  连接教师与该教师教授课程的头指针
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
    // 测试数据
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
    np = (student *) malloc(sizeof(student));   // 动态分配内存，存放学生数据
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