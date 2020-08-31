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

NODE *createNode(int ids[], char names[][20], int scores[]);			// 新建结点，返回链表头指针
void printNode(NODE *np);							// 打印所有结点
void searchNode(NODE *np, int key);						// 按id搜索结点
void traversal(NODE *fNode);							// 遍历链表
void insertAfter(NODE *node, NODE *newNode);					// 在特定序号的结点后插入一个结点
NODE *insertBeginning(NODE *fNode, NODE *newNode);				// 在链表的表头插入结点，返回新的链表头指针
void removeAfter(NODE *node);							// 在移除特定序号结点后的那个结点
NODE *removeBeginning(NODE *fNode);						// 移除链表表头的结点，返回新的链表头指针
NODE *insertOrder(NODE *fNode, NODE *np);					// 按各个结点的id大小顺序插入一个新结点（此函数返回的指针为被插入结点）
NODE *deleteOrder(NODE *foNode, int key);					// 按id寻找相应结点并删除（此函数返回的指针不是链表头指针而是被删除结点的后一个结点）

int main()
{
	// 测试数据，数组
        int ids[N]={1234,5678,3456,4567,2345}; 
        char names[N][20]={"aaa","bbb","ccc","ddd","eee"}; 
        int scores[N]={12,23,34,45,56};

	NODE *fNode=NULL,*foNode=NULL,*newNode=NULL,*np=NULL;	// 准备main函数需要用到的指针
	int i;
	int key;                 

	//create 5 nodes and input data for the nodes，创建五个新结点并将数据储存进各个结点
	for (i=0;i<4;i++)		
	{
		newNode = createNode(ids, names, scores);	// 创建新结点，返回结点指针
		fNode = insertBeginning(fNode, newNode);	// 将新结点插入链表头部，返回链表头指针
	}

	// 遍历链表并打印出途中经过的每个结点所携带的信息
	traversal(fNode);		

	// 输入需要查找的结点id
	printf("Please input a key to search:\n");	
	scanf("%d",&key);
	// 按结点id遍历搜索需要查找的结点，若找到则打印出该结点所含信息
	searchNode(fNode, key);				

    	// 对链表进行排序
	while(fNode != NULL)				
	{
		np = fNode;
		fNode = fNode->next;
		np->next = NULL;
		foNode = insertOrder(foNode, np);
	}
    
	// 再次遍历链表并打印出途中经过的每个结点所携带信息（此时链表已按id大小从小到大排序）
	printf("\nOrdered linked list:\n");	
	traversal(foNode);


	// 输入一个id，删除该id的结点，并再次打印出整个链表
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
	static int i = 0;				// 为了从数组读取数据，
	NODE *np;
	np = (NODE *) malloc(sizeof(NODE));			// 动态分配内存，存放节点
	// printf("Please input id, name, score: \n");
	// scanf("%d%s%d", &np->id, &np->name, &np->score);

	np->id = ids[i];
	strcpy(np->name, names[i]);
	np->score = scores[i];
	np->next = NULL;				// 很重要
	i++;
	return np;
}
void searchNode(NODE *np, int key)
{
	while(np != NULL && np->id !=key)	// 不断搜索下一个节点，直到找到id为止，或者到链表末尾
	{
		np = np->next;
	}
	if (np != NULL)					// 非末尾，即找到
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
	while(np != NULL)	// 从第一个开始，通过next搜索下一个，并打印每个节点的信息
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
	if (foNode == NULL)		// 空表时，返回新节点的指针np即可
		return np;
	if (np->id > foNode->id)	// 新节点的id大于第一个节点的id，
					// 应该插入到第2个节点开始的链表中，可以用递归来实现。
	{
		foNode->next = insertOrder(foNode->next, np);
		return foNode;
	}
	else				// 新节点的id小于第一个节点的id，新节点插入到链表头上。
	{
		np->next = foNode;
		return np;
	}
}

NODE *deleteOrder(NODE *foNode, int key)
{
	NODE *temp;
	if (foNode == NULL)		// 空表
						// 或是指针移到末节点也没有找到
	{
		printf("Not Found!\n");
		return foNode;
	}
	if (foNode->id == key)		// 找到了
	{
		temp = foNode;
		foNode = foNode->next;
		free(temp);
		return foNode;
	}
	else				// 递归从下一个节点中删除
	{
		foNode->next = deleteOrder(foNode->next,key);
		return foNode;
	}
}
