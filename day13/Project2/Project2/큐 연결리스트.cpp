#include<stdio.h>
#include<stdlib.h>
#define QSIZE 3

typedef struct
{
	int front;
	int rear;
	char queue[QSIZE];
}queue;

queue* create();
void enqueue(queue*, char);
int isFull(queue*);

void dequeue(queue*);
int isEmpty(queue*);

void printQueue(queue*);

int main()
{
	queue* pqueue = create();
	enqueue(pqueue, 'A');
	enqueue(pqueue, 'B');
	enqueue(pqueue, 'C');
	enqueue(pqueue, 'D');

	dequeue(pqueue);
	dequeue(pqueue);

	printQueue(pqueue);

	return 0;
}

queue* create()
{
	queue* pqueue = (queue*)malloc(sizeof(queue));
	pqueue->front = -1;
	pqueue->rear = -1;
	

	return pqueue;
}

int isFull(queue* q)
{
	if (q->rear >= QSIZE - 1)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void enqueue(queue* q, char data)
{
	if (isFull(q))
	{
		printf("stack overflow!\n");
	}
	q->queue[++q->rear] = data;
}

int isEmpty(queue* q)
{
	if (q->rear <= -1)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void dequeue(queue* q)
{
	if (isEmpty(q))
	{
		printf("stack underflow!\n");
	}
	printf("%c\n", q->queue[++q->front]);
}

void printQueue(queue* q)
{
	for (int i = q->front + 1; i <= q->rear; i++)
	{
		printf("%c\n", q->queue[i]);
	}
}