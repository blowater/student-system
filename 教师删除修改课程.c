void delete_t_course(course *np)   //   教师删除课程 

{ 	
    course *temp=NULL, *p=NULL,*idx=NULL;
    search_cos_name(t_fcourse);
    idx = search_cos_name(t_fcourse);
    p = np;
    if(idx->selected == 0)
    {
    	while(p!=NULL)
    	{
    		temp = p;
    		p = p->next;
    		if(p->name == CourseName)
    		{
    			temp->next = p->next;
    			free(p);
    			printf("删除课程成功！");
				}
		}
	}
	else
	{
		printf("改课程已开始选课，无法删除"); 
	}
}
void change_t_course(course *np) //教师修改课程 
{
	int choice = 0;
	search_cos_name(t_fcourse); 
	if(np->selected==0)
	{
		printf("--------[改课程尚未有学生选择]--------\n");
		printf("\t1.修改教材请输入1\n");
		printf("\t2.修改课程简介请输入2\n");
		printf("\t3.修改限制人数请输入3\n");
		printf("\t4.返回上级菜单请输入4\n");
		scanf("%d",&choice);
		if(choice == 1)
		{
			printf("请输入修改后的内容:\n");
			scanf("%s", np->iom);
		}
		else if(choice == 2)
		{
			print("请输入修改后的内容：\n");
			scanf("%s",np->ioc);
		}
		else if(choice == 3)
		{
			printf("请输入修改后的内容:\n");
			scanf("%s",np->limitation);
		}
		else
		{
			//上级菜单函数 
		}
    }
    else
    {
    	printf("该课程已经有学生选择\n");
    	printf("修改限制人数请输入：\n"); 
    	scanf("%d",np->selected);
	}
			
}

