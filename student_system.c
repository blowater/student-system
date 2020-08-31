#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct student{
	char id[10];
	char department[10];
	char major[10];
	char name[10];
	char gender[10];
	char phone_number[11];
	char password[20];
	char mailbox[10];
	struct student *next;
} student;

typedef struct teacher{
	char id[10];
	char department[10];
	char name[10];
	char mailbox[10];
	char password[20];
	struct teacher *next;
} teacher;

typedef struct course{
	char id[6];
	int credit;
	char time[20];
	char place[20];
	struct course *next;
} course;

student *create_student(char id[10], )

int main()
{
    student *fnode=NULL,*fonode=NULL,*newnode=NULL,*np=NULL;
    int i;
    int key;

    
}