/*Desc: Student system

    学生选课，添加课程

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

	char id[7];                 //  课程编号（6位数字）

	char name[20];              //  课程名称

    int credit;                 //  学分（可取范围数字1-4）

    int period;                 //  学时

    char characteristics[10];   //  课程性质

    char teacher[20];           //  开课教师

    char department[20];        //  开课学院

                                //  上课时间（起止时间格式为：“202*-202*学年第*学期第*周”）

    int year1;                  //  year选择范围为0-9

    int year2;

    int semester;               //  semester选择范围为1-2

    int week;                   //  week选择范围为01-20

                                //  上课具体时间段：全天共计10个时间段，早8:00-11:50每50分钟一个时间段；下午1：30-5：20每50分钟一个时间段；晚6：30-8：20没50分钟一个时间段。课间休息均为10分钟。）

    int time;                   //  time选择范围为01-10

                                //  上课地点（上课地点格式：“楼号-房间号。1表示教一楼，2表示教二楼。房间号为3位数字。）

    int building;               //  楼号

    int room;                   //  房间号

    int limitation;             //  限制人数（80和100人）

    int selected;               //  选课人数

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

    course *s_fcourse;          //  学生已选课程链表头指针

	struct student *next;       

} student;



//  教师档案链表基础操作

teacher *create_tch(char id[][10],                                      //  创建一个教师结点

                    char department[][10],

                    char name[][20],

                    char mailbox[][10],

                    char password[][20]);

void print_tch(teacher *np);                                            //  打印某个教师结点

void traversal_tch(teacher *fnode);                                     //  遍历并打印所有教师结点

teacher *insertBeginning_tch(teacher *fnode, teacher *newnode);         //  插入教师结点头部







//  教师开设课程链表基础操作

course *create_cos(char id[][7],                                        // 从原始数据导入一个课程结点

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

course *tch_create_cos(course *t_fcourse);                              //  手动创建教师开设课程结点

void print_cos(course *np);                                             //  打印某个课程结点

void traversal_cos(course *fnode);                                      //  遍历并打印所有课程

course *insertBeginning_cos(course *fnode, course *newnode);            //  插入课程链表头部

int tch_check_course(course *fnode, course *new_node);                  //  检查教师开设新课程是否符合规则

course *search_cos(course *np, char key[20]);                           //  根据ID搜索课程





//  学生选修课程链表基础操作

int std_check_cos(course *fnode, course *new_node);                     //  检查学生选修新课程是否符合规则

course *std_create_cos(course *np);                                     //  复制学生选修课程结点



//  学生档案链表基础操作

student *create_std(char id[][10],                                      //  创建一个学生结点

                    char department[][10],

                    char major[][10],

                    char name[][20],

                    char gender[][10],

                    char phone_number[][11],

                    char password[][20],

                    char mailbox[][10]);

void print_std(student *np);                                            //  打印某个学生结点

void traversal_std(student *fnode);                                     //  遍历并打印所有学生结点

student *insertBeginning_std(student *fnode, student *newnode);         //  插入学生链表头部

//  学生功能：

//      1.登陆

void menu1(student *fstudent,teacher *fteacher, course *t_fcourse, course *s_fcourse);

void studentmenu1(student *fstudent);                           //  学生功能菜单        

int std_checkAccountandPassword(student *np);                   //  学生账号密码检验

//      2.学生选课

void std_select_cos(course *s_fcourse, course *t_fcourse);     

//      3.查询课程

void studdentmenu2(student *fstudent, course *t_course);        //  学生查询课程二级菜单

void search_cos_name(course *t_fcourse);            //  根据课程名搜索课程

void search_cos_department(course *t_fcourse);    //  根据开课学院搜索课程

void order_margin(course *t_fcourse);                   //  根据课余量排序 

void order_selected(course *t_fcourse);                  //  根据选课人数排序 



//  教师功能：

//      1.登陆

void teachermenu1(teacher *fteacher);                           //  教师账号菜单

int tch_checkAccountandPassword(teacher *np);                   //  教师账号密码检验

//      2.选课管理

        //  a.查看选课情况：

void tch_checkcourse(course *t_fcourse);                        //  查询教师自己开设过短的课程的选课情况（选课人数和课程详细信息）

void tch_checkstudent(course *t_fcourse);                       //  查询某门课程的学生信息

        //  b.删除选课    

//      5.添加课程

void *tch_add_cos(course *t_course); 



/*

int main()

{

    // 学生测试数据

    char s_id[N][10]={"1","2","3","4","5"};

    char s_department[N][10]={"1","2","3","4","5"};

    char s_major[N][10]={"1","2","3","4","5"};

    char s_name[N][20]={"1","2","3","4","5"};

    char s_gender[N][10]={"1","2","1","2","1"};    

    char s_phone_number[N][11]={"1","2","3","4","5"};

    char s_password[N][20]={"1","2","3","4","5"};

    char s_mailbox[N][10]={"1","2","3","4","5"};

    //  教师测试数据

    char t_id[N][10]={"1","2","3","4","5"};

    char t_department[N][10]={"1","2","3","4","5"};

    char t_name[N][20]={"1","2","3","4","5"};

    char t_mailbox[N][10]={"1","2","3","4","5"};

    char t_password[N][20]={"1","2","3","4","5"};

    //  课程测试数据

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

    // student *fstudent=NULL/*学生链表头指针*/,*fostudent=NULL,*new_student=NULL,*np_s=NULL;    //  准备建立学生档案链表

    // teacher *fteacher=NULL/*教师链表头指针*/,*foteacher=NULL,*new_teacher=NULL,*np_t=NULL;    //  准备建立教师档案链表

    // course *t_fcourse=NULL/*教师课程链表头指针*/,*t_focourse=NULL,*t_new_course=NULL,*t_np_c=NULL;    // 准备建立教师开设课程链表

    // course *s_fcourse=NULL/*学生课程链表头指针*/,*s_focourse=NULL,*s_new_course=NULL,*s_np_c=NULL;    // 准备建立学生选修课程链表

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



    // 学生测试数据

    char s_id[N][10]={"1","2","3","4","5"};

    char s_department[N][10]={"1","2","3","4","5"};

    char s_major[N][10]={"1","2","3","4","5"};

    char s_name[N][20]={"1","2","3","4","5"};

    char s_gender[N][10]={"1","2","1","2","1"};    

    char s_phone_number[N][11]={"1","2","3","4","5"};

    char s_password[N][20]={"1","2","3","4","5"};

    char s_mailbox[N][10]={"1","2","3","4","5"};

    //  教师测试数据

    char t_id[N][10]={"1","2","3","4","5"};

    char t_department[N][10]={"1","2","3","4","5"};

    char t_name[N][20]={"1","2","3","4","5"};

    char t_mailbox[N][10]={"1","2","3","4","5"};

    char t_password[N][20]={"1","2","3","4","5"};

    //  课程测试数据

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

    course *t_fcourse=NULL,*t_focourse=NULL,*t_new_course=NULL,*t_np_c=NULL;    // 准备建立教师开设课程链表

    course *s_fcourse=NULL,*s_focourse=NULL,*s_new_course=NULL,*s_np_c=NULL;    // 准备建立学生选修课程链表

    

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

teacher *create_tch(char id[][10],                      //  创建一个教师结点

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

void print_tch(teacher *np) //  打印某个教师结点

{

   printf("工号: %s / 院系: %s / 姓名: %s / 邮箱: %s / 密码: %s\n", np->id, np->department, np->name, np->mailbox, np->password);

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

course *create_cos(char id[][7],                    // 从已有数据导入一个课程结点

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

    strcpy(np->department, department[i]);

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

course *tch_create_cos(course *t_fcourse)                    // 教师手动创建课程结点                

{

    course *np;

    np = (course *) malloc(sizeof(course));

    printf("请输入课程编号：\n");

    scanf("%s", np->id);

    printf("请输入课程名称：\n");

    scanf("%s", np->name);

    printf("请输入课程学分：\n");  

    scanf("%d", &np->credit);

    printf("请输入课程学时：\n");

    scanf("%d", &np->period);

    printf("请输入课程性质：\n");

    scanf("%s", np->characteristics);

    printf("请输入课程教师名称：\n");

    scanf("%s", np->teacher);

    printf("请输入开课学院：\n");

    gets(np->department);

    printf("课程起始于\n");

    printf("202*学年？\n");

    scanf("%d", &np->year1);

    printf("第*学期？\n");

    printf("1.第一学期\n");

    printf("2.第二学期\n");

    scanf("%d", &np->semester);

    printf("第*周？\n");

    scanf("%d", &np->week);

    printf("课程结束于\n");

    printf("202*学年？\n");

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

    printf("10:30-8:20\n");

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

    scanf("%s", np->ioc);

    printf("教材信息：\n");

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

        printf("课程时间与已开设课程冲突\n");

    }

    else if (a == 2)

    {

        printf("课程名与已开设课程重复\n");

    }

    else if (a == 3)

    {

        printf("课程号与已开设课程重复\n");

    }

    else if (a == 4)

    {

        printf("超出一位教师单学期开设课程上限数（2）\n");

    }

    return NULL;

}



void print_cos(course *np)  //  打印某个课程结点

{

    printf("课程编号: %s / 课程名称: %s / 学分: %d / 学时: %d / 课程性质: %s / 开课老师: %s / ", np->id, np->name, np->credit, np->period, np->characteristics, np->teacher);

    printf("开课学院: %s / ", np->department);

    printf("课程起始于：202%d-202%d学年第%d学期第%d周 / ", np->year1, np->year2, np->semester, np->week, np->time);

    printf("课程结束于：202%d-202%d学年第%d学期第%d周 / ", np->year1, np->year2, np->semester, np->week, np->time);

    printf("上课地点: 教%d楼-%d / ", np->building, np->room);

    printf("限制人数: %d / 选课人数: %d / ", np->limitation, np->selected);

    printf("课程简介: %s / 教材信息: %s \n", np->ioc, np->iom);

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

int tch_check_course(course *t_fcourse, course *new_node)

{

    course *np;

    np = t_fcourse;

    int i=0;

    while(np != NULL)

    {

        if(new_node->teacher == np->teacher)

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

        }

        else

        {

            np = np->next;

        }

    }

    return 0;

}





course *search_cos(course *np, char key[20])             // 根据ID搜索课程                                           

{

	while(np != NULL && strcmp(np->id, key) != 0)	// 不断搜索下一个节点，直到找到id为止，或者到链表末尾

	{

		np = np->next;

	}

	if (np != NULL)					// 非末尾，即找到

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

int std_check_cos(course *fnode, course *new_node)                //  检查学生选修新课程是否符合规则

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

course *std_create_cos(course *np)               //  创建学生选修课程结点

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

    np = (student *) malloc(sizeof(student));   // 动态分配内存，存放学生数据

    strcpy(np->id, id[i]);

    strcpy(np->department, department[i]);

    strcpy(np->major, major[i]);

    strcpy(np->name, name[i]);

    strcpy(np->gender, gender[i]);

    strcpy(np->phone_number, phone_number[i]);

    strcpy(np->password, password[i]);

    strcpy(np->mailbox, mailbox[i]);

    np->s_fcourse = (course *) malloc(sizeof(course));  //  创建学生选课链表头结点

    np->s_fcourse->next = NULL;

    np->next = NULL;

    i++;

    return np;

}



void print_std(student *np) //  打印某个学生结点

{

    printf("学号: %s / 院系: %s / 专业: %s / 姓名: %s / 性别: %s / 电话: %s / 密码: %s / 邮箱: %s\n", np->id, np->department, np->major, np->name, np->gender, np->phone_number, np->password, np->mailbox);

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











 

//  学生功能

//  1.登陆

void menu1(student *fstudent,teacher *fteacher, course *t_fcourse, course *s_fcourse)

{

    int choice=0;

	printf("--------[选课系统]--------\n");

	printf("\t1.学生登陆\n");

	printf("\t2.教师登录\n");

	printf("\t3.退出系统\n");

	printf("--------------------------\n");

    int flag=0;

	scanf("%d", &choice);

	if (choice == 1)

	{

		printf("--------[学生登录]------\n");

		flag = std_checkAccountandPassword(fstudent);

        if (flag == 1)

        {

            choice = 0;

            studentmenu1(fstudent);

            scanf("%d", &choice);

            if (choice == 1)

            {

                //  学生选课

                std_select_cos(s_fcourse, t_fcourse);

            }

            else if (choice == 2)

            {

                //  查询课程

                studdentmenu2(fstudent, t_fcourse);

                int i=0;

                scanf("%d", &i);

                if (i == 1)

                {

                    search_cos_name(t_fcourse);   

                }  

                else if (i == 2)

                {

                    search_cos_department(t_fcourse); 

                }

                else if (i == 3)

                {

                    order_margin(t_fcourse);  

                }

                else if (i == 4)

                {

                    order_selected(t_fcourse); 
 

                }

            }

            else if (choice == 3)

            {

                //  查询选课结果

            }

            else if (choice == 4)

            {

                //  删除选课结果

            }

            else if (choice == 5)

            {

                //  个人信息管理

            }

            else

            {

                menu1(fstudent,fteacher,t_fcourse,s_fcourse);

            }

            

        }

        else

	    {

            menu1(fstudent,fteacher,t_fcourse,s_fcourse);

	    }   

	}

    else if (choice == 2)

	{

		printf("--------[教师登录]------\n");

        flag = tch_checkAccountandPassword(fteacher);

        if (flag == 1)

        {

            teachermenu1(fteacher);

            scanf("%d", &choice);

            if (choice == 1)

            {

                //  选课管理

            }

            else if (choice == 2)

            {

                //  统计选课信息

            }

            else if (choice == 3)

            {

                //  课程管理

            }

            else if (choice == 4)

            {

                //  添加课程

                tch_add_cos(t_fcourse);   

            }

            else if (choice == 5)

            {

                //  修改课程

            }

            else if (choice == 6)

            {

                //  删除课程

            }

            else if (choice == 7)

            {

                //  个人信息管理

            }

            else

            {

                menu1(fstudent,fteacher,t_fcourse,s_fcourse);

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

	printf("--------[学生功能]--------\n");

	printf("\t1.学生选课\n");  

	printf("\t2.查询课程\n");

	printf("\t3.查询选课结果\n");

	printf("\t4.删除选课结果\n");

	printf("\t5.个人信息管理\n");

	printf("\t6.返回上级菜单\n");

	printf("--------------------------\n");



}

int std_checkAccountandPassword(student *np)

{

	char id[10],password[20];

	printf("输入你的学号:\n");

	scanf("%s", &id);

	printf("输入你的密码:\n");

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

			    printf("登陆成功！\n");

                return 1;

		    }

            else

            {

                printf("用户名或密码错误\n");

                return 0;

            }

        }

	}

    return 0;

}



//  2.学生选课

void std_select_cos(course *s_fcourse, course *t_fcourse)  

{

    course *np, *new_course;

    char key[20];

    traversal_cos(t_fcourse);

    traversal_cos(s_fcourse);

    printf("请输入感兴趣课程的ID：\n");

    scanf("%s", &key);

    np = search_cos(t_fcourse, key);

    np->selected++;

    int a=0;

    a = std_check_cos(s_fcourse, np);

    if (a == 0)

    {

        new_course = std_create_cos(np);

        s_fcourse = insertBeginning_cos(s_fcourse, new_course); //  插入课程链表头部

    }

    else if (a == 1)

    {

        printf("课程时间与已选修课程时间冲突\n");

        np->selected--;

    }

    else if (a == 2)

    {

        printf("课程人满\n");

        np->selected--;

    }

    else if (a == 3)

    {

        printf("超出一名学生单学期选修课程上限数（3）\n");

        np->selected--;

    }

    traversal_cos(s_fcourse);



}

void studdentmenu2(student *fstudent, course *t_course)         //  学生查询课程耳机菜单

{

    printf("--------[查询课程]--------\n");

	printf("\t1.根据课程名查询\n");  

	printf("\t2.根据开课学院查询\n");

	printf("\t3.根据课余量排序所有课程\n");

	printf("\t4.根据选课人数排序所有课程\n");

	printf("\t5.返回上级菜单\n");

	printf("--------------------------\n");

}

void search_cos_name(course *t_fcourse)             //根据课程名搜索课程

{

    course *np;

    np = t_fcourse;

    char CourseName[20];

	printf("请输入课程名称：\n");

	scanf("%s", &CourseName);

	while(np != NULL && strcmp(np->name, CourseName) != 0)	// 不断搜索下一个节点，直到找到课程名为止，或者到链表末尾

	{

		np = np->next;

	}

	if (np != NULL)					// 非末尾，即找到

	{

		print_cos(np); //打印课程内容 

	}

	else

    {

        printf("不存在该课程名的课程!\n");

    }   

}

void search_cos_department(course *t_fcourse) //  根据开课学院搜索课程

{

    course *np;

    np = t_fcourse;

    char department[20]; 

	printf("请输入开课学院名称：\n");

	scanf("%s", &department);

    int flag=0;

	while(np != NULL)	// 不断搜索下一个节点，直到找到开课学院为止，或者到链表末尾

	{

        if (strcmp(np->department, department) == 0)					// 非末尾，即找到

	    {

		    print_cos(np); //打印课程内容 

            flag = 1;

        }

		np = np->next;

	}

    if (flag == 0)

    {

        printf("此学院并无开课。\n");

    }

}

void order_margin(course *t_fcourse)                  //  根据课余量排序

{

    course *first=NULL; //排列后有序链的表头指针

	course *tail=NULL; //排列后有序链的表尾指针

	course *p_min=NULL; //保留键值更小的节点的前驱节点的指针

	course *min=NULL; //存储最小节点

	course *p=NULL; //当前比较的节点

    course *temp;

    temp = t_fcourse;

	first = NULL;

	while(temp!=NULL)

	{

		for(p=temp,min=temp;p->next!=NULL;p=p->next)//遍历所有节点 

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

		if(min==temp)//使原链表中min脱离 

		{

			temp = temp->next; 

		}

		else

		{

			p_min->next = min->next;//前驱节点指向min的下一个节点，min可分离出原链表 

		}

		

	}
        if(first!=NULL)//循环结束后令尾指针的next为NULL 

		{

			tail->next = NULL; 

		}

		temp = first;		
    traversal_cos(first);

}
void order_selected(course *t_fcourse)                //  根据选课人数排序

{

    course *first; //排列后有序链的表头指针

	course *tail; //排列后有序链的表尾指针

	course *p_min; //保留键值更小的节点的前驱节点的指针

	course *min; //存储最小节点

	course *p; //当前比较的节点

    course *temp;

    temp = t_fcourse;

	first = NULL;

	while(temp!=NULL)

	{

		for(p=temp,min=temp;p->next!=NULL;p=p->next)//遍历所有节点 

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

		if(min==temp)//使原链表中min脱离 

		{

			temp = temp->next; 

		}

		else

		{

			p_min->next = min->next;//前驱节点指向min的下一个节点，min可分离出原链表 

		}


	}
		if(first!=NULL)//循环结束后令尾指针的next为NULL 

		{

			tail->next = NULL; 

		}
		temp=first;
    traversal_cos(first);

}



void teachermenu1(teacher *fteacher)

{

    printf("--------[教师功能]--------\n");

	printf("\t1.选课管理\n");  

	printf("\t2.统计选课信息\n");

	printf("\t3.课程管理\n");

	printf("\t4.添加课程\n");

	printf("\t5.修改课程\n");

	printf("\t6.删除课程\n");

    printf("\t7.个人信息管理\n");

    printf("\t8.返回上级菜单\n");

	printf("--------------------------\n");

}

int tch_checkAccountandPassword(teacher *np)                    //  教师账号密码检验

{

    char id[10],password[20];

	printf("输入你的工号:\n");

	scanf("%s", &id);

	printf("输入你的密码:\n");

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

			    printf("登陆成功！\n");

                return 1;

		    }

            else

            {

                printf("用户名或密码错误\n");

                return 0;

            }

        }

	}

    return 0;

}

void tch_checkcourse(course *t_fcourse)

{

    course *np = t_fcourse;



}

void *tch_add_cos(course *t_fcourse)     //  教师功能——添加课程

{

    course *t_new_course;

    traversal_cos(t_fcourse);

    t_new_course = tch_create_cos(t_fcourse);

    t_fcourse = insertBeginning_cos(t_fcourse, t_new_course); 

    traversal_cos(t_fcourse);

    return t_fcourse;

}

/*

void search_s_courser result(course*np,char key,student*student)  //查询选课结果 

{ 

    printf("请输入您的姓名\n");

	scanf("%c",&key);

	while(student->name!=key&&student!=NULL)

	{

		student=student->next;

	} 

	if(student!=NULL)

	{

		np=student->course;

	 	while(np!=NULL)

	 	{

	 		void print_cos(np);

	 		np=np->next;

		}

	}

	else

	{

	 	printf("未找到"); 

	} 

}





void change_s_i(student*fostudent, char key) 

{

	printf("请输入您的姓名\n");

	scanf("%c",&key);

	while(student->name!=key&&student!=NULL)

	{

		student=student->next;

	 } 

	 if(student!=NULL)

	 {

	 	printf("请输入您的新电话号码.\n");

	 	student->phone_number=key;

	 	printf("请输入您的新邮箱.\n");

	 	student->mailbox=key;

		scanf("%c",&key);

		printf("请输入您的新密码.\n");

		student->password=key; 

		scanf("%c",&key);

	 }

	 else

	 {

	 	printf("未找到"); 

	  } 

}

void delete_s_courser result(course*np ,course*nb ,char key,student*student ,char searchname[20])  //查询选课结果 

{ 

    printf("请输入您的姓名\n");

	scanf("%c",&key);

	student = fostudent;

	while(student->name != key&&student!=NULL)

	{

		student = student->next;

	} 

	if(student!=NULL)

	{

		printf("请输入你要删除的课程")

		scanf("%c",&searchname); 

		np = student->course;

	 	while(np!=NULL)

	 	{

	 		nb = np;

	 		np = np->next;

	 		if(np->name == searchname)

	 		{

	 			nb->next = np->next;

	 			free(np);

	 			printf("删除成功。")

			 }

			 if(np == NULL)

			 {

			 	printf("课程未被选。"); 

			 }

		}

	}

	else

	{

	 	printf("未找到"); 

	} 

}

*/


