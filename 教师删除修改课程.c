void delete_t_course(course *np)   //   ��ʦɾ���γ� 

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
    			printf("ɾ���γ̳ɹ���");
				}
		}
	}
	else
	{
		printf("�Ŀγ��ѿ�ʼѡ�Σ��޷�ɾ��"); 
	}
}
void change_t_course(course *np) //��ʦ�޸Ŀγ� 
{
	int choice = 0;
	search_cos_name(t_fcourse); 
	if(np->selected==0)
	{
		printf("--------[�Ŀγ���δ��ѧ��ѡ��]--------\n");
		printf("\t1.�޸Ľ̲�������1\n");
		printf("\t2.�޸Ŀγ̼��������2\n");
		printf("\t3.�޸���������������3\n");
		printf("\t4.�����ϼ��˵�������4\n");
		scanf("%d",&choice);
		if(choice == 1)
		{
			printf("�������޸ĺ������:\n");
			scanf("%s", np->iom);
		}
		else if(choice == 2)
		{
			print("�������޸ĺ�����ݣ�\n");
			scanf("%s",np->ioc);
		}
		else if(choice == 3)
		{
			printf("�������޸ĺ������:\n");
			scanf("%s",np->limitation);
		}
		else
		{
			//�ϼ��˵����� 
		}
    }
    else
    {
    	printf("�ÿγ��Ѿ���ѧ��ѡ��\n");
    	printf("�޸��������������룺\n"); 
    	scanf("%d",np->selected);
	}
			
}

