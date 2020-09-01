/*Desc: Student system
    更新了课程信息中的上课时间和上课地点

Author: 
Date: 2020/9/1
*/


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
//  教师结构体
typedef struct teacher{
	char id[10];                //  工号（10位数字）
	char department[10];        //  院系
	char name[20];              //  姓名
	char mailbox[10];           //  邮箱
	char password[20];          //  密码 
	struct teacher *next;   
} teacher;

//  课程结构体                                                
typedef struct course{
	char id[6];                 //  课程编号（6位数字）
	char name[20];              //  课程名称
    int credit;                 //  学分（可取范围数字1-4）
    int period;                 //  学时
    char characteristics[10];   //  课程性质
    char teacher[20];           //  开课教师
                                //  上课时间（起止时间格式为：“202*-202*学年第*学期第*周”）
    int year1;                  //  year选择范围为0-9
    int year2;
    int semester;               //  semester选择范围为1-2
    int week;                   //  week选择范围为01-20
                                //  上课具体时间段：全天共计10个时间段，早8:00-11:50每50分钟一个时间段；下午1：30-5：20每50分钟一个时间段；晚6：30-8：20没50分钟一个时间段。课间休息均为10分钟。）
    int time[10];               //  time选择范围为01-10
                                //  上课地点（上课地点格式：“楼号-房间号。1表示教一楼，2表示教二楼。房间号为3位数字。）
    int building;               //  楼号
    int room;                   //  房间号
    int limitation;             //  限制人数（80和100人）
    int selected;               //  课程已选人数
    char ioc[20];               //  "ioc" == "introduction of course"，课程简介
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
	struct student *next;       
} student;

//  教师链表基本操作
teacher *create_tch(char id[][10],                  //  创建一个教师结点
                    char department[][10],
                    char name[][20],
                    char mailbox[10],
                    char password[][20]);
void print_tch(teacher *np);                        //  打印某个教师结点
void traversal_tch(teacher *fnode);                 //  遍历并打印所有教师结点
teacher *insertBeginning_tch(teacher *fnode, teacher *newnode); //  插入教师结点头部
void searchcource(course *np, char key);            //  课程管理：a.查询所有开设的课程、根据课程名查询

//  课程链表基础操作
course *create_cos(char id[][6],                    // 从已有数据导入一个课程结点
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
course *tch_create_cos(course *fnode);                              //  教师手动创建课程结点
void print_cos(course *np);                         //  打印某个课程结点
void traversal_cos(course *fnode);                  //  遍历并打印所有课程
course *insertBeginning_cos(course *fnode, course *newnode);    //  插入课程链表头部
int check_t_course(course *fnode, course *new_node);

//  学生链表基础操作
student *create_std(char id[][10],                  //  创建一个学生结点
                    char department[][10],
                    char major[][10],
                    char name[][20],
                    char gender[][10],
                    char phone_number[][11],
                    char password[][20],
                    char mailbox[][10]);
void print_std(student *np);                        //  打印某个学生结点
void traversal_std(student *fnode);                 //  遍历并打印所有学生结点
student *insertBeginning_std(student *fnode, student *newnode);  //  插入学生链表头部

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


    student *fstudent=NULL,*fostudent=NULL,*new_student=NULL,*np_s=NULL;    //  准备建立学生档案链表
    teacher *fteacher=NULL,*foteacher=NULL,*new_teacher=NULL,*np_t=NULL;    //  准备建立教师档案链表
    course *t_fcourse=NULL,*t_focourse=NULL,*t_new_course=NULL,*t_np_c=NULL;    // 准备建立教师开设课程链表
    course *s_fcourse=NULL,*s_focourse=NULL,*s_new_course=NULL,*s_np_c=NULL;    // 准备建立学生选修课程链表
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


void print_std(student *np) //  打印某个学生结点
{
    printf("ID: %s / Department: %s / Major: %s / Name: %s / Gender: %s / Phone number: %s / Password: %s / Mailbox: %s\n", np->id, np->department, np->major, np->name, np->gender, np->phone_number, np->password, np->mailbox);
}

void traversal_std(student *fnode)  //  遍历并打印所有学生结点
{
    student *np = fnode;
    while(np != NULL)
    {
        print_std(np);
        np = np->next;
    }
}

student *insertBeginning_std(student *fnode, student *newnode)  //  插入学生链表头部  
{
    newnode->next = fnode;
    fnode = newnode;
    return fnode;
}
course *create_cos(char id[][6],                    // 从已有数据导入一个课程结点
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
        输入


    */
    np->next = NULL;
    return np;
}
course *tch_create_cos(course *fnode)                    // 教师手动创建课程结点                
{
    course *np;
    np = (course *) malloc(sizeof(course));
    printf("请输入课程编号：\n");
    scanf("%s", &np->id);
    printf("请输入课程名称：\n");
    scanf("%s", &np->name);
    printf("请输入课程学分：\n");
    scanf("%d", &np->credit);
    printf("请输入课程学时：\n");
    scanf("%d", &np->period);
    printf("请输入课程性质：\n");
    scanf("%s", &np->characteristics);
    printf("请输入课程教师名称：\n");
    scanf("%s", &np->teacher);
    printf("课程起始于202*学年？\n");
    scanf("%d", &np->year1);
    printf("课程结束于202*学年？\n");
    scanf("%d", &np->year2);
    printf("第*学期？\n");
    printf("1.第一学期\n");
    printf("2.第二学期\n");
    scanf("%d", &np->semester);
    printf("第*周？\n");
    scanf("%d", &np->week);
    printf("请选择课程时间段\n");
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
    printf("教*楼？\n");
    scanf("%d", &np->building);
    printf("房间号？\n");
    scanf("%d", &np->room);
    printf("限制人数选择：\n");
    printf("1.80\n");
    printf("2.100\n");
    scanf("%d", &np->limitation);
    printf("课程简介：\n");
    scanf("%s", &np->ioc);
    printf("教材信息：\n");
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
        printf("课程时间与已开设课程冲突");
    }
    else if(a == 2)
    {
        printf("课程名与已开设课程重复");
    }
    else if(a == 3)
    {
        printf("课程号与已开设课程重复");
    }
    else if(a == 4)
    {
        printf("超出一位教师单学期开设课程上限数（2）");
    }
    return NULL;
}

void print_cos(course *np)  //  打印某个课程结点
{
    printf("ID: %s / Name: %s / Credit: %d / Period: %d / Characteristics: %s / Teacher: %s / Time: 202%d-202%d学年第%d学期第%d周 / Place: 教%d楼-%d / Limitation: %d / Selected: %d / Introduction of course: %s / Information of material: %s\n", np->id, np->name, np->credit, np->period, np->characteristics, np->teacher, np->year1, np->year2, np->semester, np->week, np->time, np->building, np->room, np->limitation, np->selected, np->ioc, np->iom);
}
void traversal_cos(course *fnode)   //  遍历并打印所有课程
{
    course *np = fnode; 
    while(np != NULL)
    {
        print_cos(np);
        np = np->next;
    }
}
course *insertBeginning_cos(course *fnode, course *newnode) //  插入课程链表头部
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
teacher *create_tch(char id[][10],                  //  创建一个教师结点
                    char department[][10],
                    char name[][20],
                    char mailbox[10],
                    char password[][20])
{
    teacher *np;
    np = (teacher *) malloc(sizeof(teacher));
    /*
        输入


    */
    np->next = NULL;
    return np;
}
void print_tch(teacher *np) //  打印某个教师结点
{
    printf("ID: %s / Department: %s / Name: %s / Mailbox: %s / Password: %s\n", np->id, np->department, np->name, np->mailbox, np->password);
}                        
void traversal_tch(teacher *fnode)  //  遍历并打印所有教师
{
    teacher *np = fnode; 
    while(np != NULL)
    {
        print_tch(np);
        np = np->next;
    }
}               
teacher *insertBeginning_tch(teacher *fnode, teacher *newnode)  //  插入教师链表头部
{
    newnode->next = fnode; 
    fnode = newnode;
    return fnode;
} 


void searchcource(cos *np, char key)

{

	while(np != NULL && np->name !=key)	// 不断搜索下一个节点，直到找到name为止，或者到链表末尾

	{

		np = np->next;

	}

	if (np != NULL)					// 非末尾，即找到

	{

	print_cos(course *np);

	}

	else

		printf("Not Found!\n");

}