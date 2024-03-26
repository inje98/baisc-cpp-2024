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
	// 1. InitList 초기화 함수
	InitList(&list);

	// 2. pushData 함수

	// 3. ShowData 함수

	// 4. free 함수



	return 0;
}