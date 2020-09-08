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
	char id[11];                //  工号（10位数字）
	char department[50];        //  院系
	char name[30];              //  姓名
	char mailbox[50];           //  邮箱
	char password[50];          //  密码 
	struct teacher *next;   
} teacher;

//  课程结构体                                                
typedef struct course{
	char id[7];                 //  课程编号（6位数字）
	char name[50];              //  课程名称
    int credit;                 //  学分（可取范围数字1-4）
    int period;                 //  学时
    char characteristics[20];   //  课程性质
    char teacher[50];           //  开课教师
    char department[50];        //  开课学院
                                //  上课时间（起止时间格式为：“202*-202*学年第*学期第*周”）
    int year1;                  //  year选择范围为0-9
    int year2;
    int semester1;               //  semester选择范围为1-2
    int semester2;
    int week1;                   //  week选择范围为1-20
    int week2;
                                //  上课具体时间段：全天共计10个时间段，早8:00-11:50每50分钟一个时间段；下午1：30-5：20每50分钟一个时间段；晚6：30-8：20没50分钟一个时间段。课间休息均为10分钟。）
    int time;                   //  time选择范围为1-10
                                //  上课地点（上课地点格式：“楼号-房间号。1表示教一楼，2表示教二楼。房间号为3位数字。）
    int building;               //  楼号
    int room;                   //  房间号
    int limitation;             //  限制人数（80和100人）
    int selected;               //  选课人数
    char ioc[200];               //  "ioc" == "introduction of course"，课程简介
    char iom[200];               //  "iom" == "information of material"，教材信息
	struct course *next;
} course;

//  学生结构体
typedef struct student{
	char id[11];                //  学号（10位数字）
	char department[50];        //  院系
	char major[50];             //  专业
	char name[30];              //  姓名
	int gender;            //  性别
	char phone_number[12];      //  电话（11位数字）
	char password[50];          //  密码
	char mailbox[50];           //  邮箱（符合***@***.***的规范）
    course *s_fcourse;          //  学生已选课程链表头指针
	struct student *next;       
} student;

//  教师档案链表基础操作
teacher *create_tch(char id[][11],                                      //  创建一个教师结点
                    char department[][50],
                    char name[][30],
                    char mailbox[][50],
                    char password[][50]);
void print_tch(teacher *np);                                            //  打印某个教师结点
void traversal_tch(teacher *fnode);                                     //  遍历并打印所有教师结点
teacher *insertBeginning_tch(teacher *fnode, teacher *newnode);         //  插入教师结点头部



//  教师开设课程链表基础操作
course *create_cos(char id[][7],                                        // 从原始数据导入一个课程结点
                    char name[][50],
                    int credit[],
                    int period[],
                    char characteritics[][20],
                    char teacher[][50],
                    char department[][50],
                    int year1[],
                    int year2[],
                    int semester1[],
                    int semester2[],
                    int week1[],
                    int week2[],
                    int time[],
                    int building[],
                    int room[],
                    int limitation[],
                    int selected[],
                    char ioc[][200],
                    char iom[][200]);
course *tch_create_cos(course *t_fcourse);                              //  手动创建教师开设课程结点
void print_cos(course *np);                                             //  打印某个课程结点
void traversal_cos(course *fnode);                                      //  遍历并打印所有课程
course *insertBeginning_cos(course *fnode, course *newnode);            //  插入课程链表头部
int tch_newcourse_check(course *fnode, course *new_node);                  //  检查教师开设新课程是否符合规则
course *search_cos(course *np, char key[20]);                           //  根据ID搜索课程


//  学生选修课程链表基础操作
int std_check_cos(course *fnode, course *new_node);                     //  检查学生选修新课程是否符合规则
course *std_create_cos(course *np);                                     //  复制学生选修课程结点

//  学生档案链表基础操作
student *create_std(char id[][11],                                      //  创建一个学生结点
                    char department[][50],
                    char major[][50],
                    char name[][30],
                    int gender[],
                    char phone_number[][12],
                    char password[][50],
                    char mailbox[][50]);
void print_std(student *np);                                            //  打印某个学生结点
void traversal_std(student *fnode);                                     //  遍历并打印所有学生结点
student *insertBeginning_std(student *fnode, student *newnode);         //  插入学生链表头部
//  学生功能：
//      1.登陆
void menu1(student *fstudent,teacher *fteacher, course *t_fcourse);
void studentmenu1(course *t_fcourse,student *fstudent,teacher *fteacher,student *np);                                   //  学生功能菜单        
student *std_checkAccountandPassword(student *np);                      //    学生账号密码检验
//      2.学生选课
void std_select_cos(course *s_fcourse, course *t_fcourse);     
//      3.查询课程
course *studentmenu2(student *fstudent, course *t_course);        //  学生查询课程二级菜单
void search_cos_name(course *t_fcourse);                        //  根据课程名搜索课程
void search_cos_department(course *t_fcourse);                  //  根据开课学院搜索课程
course *order_margin(course *t_fcourse);                           //  根据课余量排序 
course *order_selected(course *t_fcourse);                         //  根据选课人数排序 
//      4.查询选课结果
void search_s_courser_result(course *np);                       //  查询选课结果 
//      5.删除选课结果
void delete_s_courser_result(course *np);                       //  查询选课结果 
//      6.个人信息管理
void change_std_i(student *np);                                 //  个人信息管理

//  教师功能：
//      1.登陆
void teachermenu1(teacher *fteacher,student *fstudent, course *t_fcourse, teacher *np);                           //  教师账号菜单
teacher *tch_checkAccountandPassword(teacher *np);              //  教师账号密码检验
//      2.选课管理
void tch_manage_course(teacher *account, course *t_fcourse, student *fstudent);
        //  a.查看选课情况：
void tch_checkcourse(course *t_fcourse);                        //  查询教师自己开设过短的课程的选课情况（选课人数和课程详细信息）
void tch_checkstudent(course *t_fcourse);                       //  查询某门课程的学生信息
        //  b.删除选课    
  
//      3.统计选课信息
void teachermenu2(course *t_fcourse, teacher *np);               
void tch_cos_count(course *t_fcourse, teacher *np);             //  统计教师自己开设过的课程数目
void selected_order(course *t_fcourse, teacher *np);              //  按选课人数排序所有开设过的课程
//      4.课程管理
void tch_manage_cos(course *t_fcourse, teacher *np);            //  查询所有开设的课程、根据课程名查询
//      5.添加课程
course *tch_add_cos(course *t_course);                            //  添加一门新的课程
//      6.修改课程
void change_tch_course(teacher *fteacher,student *fstudent,course *t_fcourse,teacher *np);                      //  教师修改课程 
//      7.删除课程
course *delete_tch_course(course *t_fcourse);                      //  教师删除课程 
//      8.个人信息管理
void change_tch_i(teacher *np);                                 //  个人信息管理

int main()
{
    int i;
    int key;

    // 学生测试数据
    char s_id[N][11]={"2019213444","2019211456","2018125486","2017213489","2019215671"};
    char s_department[N][50]={"计算机学院","人工智能学院","人文学院","国际学院","经济与管理学院"};
    char s_major[N][50]={"计算机科学与技术","人工智能","英语","物联网工程","市场营销"};
    char s_name[N][30]={"陈恺","周森宇","唐三","魏子翔","宋明月"};
    int s_gender[N]={1,1,1,1,2};    
    char s_phone_number[N][12]={"18145678912","17312345678","13898745612","13714785296","13707145689"};
    char s_password[N][50]={"104785","193569","865239","108569","418569"};
    char s_mailbox[N][50]={"123456789@qq.com","987654321@qq.com","535478690@qq.com","535078459@qq.com","2199785687@qq.com"};
    //  教师测试数据
    char t_id[N][11]={"2018154965","2012589142","2014875912","2010458961","2016784956"};
    char t_department[N][50]={"电子工程学院","计算机学院","国际学院","理学院","人文学院"};
    char t_name[N][30]={"张锦北","徐六通","王慧玲","张勇敢","杨鼓"};
    char t_mailbox[N][50]={"613425790@qq.com","132467980@qq.com","845213423@qq.com","986723556@qq.com","211447889@qq.com"};
    char t_password[N][50]={"510263","814590","859740","746980","411213"};
    //  课程测试数据
    char c_id[N][7]={"985641","654321","456789","654789","321987"};
    char c_name[N][50]={"程序设计及c语言基础","电子系统基础","大学综合英语","高等数学","电影艺术及其欣赏"};  
    int c_credit[N]={2,3,5,4,1};
    int c_period[N]={12,48,48,36,12}; 
    char c_characteristics[N][20]={"必修","必修","必修","必修","选修"};  
    char c_teacher[N][50]={"徐六通","张锦北","杨鼓","张勇敢","王慧玲"};  
    char c_department[N][50]={"计算机学院","电子工程学院","任务学院","理学院","国际学院"};
    int c_year1[N]={1,1,1,1,1}; 
    int c_year2[N]={1,1,1,1,51}; 
    int c_semester1[N]={1,1,1,1,1};
    int c_semester2[N]={2,2,2,2,2};
    int c_week1[N]={3,3,3,7,8};
    int c_week2[N]={18,18,20,18,20};
    int c_time[N]={1,1,5,7,5};
    int c_building[N]={1,2,1,2,2};
    int c_room[N]={401,201,211,307,512};
    int c_limitation[N]={1,2,1,2,1};
    int c_selected[N]={42,58,32,0,24};
    char c_ioc[N][200]={"《C语言程序设计》是电子信息技术相关专业的专业能力模块课程。"," 以电路设计为主导，深化电子电路理论知识，培养实验能力","大学英语课程是大学生的一门必修的基础课程。","高等数学是由微积分学、代数学、几何学以及它们之间的交叉内容所形成的一门基础学科","加强学生对于电影艺术的理解及鉴赏能力"}; 
    char c_iom[N][200]={"《C语言程序设计基础》童建中、童华、罗在文。","《电子系统设计教程》从电子系统的基本概念开始，由浅入深，介绍了 模拟电路子系统、 数字电路子系统和 单片机子系统的设计方法","《大学英语（A）综合教程》是根据国家教育部全国高校网络教育考试委员会制定的“大学英语（A）”课程考试大纲","《高等数学教程》是?浙江大学出版社在2000年08月出版的图书，作者是吴迪光?张彬?陈仲慈 李永琪。","本书除引论外有六章。引论介绍电影艺术的基本特征。"};  

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
        t_new_course = create_cos(c_id,c_name,c_credit,c_period,c_characteristics,c_teacher,c_department,c_year1,c_year2,c_semester1,c_semester2,c_week1,c_week2,c_time,c_building,c_room,c_limitation,c_selected,c_ioc,c_iom);
        t_fcourse = insertBeginning_cos(t_fcourse, t_new_course);
    }
    traversal_cos(t_fcourse);
    
    menu1(fstudent,fteacher,t_fcourse);

	return 0; 

}
teacher *create_tch(char id[][11],                      //  创建一个教师结点
                    char department[][50],
                    char name[][30],
                    char mailbox[][50],
                    char password[][50])
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
                    char name[][50],
                    int credit[],
                    int period[],
                    char characteristics[][20],
                    char teacher[][50],
                    char department[N][50],
                    int year1[],
                    int year2[],
                    int semester1[],
                    int semester2[],
                    int week1[],
                    int week2[],
                    int time[],
                    int building[],
                    int room[],
                    int limitation[],
                    int selected[],
                    char ioc[][200],
                    char iom[][200])
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
    np->semester1 = semester1[i];
    np->semester2 = semester2[i];
    np->week1 = week1[i];
    np->week2 = week2[i];
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
    int i=0;
    printf("请输入课程编号（6位数字）：\n");
    scanf("%s", np->id);
    if (strlen(np->id) != 6)
    {
        printf("课程编号长度不符要求\n");
        printf("请输入课程编号（6位数字）：\n");
        scanf("%s", np->id);
    }
    printf("请输入课程名称：\n");
    scanf("%s", np->name);
    printf("请输入课程学分：\n");  
    printf("1.1分\n");
    printf("2.2分\n");
    printf("3.3分\n");
    printf("4.4分\n");
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
    scanf("%d", &np->semester1);
    printf("第*周？\n");
    scanf("%d", &np->week1);
    printf("课程结束于\n");
    printf("202*学年？\n");
    scanf("%d", &np->year2);
    printf("第*学期？\n");
    printf("1.第一学期\n");
    printf("2.第二学期\n");
    scanf("%d", &np->semester2);
    printf("第*周？\n");
    scanf("%d", &np->week2);
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
    a = tch_newcourse_check(t_fcourse,np);
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
    printf("课程起始于：202%d-202%d学年第%d学期第%d周 / ", np->year1, np->year2, np->semester1, np->week1);
    printf("课程结束于：202%d-202%d学年第%d学期第%d周 / ", np->year1, np->year2, np->semester2, np->week2);
    if (np->time == 1)
    {
        printf("上课时段为8:00-8:50 / ");
    }
    else if (np->time == 2)
    {
        printf("上课时段为9:00-9:50 / ");
    }
    else if (np->time == 3)
    {
        printf("上课时段为10:00-10:50 / ");
    }
    else if (np->time == 4)
    {
        printf("上课时段为11:00-11:50 / ");
    }
    else if (np->time == 5)
    {
        printf("上课时段为1:30-2:20 / ");
    }
    else if (np->time == 6)
    {
        printf("上课时段为2:30-3:20 / ");
    }
    else if (np->time == 7)
    {
        printf("上课时段为3:30-4:20 / ");
    }
    else if (np->time == 8)
    {
        printf("上课时段为4:30-5:20 / ");
    }

    printf("上课地点: 教%d楼-%d / ", np->building, np->room);
    if (np->limitation == 1)
    {
        printf("限制人数: 80 / ");
    }
    else if(np->limitation == 2)
    {
        printf("限制人数：100 / ");
    }
    
    printf("选课人数: %d / ", np->selected);
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
int tch_newcourse_check(course *t_fcourse, course *new_node)
{
    course *np;
    np = t_fcourse;
    int i=0;
    while(np != NULL)
    {
        if(strcmp(new_node->teacher,np->teacher)==0)
        {
            if (new_node->year1 == np->year1 
                && new_node->year2 == np->year2
                && new_node->semester1 == np->semester1
                && new_node->semester2 == np->semester2
                && new_node->week1 == np->week1
                && new_node->week2 == np->week2
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
                    && new_node->semester1 == np->semester1
                    && new_node->semester2 == np->semester2)
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
            && new_node->semester1 == np->semester1
            && new_node->semester2 == np->semester2
            && new_node->week1 == np->week1
            && new_node->week2 == np->week2
            && new_node->time == np->time)
        {
            return 1;
        }    
        else if (new_node->year1 == np->year1
                && new_node->year2 == np->year2
                && new_node->semester1 == np->semester1
                && new_node->semester2 == np->semester2)
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
    new_course->semester1 = np->semester1;
    new_course->semester2 = np->semester2;
    new_course->week1 = np->week1;
    new_course->week2 = np->week2;
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

student *create_std(char id[][11],
                    char department[][50],
                    char major[][50],
                    char name[][30],
                    int gender[],
                    char phone_number[][12],
                    char password[][50],
                    char mailbox[][50])  
{
    static int i = 0;
    student *np;
    np = (student *) malloc(sizeof(student));   // 动态分配内存，存放学生数据
    strcpy(np->id, id[i]);
    strcpy(np->department, department[i]);
    strcpy(np->major, major[i]);
    strcpy(np->name, name[i]);
    np->gender = gender[i];
    strcpy(np->phone_number, phone_number[i]);
    strcpy(np->password, password[i]);
    strcpy(np->mailbox, mailbox[i]);
    np->s_fcourse = (course *) malloc(sizeof(course));  //  创建学生选课链表头结点
    np->s_fcourse= NULL;
    np->next = NULL;
    i++;
    return np;
}

void print_std(student *np) //  打印某个学生结点
{
    printf("学号: %s / 院系: %s / 专业: %s / 姓名: %s / ", np->id, np->department, np->major, np->name);
    if (np->gender == 1)
    {
        printf("性别：男 / ");
    }
    else
    {
        printf("性别：女 / ");
    }
    printf("电话: %s / 密码: %s / 邮箱: %s\n", np->phone_number, np->password, np->mailbox);
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
void menu1(student *fstudent,teacher *fteacher, course *t_fcourse)
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
        student *np; 
        np = NULL;
		printf("--------[学生登录]------\n");
		np = std_checkAccountandPassword(fstudent);
        if (np != NULL)
        {
            studentmenu1(t_fcourse,fstudent,fteacher,np);
        }
	}
    else if (choice == 2)
	{
        teacher *np;
        np = NULL;
		printf("--------[教师登录]------\n");
        np = tch_checkAccountandPassword(fteacher);
        if (np != NULL)
        {
            teachermenu1(fteacher,fstudent,t_fcourse,np);
        }
    }
    else
    {
        menu1(fstudent,fteacher,t_fcourse);
    }
}
void studentmenu1(course *t_fcourse,student *fstudent,teacher *fteacher,student *np)
{
	printf("--------[学生功能]--------\n");
	printf("\t1.学生选课\n");  
	printf("\t2.查询课程\n");
	printf("\t3.查询选课结果\n");
	printf("\t4.删除选课结果\n");
	printf("\t5.个人信息管理\n");
	printf("\t6.返回上级菜单\n");
	printf("--------------------------\n");
    int choice=0;
    scanf("%d", &choice);
    if (choice == 1)
    {
        //  学生选课
        std_select_cos(np->s_fcourse, t_fcourse);
        studentmenu1(t_fcourse,fstudent,fteacher,np);
    }
    else if (choice == 2)
    {
        //  查询课程
        t_fcourse = studentmenu2(fstudent, t_fcourse);
        studentmenu1(t_fcourse,fstudent,fteacher,np);
    }
    else if (choice == 3)
    {
        //  查询选课结果
        search_s_courser_result(np->s_fcourse); 
        studentmenu1(t_fcourse,fstudent,fteacher,np);
    }
    else if (choice == 4)
    {
        //  删除选课结果
        delete_s_courser_result(np->s_fcourse);
        studentmenu1(t_fcourse,fstudent,fteacher,np);
    }
    else if (choice == 5)
    {
        //  个人信息管理
        change_std_i(np);
        studentmenu1(t_fcourse,fstudent,fteacher,np);
    }
    else
    {
        menu1(fstudent,fteacher,t_fcourse);
    }

}
student *std_checkAccountandPassword(student *np)
{
	char id[11],password[50];
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
                return np;
		    }
        }
	}
    printf("用户名或密码错误\n");
    return NULL;
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
course *studentmenu2(student *fstudent, course *t_fcourse)         //  学生查询课程耳机菜单
{
    printf("--------[查询课程]--------\n");
	printf("\t1.根据课程名查询\n");  
	printf("\t2.根据开课学院查询\n");
	printf("\t3.根据课余量排序所有课程\n");
	printf("\t4.根据选课人数排序所有课程\n");
	printf("\t5.返回上级菜单\n");
	printf("--------------------------\n");
    int i=0;
    scanf("%d", &i);
    if (i == 1)
    {
        //  根据课程名搜索课程
        search_cos_name(t_fcourse);   
    }  
    else if (i == 2)
    {
        //  根据开课学院搜索课程
        search_cos_department(t_fcourse); 
    }
    else if (i == 3)
    {
        //  根据课余量排序 
        t_fcourse = order_margin(t_fcourse);  
    }
    else if (i == 4)
    {
        //  根据选课人数排序 
        t_fcourse = order_selected(t_fcourse); 
    }
    else
    {
        studentmenu2(fstudent,t_fcourse);
    }
    return t_fcourse;
}
void search_cos_name(course *t_fcourse)             //根据课程名搜索课程
{
    course *np;
    np = t_fcourse;
    char CourseName[50];
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
    char department[50]; 
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
course *order_margin(course *t_fcourse)                  //  根据课余量排序
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
    t_fcourse = first;
    return t_fcourse;
}

course *order_selected(course *t_fcourse)                //  根据选课人数排序
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
	temp = first;
    traversal_cos(first);
    t_fcourse = first;
    return t_fcourse;
}

void search_s_courser_result(course *np)  //查询选课结果 
{ 
    if (np != NULL)
    {
        while(np!=NULL)
	    {
	 	    print_cos(np);
	 	    np=np->next;
	    }
    }
    else
    {
        printf("未有选课。\n");
    }
}

void delete_s_courser_result(course *np)   //   删除选课结果
{ 
    char searchname[20];
    course *temp=NULL, *p=NULL;
    p = np;
	printf("请输入你要删除的课程名称:\n");
	scanf("%s",searchname); 
	while(p!=NULL)
 	{
		temp = p;  
 		p = p->next;
    	if(p->name == searchname)
    	{
		    temp->next = p->next;
		    printf("删除成功。");
	    }
		if(p == NULL)
		{
		 	printf("课程未被选。"); 
		}
	}
}


void change_std_i(student *np)                //  个人信息管理
{
    int choice=0;
    printf("--------[个人信息管理]--------\n");
	printf("\t1.对个人信息中电话进行修改\n");
	printf("\t2.对个人信息中密码进行修改\n");
	printf("\t3.对个人信息中邮箱进行修改\n");
    printf("\t4.返回上级菜单\n");
    printf("-----------------------------\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("请输入您的新电话号码.\n");
	    scanf("%s", np->phone_number);
        if (strlen(np->phone_number) != 11)
        {
            printf("电话号码位数不符合要求\n");
            printf("请输入您的新电话号码.\n");
	        scanf("%s", np->phone_number);
        }
    }
    else if (choice == 2)
    {
        printf("请输入您的新邮箱.\n");
	    scanf("%s", np->mailbox);
        int i=0;
        int flag1=0,flag2=0;
        while(np->mailbox[i] != '\0')
        {
            if (np->mailbox[i] == '@' && flag2 == 0)
            {
                flag1++;
            }
            else if (np->mailbox[i] == '.' && flag1 == 1)
            {
                flag2++;
            }
            i++;
        }
        if (flag1 != 1 || flag2 != 1)
        {
            printf("邮箱格式错误\n");
            printf("请输入您的新邮箱.\n");
	        scanf("%s", np->mailbox);
        }
    }
    else if (choice == 3)
    {
        printf("请输入您的新密码.\n");
	    scanf("%s", np->password);  
    }

}


void teachermenu1(teacher *fteacher,student *fstudent, course *t_fcourse, teacher *np)
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
    int choice=0;
    scanf("%d", &choice);
    if (choice == 1)
    {
        //  选课管理
        tch_manage_course(np,t_fcourse,fstudent);
        teachermenu1(fteacher,fstudent,t_fcourse,np);
    }
    else if (choice == 2)
    {
        //  统计选课信息
        teachermenu2(t_fcourse,np);
        teachermenu1(fteacher,fstudent,t_fcourse,np);
    }
    else if (choice == 3)
    {
        //  课程管理
        tch_manage_cos(t_fcourse,np);
        teachermenu1(fteacher,fstudent,t_fcourse,np);
    }
    else if (choice == 4)
    {
        //  添加课程
        t_fcourse = tch_add_cos(t_fcourse);   
        teachermenu1(fteacher,fstudent,t_fcourse,np);
    }
    else if (choice == 5)
    {
        //  修改课程
        change_tch_course(fteacher,fstudent,t_fcourse,np);         //  教师修改课程 
        teachermenu1(fteacher,fstudent,t_fcourse,np);
    }
    else if (choice == 6)
    {
        //  删除课程
        t_fcourse = delete_tch_course(t_fcourse);         //  教师删除课程 
        teachermenu1(fteacher,fstudent,t_fcourse,np);
    }
    else if (choice == 7)
    {
        //  个人信息管理
        change_tch_i(np);     //  个人信息管理     
        teachermenu1(fteacher,fstudent,t_fcourse,np);
    }
    else
    {
        menu1(fstudent,fteacher,t_fcourse);
    }
}
teacher *tch_checkAccountandPassword(teacher *np)                    //  教师账号密码检验
{
    char id[11],password[50];
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
                return np;
		    }
        }
	}
    printf("用户名或密码错误\n");
    return NULL;
}
void tch_manage_course(teacher *account, course *t_fcourse, student *fstudent)
{
    course *np;
    np = t_fcourse;
    student *temp;
    temp = fstudent;
    int choice=0;
    printf("--------[选课管理]--------\n");
	printf("\t1.查看选课情况\n");  
    printf("\t2.删除选课\n");
	printf("\t3.返回上级菜单\n");
	printf("-------------------------\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("--------[查看选课情况]--------\n");
	    printf("\t1.查询本人开设课程选课情况\n");  
        printf("\t2.查询某门课程的学生信息\n");
	    printf("\t3.返回上级菜单\n");
	    printf("-------------------------\n");
        int a=0;
        scanf("%d", &a);
        if (a == 1)
        {
            printf("您开设的课程相关信息：\n");
            while(np != NULL)
            {
                if (account->name == np->teacher)
                {
                    printf("课程编号：%s / 课程名称：%s / 选课人数：%s / ", &np->id, &np->name, &np->selected);
                    printf("课程简介：%s / 教材信息：%s\n", np->ioc, np->iom);
                }       
                np = np->next;
            }
        }
        else if (a == 2)
        {
            printf("请输入想要查询学生信息的课程名称\n");
            char cos_name[50];
            scanf("%s", &cos_name);
            while(temp != NULL)
            {
                course *p;
                p = temp->s_fcourse;
                while(p != NULL)
                {
                    if (p->name == cos_name)
                    {
                        print_std(temp);
                    }
                    p = p->next;
                }
                temp = temp->next;
            }
        }
    }
    else if (choice == 2)
    {
        while(np != NULL)
        {
            if (np->selected < 30)
            {
                course *ptr;
                while(temp != NULL)
                {
                    course *p;
                    p = temp->s_fcourse;
                    while(p != NULL)
                    {
                        if (p->name == np->name)
                        {
                            ptr = p;
                            p->next = p->next->next;
                        }
                        p = p->next;
                    }
                }
                ptr = np;
                np->next = np->next->next;
                free(ptr);  
            }
            np = np->next;
        }
    }
}

void teachermenu2(course *t_fcourse, teacher *np)
{
    printf("--------[统计选课信息]-----------\n");
	printf("\t1.统计教师自己开设过的课程数目\n");  
	printf("\t2.按选课人数排序所有开设过的课程\n");
	printf("\t3.返回上级菜单\n");
	printf("--------------------------------\n");
    int choice=0;
    scanf("%d", &choice);
    if (choice == 1)
    {
        tch_cos_count(t_fcourse,np);    
    }
    else if (choice == 2)
    {
        selected_order(t_fcourse,np);
    }
   
}

void tch_cos_count(course *t_fcourse, teacher *np)                          //  统计教师自己开设过的课程数目
{
    int i=0;
    course *p;
    p = t_fcourse;
    while(p != NULL)
    {
        if (strcmp(p->teacher, np->name) == 0)
        {
            i++;
        }
        p = p->next;
    }
    printf("共开设了%d门课程\n", i);
}

void selected_order(course *t_fcourse, teacher *np)                                      //  按选课人数排序所有开设过的课程
{

    course *first;                              //  排列后有序链的表头指针
	course *tail;                               //  排列后有序链的表尾指针
	course *p_min;                              //  保留键值更小的节点的前驱节点的指针
	course *min;                                //  存储最小节点
	course *p;                                  //  当前比较的节点
    course *temp1;
    course *temp2;
    course *ftemp;
    temp1 = t_fcourse;
    while(temp1 != NULL)
    {
        if (temp1->teacher == np->name)
        {
            course *temp;
            temp = (course *) malloc(sizeof(course));
            temp = temp1;
            temp->next = NULL;
            ftemp = insertBeginning_cos(ftemp,temp);
        }
        temp1 = temp1->next;
    }
    temp2 = ftemp;
	first = NULL;
	while(temp2!=NULL)
	{
		for(p=temp2,min=temp2;p->next!=NULL;p=p->next)//遍历所有节点 
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
		if(min==temp2)//使原链表中min脱离 
		{
			temp2 = temp2->next; 
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
	temp2 = first;
    traversal_cos(first);
}

void tch_manage_cos(course *t_fcourse, teacher *np)
{
    course *p;
    p = t_fcourse;
    while(p != NULL)
    {
        if (strcmp(p->teacher,np->name) == 0)
        {
            print_cos(p);
        }
        p = p->next;
    }
}

course *tch_add_cos(course *t_fcourse)        //  教师功能——添加课程
{
    course *t_new_course;
    traversal_cos(t_fcourse);
    t_new_course = tch_create_cos(t_fcourse);
    t_fcourse = insertBeginning_cos(t_fcourse, t_new_course); 
    traversal_cos(t_fcourse);
    return t_fcourse;
}

void change_tch_course(teacher *fteacher,student *fstudent,course *t_fcourse,teacher *np) //教师修改课程 
{
	int choice = 0;
    char CourseName[20];
	printf("请输入课程名称：\n");
	scanf("%s", &CourseName);
    course *p;
    p = t_fcourse;
	while(p != NULL && strcmp(np->name, CourseName) != 0)	// 不断搜索下一个节点，直到找到课程名为止，或者到链表末尾
	{
		p = p->next;
	}
    if (p != NULL)
    {
        if (p != NULL && p->selected ==0)
	    {
		    printf("--------[被修改课程尚未有学生选择]--------\n");
		    printf("\t1.修改教材请输入1\n");
		    printf("\t2.修改课程简介请输入2\n");
		    printf("\t3.修改限制人数请输入3\n");
		    printf("\t4.返回上级菜单请输入4\n");
		    scanf("%d",&choice);
		    if(choice == 1)
		    {
			    printf("请输入修改后的内容:\n");
			    scanf("%s", p->iom);
		    }
		    else if(choice == 2)
		    {
			    printf("请输入修改后的内容：\n");
			    scanf("%s",p->ioc);
		    }
		    else if(choice == 3)
		    {
			    printf("请输入修改后的内容:\n");
			    scanf("%s",p->limitation);
		    }
		    else
		    {
			    teachermenu1(fteacher,fstudent,t_fcourse,np);
		    }
        }
        else
        {
    	    printf("该课程已经有学生选择\n");
            printf("修改限制人数请输入：\n"); 
            printf("1.80人\n");
            printf("2.100人\n");
    	    scanf("%d",p->selected);
	    }
    }
    else
    {
        printf("该课程不存在\n");
    }
}

course *delete_tch_course(course *t_fcourse)   //   教师删除课程 
{ 	
    course *temp=NULL, *np=NULL,*idx=NULL;
    np = t_fcourse;
    char CourseName[50];
	printf("请输入想要删除的课程名称：\n");
	scanf("%s", &CourseName);
	while(np != NULL && strcmp(np->name, CourseName) != 0)	// 不断搜索下一个节点，直到找到课程名为止，或者到链表末尾
	{
		np = np->next;
	}
	if (np != NULL)					// 非末尾，即找到
	{
        if(np->selected == 0)
        {
    		temp = np;
            np = np->next;
    		printf("删除课程成功！");
	    }   
	    else
	    {
		    printf("改课程已开始选课，无法删除"); 
	    }
	}
	else
    {
        printf("不存在该课程名的课程!\n");
    }   
    return t_fcourse;
}
void change_tch_i(teacher *np)                                  //  个人信息管理
{
    int choice=0;
    printf("--------[个人信息管理]--------\n");
	printf("\t1.对个人信息中密码进行修改\n");
	printf("\t2.对个人信息中邮箱进行修改\n");
    printf("\t3.返回上级菜单\n");
    printf("-----------------------------\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("请输入您的新邮箱.\n");
	    scanf("%s", np->mailbox);
    }
    else if (choice == 2)
    {
        printf("请输入您的新密码.\n");
	    scanf("%s", np->password);  
    }
}