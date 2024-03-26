#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE* link;
}node;

typedef struct
{
	node* rear;
	node* front;
}linkQ;

linkQ* create();
void enqueue(linkQ*, int);
void dequeue(linkQ*);
void printQ(linkQ*);
void allFree(linkQ*);

int main()
{
	linkQ* lq = create();
	/*lq->front->data = 100;
	lq->front = newNode;*/

	


	enqueue(lq, 10);
	enqueue(lq, 20);
	enqueue(lq, 30);
	enqueue(lq, 50);
	enqueue(lq, 60);
	enqueue(lq, 70);
	enqueue(lq, 80);
	enqueue(lq, 90);

	dequeue(lq);
	dequeue(lq);
	dequeue(lq);
	//dequeue(lq);
	//dequeue(lq);

	printQ(lq);

	dequeue(lq);
	dequeue(lq);

	printQ(lq);

	/*allFree(lq);
	free(lq);*/

	return 0;
}



linkQ* create()
{
	linkQ* lq = (linkQ*)malloc(sizeof(linkQ));
	lq->rear = NULL;
	lq->front = NULL;
	return lq;
}

void enqueue(linkQ* lq, int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->link = NULL;

	if (lq->rear == NULL)
	{
		lq->rear = newNode;
		lq->front = newNode;  // front�� ��� ù��� ����Ű�� �ϴ�
	}

	else
	{
		lq->rear->link = newNode;
		lq->rear = lq->rear->link;
	}
}

void dequeue(linkQ* lq)
{
	if (lq->front == NULL)
	{
		printf("stack underflow!\n");
		return;
	}
	node* next = lq->front->link;
	printf("������ ������: %d\n", lq->front->data);
	free(lq->front);
	lq->front = next;
}

void printQ(linkQ* lq)
{
	node* curr = lq->front;
	printf("\nť ����Ʈ\n");
	while (curr != NULL)
	{
		
		printf("%d\n", curr->data);
		curr = curr->link;
	}
}

void allFree(linkQ* lq)
{
	node* next = lq->front->link;
	printf("���� ��� ����\n");
	while (lq->front != NULL)
	{
		printf("����");
		free(lq->front);
		lq->front = next;
	}
}