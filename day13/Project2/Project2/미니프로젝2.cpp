#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE
{
	char BookTitle[40];
	struct NODE* next;
}node;

typedef struct HEAD
{
	node* headNode;
}head;

head* createHead()
{
	head* headNode = (head*)malloc(sizeof(head));
	headNode->headNode = NULL;

	return headNode;
}

void addBook(head* headNode, const char* BookTitle)
{
	node* newBook = (node*)malloc(sizeof(node));
	strcpy(newBook->BookTitle, BookTitle);
	newBook->next = NULL;

	if (headNode->headNode == NULL)
	{
		headNode->headNode = newBook;
		//printf("%s", newBook->BookTitle);
		return;
	}

	node* curr = headNode->headNode;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = newBook;
}

void SearchBook(head* headNode, const char* searchBook)
{
	node* curr = headNode->headNode;
	while (curr != NULL)
	{
		if (strcmp(curr->BookTitle, searchBook) == 0)
		{
			printf("%s �ִ�!\n", curr->BookTitle);
			return;
		}
		curr = curr->next;
	}
	printf("\n%s ���µ�?\n\n", searchBook);
}

void deleteBook(head* headNode, const char* deleteB)
{
	node* curr = headNode->headNode;
	node* prev = NULL;  // �� ���� ���� ���� �����ؾ� �ϱ⶧���� ������

	if (curr == NULL)
	{
		printf("å�� �ϳ��� ���µ���??\n");
		return;
	}

	// ������ å�� ù ��° å�� ���
	if (strcmp(headNode->headNode->BookTitle, deleteB) == 0)
	{
		headNode->headNode = headNode->headNode->next; // ��带 ���� ���� �Űܳ���
		free(curr); // ù ��� ����
		return;
	}

	// ������ ���� ù��°�� �ƴϸ� ����
	while (curr != NULL)
	{
		if (strcmp(curr->BookTitle, deleteB) == 0)
		{
			prev->next = curr->next;
			free(curr); // ���� ��� ����
			return;
		}
		prev = curr;       // ���� ���縦 prev�� �ٰ�
		curr = curr->next; // �׷��� �� next�� �ɰ�
	}
	printf("%s ���µ�?\n", deleteB);
}


//void deleteBook(head* headNode, const char* deleteB)
//{
//	node* curr = headNode->headNode;
//
//	if (curr == NULL)
//	{
//		printf("å�� �ϳ��� ���µ���?\n");
//		return;
//	}
//
//	else if (strcmp(headNode->headNode->BookTitle, deleteB) == 0) // ù��° å�� ����ٸ� ����
//	{
//		headNode->headNode = headNode->headNode->next; // ù��° ���� ����ϱ� ��带 �������� �Ű� ����
//		free(curr);  // ù��° ��� ����
//		return;
//	}
//
//
//
//	while (curr->next != NULL)
//	{
//		if (strcmp(curr->next->BookTitle, deleteB) == 0) // �� ��ȸ�ϸ鼭 �̸� ���� ���� ���´ٸ�
//		{
//
//			curr->next = curr->next->next;
//			free(curr->next);
//			return;
//		}
//		curr = curr->next;
//	}
//	printf("%s ���µ�?", deleteB);
//}

int main()
{
	head* headNode = createHead();
	while (1)
	{
		int menuNum;

		printf("1. �������\n2. �����˻�\n3. ��������\n4. �������\n0. ����\n>>  ");
		scanf("%d", &menuNum);

		// 1. �������ϸ鼭 next�� ������� ����
		if (menuNum == 1)
		{
			char title[40];
			printf("����� å �̸� >> ");
			scanf("%s", title);

			addBook(headNode, title);

		}
		// 2. while ���鼭 if���� strcmp == 0�� �ɸ��� ����ϰ� �ϸ� �ɵ�?
		if (menuNum == 2)
		{
			char search[40];
			printf("�˻��� å �̸� >> ");
			scanf("%s", search);

			SearchBook(headNode, search);

		}
		// 3. while ���鼭 if���� strcmp == 0�� �ɸ��� free�ϴµ�, �̷��� �ȵ��� �ʳ�?
		// �ȴ�. ���� ���� ���� ��Ų ���� ���� �����ϰ� �����Ѱ� free
		if (menuNum == 3)
		{
			char deleteB[40];
			printf("������ å �̸� >> ");
			scanf("%s", deleteB);

			deleteBook(headNode, deleteB);
		}


		// 4. while ���鼭 �� next next �� ���
		if (menuNum == 4)
		{
			node* curr = headNode->headNode;

			printf("\n========== ��ü å ==========\n");
			while (curr != NULL)
			{
				printf("%s\n", curr->BookTitle);
				curr = curr->next;
			}
			printf("=============================\n");
		}


		// 0. ������ ���δ� free �ϰ� exit(1)
		if (menuNum == 0)
		{
			exit(1);
		}
	}
	return 0;
}