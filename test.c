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

NODE *createNode(int ids[], char names[][20], int scores[]);
void printNode(NODE *np);
void searchNode(NODE *np, int key);
void traversal(NODE *fNode);
void insertAfter(NODE *node, NODE *newNode);
NODE *insertBeginning(NODE *fNode, NODE *newNode);
void removeAfter(NODE *node);
NODE *removeBeginning(NODE *fNode);
NODE *insertOrder(NODE *fNode, NODE *np);
NODE *deleteOrder(NODE *foNode, int key);

int main()
{
        int ids[N]={1234,5678,3456,4567,2345}; 
        char names[N][20]={"aaa","bbb","ccc","ddd","eee"}; 
        int scores[N]={12,23,34,45,56};

	NODE *fNode=NULL,*foNode=NULL,*newNode=NULL,*np=NULL;
	int i;
	int key;                 


	for (i=0;i<4;i++)		//create 5 nodes and input data for the nodes
	{
		newNode = createNode(ids, names, scores);
		fNode = insertBeginning(fNode, newNode);
	}

	traversal(fNode);

	printf("Please input a key to search:\n");
	scanf("%d",&key);
	searchNode(fNode, key);

    
	while(fNode != NULL)
	{
		np = fNode;
		fNode = fNode->next;
		np->next = NULL;
		foNode = insertOrder(foNode, np);
	}
    

	printf("\nOrdered linked list:\n");
	traversal(foNode);

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