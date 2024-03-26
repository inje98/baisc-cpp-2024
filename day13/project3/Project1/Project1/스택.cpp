#include<stdio.h>

#define STACK_SZ 10

typedef struct STACK
{
	int buf[STACK_SZ];
	int top;
}stack;

void push(stack*, int);

void InitStack(stack*);

int pop(stack*);

int main()
{
	stack s;
	InitStack(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;
}

void InitStack(stack* pstk)
{
	pstk->top = -1;
}
void push(stack* pstk, int value)
{
	if (pstk->top >= STACK_SZ - 1)
	{
		printf("stack overflow!\n");
		return;
	}

	pstk->buf[++pstk->top] = value;
}

int pop(stack* pstk)
{
	if (pstk->top <= -1)
	{
		printf("stack underflow!\n");
		return -1;
	}

	return pstk->buf[pstk->top--];
}