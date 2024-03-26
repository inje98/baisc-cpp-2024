#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}node;

typedef struct HeadNode
{
	node* head;
	int iCount;
}Head;


void InitList(Head* pnode)
{
	pnode->head = nullptr;
	pnode->iCount = 0;
}

void pushData(Head* pnode, int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
}
int main(void)
{
	Head list = {};
	// 1. InitList �ʱ�ȭ �Լ�
	InitList(&list);

	// 2. pushData �Լ�

	// 3. ShowData �Լ�

	// 4. free �Լ�



	return 0;
}