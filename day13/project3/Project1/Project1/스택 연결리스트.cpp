#include<stdio.h>
#include<stdlib.h>
#define STACK_SZ 10



typedef struct Node
{
	int data;
	struct Node* next;
}node;

typedef struct STACK
{
	node* top;
}stack;

void InitTop(stack* pstack)
{
	pstack->top = NULL;
}

void push(stack* pstack, int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = pstack->top;
	pstack->top = newNode;
}


int pop(stack* pstack)
{
	
	printf("%d", pstack->top->data);
	return pstack->top->data;
}

int main()
{
	stack s;
	InitTop(&s);

	push(&s, 100);
	push(&s, 200);
	push(&s, 300);

	pop(&s);

	return 0;
}