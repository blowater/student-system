/*Desc: Linked List
	create a node by malloc;
	insert a node, delete a node, search a node

Author: Liutong XU
Date: 2018/12/27
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
typedef struct Node{
	int id;
	char name[10];
	int score;
	struct Node *next;
} NODE;

NODE *createNode(int ids[], char names[][20], int scores[]);	// �½���㣬��������ͷָ��
void printNode(NODE *np);										// ��ӡ���н��
void searchNode(NODE *np, int key);								// ��id�������
void traversal(NODE *fNode);									// ��������
void insertAfter(NODE *node, NODE *newNode);					// ���ض���ŵĽ������һ�����
NODE *insertBeginning(NODE *fNode, NODE *newNode);				// ������ı�ͷ�����㣬�����µ�����ͷָ��
void removeAfter(NODE *node);									// ���Ƴ��ض���Ž�����Ǹ����
NODE *removeBeginning(NODE *fNode);								// �Ƴ������ͷ�Ľ�㣬�����µ�����ͷָ��
NODE *insertOrder(NODE *fNode, NODE *np);						// ����������id��С˳�����һ���½�㣨�˺������ص�ָ��Ϊ�������㣩
NODE *deleteOrder(NODE *foNode, int key);						// ��idѰ����Ӧ��㲢ɾ�����˺������ص�ָ�벻������ͷָ����Ǳ�ɾ�����ĺ�һ����㣩

int main()
{
		// �������ݣ�����
        int ids[N]={1234,5678,3456,4567,2345}; 
        char names[N][20]={"aaa","bbb","ccc","ddd","eee"}; 
        int scores[N]={12,23,34,45,56};

	NODE *fNode=NULL,*foNode=NULL,*newNode=NULL,*np=NULL;	// ׼��main������Ҫ�õ���ָ��
	int i;
	int key;                 

	//create 5 nodes and input data for the nodes����������½�㲢�����ݴ�����������
	for (i=0;i<4;i++)		
	{
		newNode = createNode(ids, names, scores);	// �����½�㣬���ؽ��ָ��
		fNode = insertBeginning(fNode, newNode);	// ���½���������ͷ������������ͷָ��
	}

	// ����������ӡ��;�о�����ÿ�������Я������Ϣ
	traversal(fNode);		

	// ������Ҫ���ҵĽ��id
	printf("Please input a key to search:\n");	
	scanf("%d",&key);
	// �����id����������Ҫ���ҵĽ�㣬���ҵ����ӡ���ý��������Ϣ
	searchNode(fNode, key);				

    // �������������
	while(fNode != NULL)				
	{
		np = fNode;
		fNode = fNode->next;
		np->next = NULL;
		foNode = insertOrder(foNode, np);
	}
    
	// �ٴα���������ӡ��;�о�����ÿ�������Я����Ϣ����ʱ�����Ѱ�id��С��С��������
	printf("\nOrdered linked list:\n");	
	traversal(foNode);


	// ����һ��id��ɾ����id�Ľ�㣬���ٴδ�ӡ����������
	printf("Please input a key to delete:\n");
	scanf("%d",&key);
	foNode = deleteOrder(foNode, key);
	traversal(foNode);

	newNode = createNode(ids, names, scores);
	np = foNode->next;

	printf("\ninsert newnode\n");
	printNode(newNode);
	printf("\nafter npnode\n");
	printNode(np);
	printf("\ninsert newnode after npnode ...\n");
	insertAfter(np, newNode);
	traversal(foNode);

	return 0;
}
NODE *createNode(int ids[], char names[][20], int scores[])
{
	static int i = 0;				// Ϊ�˴������ȡ���ݣ�
	NODE *np;
	np = (NODE *) malloc(sizeof(NODE));			// ��̬�����ڴ棬��Žڵ�
	// printf("Please input id, name, score: \n");
	// scanf("%d%s%d", &np->id, &np->name, &np->score);

	np->id = ids[i];
	strcpy(np->name, names[i]);
	np->score = scores[i];
	np->next = NULL;				// ����Ҫ
	i++;
	return np;
}
void searchNode(NODE *np, int key)
{
	while(np != NULL && np->id !=key)	// ����������һ���ڵ㣬ֱ���ҵ�idΪֹ�����ߵ�����ĩβ
	{
		np = np->next;
	}
	if (np != NULL)					// ��ĩβ�����ҵ�
	{
		printf("Found a node with key = %d!", key);
		printNode(np);
	}
	else
		printf("Not Found!\n");
}

void traversal(NODE *fNode)
{
	NODE *np = fNode;
	while(np != NULL)	// �ӵ�һ����ʼ��ͨ��next������һ��������ӡÿ���ڵ����Ϣ
	{
		printNode(np);
		np = np->next;
	}
}

// insert newNode after node
void insertAfter(NODE *node, NODE *newNode)
{
	newNode->next = node->next;
	node->next = newNode;
}

// insert node before current first node
NODE *insertBeginning(NODE *fNode, NODE *newNode)
{
	newNode->next = fNode;
	fNode = newNode;
	return fNode;
}

// remove node past this one
void removeAfter(NODE *node)
{
	NODE *rp;
	rp = node->next;
	node->next = node->next->next;
	free(rp);
}

// remove first node
NODE *removeBeginning(NODE *fNode)
{
	NODE *rp;
	rp = fNode;
	fNode = fNode->next;
	free(rp);
	return fNode;
}

void printNode(NODE *np)
{
	printf("ID: %6d / Name: %-10s / Score: %3d\n", np->id, np->name, np->score);
}

NODE *insertOrder(NODE *foNode, NODE *np)
{
	if (foNode == NULL)		// �ձ�ʱ�������½ڵ��ָ��np����
		return np;
	if (np->id > foNode->id)	// �½ڵ��id���ڵ�һ���ڵ��id��
					// Ӧ�ò��뵽��2���ڵ㿪ʼ�������У������õݹ���ʵ�֡�
	{
		foNode->next = insertOrder(foNode->next, np);
		return foNode;
	}
	else				// �½ڵ��idС�ڵ�һ���ڵ��id���½ڵ���뵽����ͷ�ϡ�
	{
		np->next = foNode;
		return np;
	}
}

NODE *deleteOrder(NODE *foNode, int key)
{
	NODE *temp;
	if (foNode == NULL)		// �ձ�
						// ����ָ���Ƶ�ĩ�ڵ�Ҳû���ҵ�
	{
		printf("Not Found!\n");
		return foNode;
	}
	if (foNode->id == key)		// �ҵ���
	{
		temp = foNode;
		foNode = foNode->next;
		free(temp);
		return foNode;
	}
	else				// �ݹ����һ���ڵ���ɾ��
	{
		foNode->next = deleteOrder(foNode->next,key);
		return foNode;
	}
}