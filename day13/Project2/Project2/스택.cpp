#include<stdio.h>

#define STACK_SZ 10

typedef struct STACK
{
	int buf[STACK_SZ];
	int top;
}stack;

void push(stack*, int);

void InitStack(stack*);

int main()
{
	stack s;
	InitStack(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	return 0;
}

void InitStack(stack* pstk)
{
	pstk->top = -1;
}
void push(stack* pstk, int value)
{
	pstk->buf[++pstk->top] = value;
}