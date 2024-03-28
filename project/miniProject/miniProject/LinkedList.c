/*
	File: linkedList.c
	Created: 24-03-27
	Author: ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

head* createHead()
{
	head* headNode = (head*)malloc(sizeof(head));
	headNode->headNode = NULL;

	return headNode;
}

void addBook(head* headNode, const char* BookTitle, int price, const char* author, const char* company, const char* ID)
{
	node* newBook = (node*)malloc(sizeof(node));
	strcpy(newBook->BookTitle, BookTitle);
	newBook->price = price;
	strcpy(newBook->author, author);
	strcpy(newBook->company, company);
	strcpy(newBook->ID, ID);

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

void deleteBook(head* headNode, head* rentHeadNode, const char* deleteB)
{
	node* rentCurr = rentHeadNode->headNode;
	node* curr = headNode->headNode;
	node* prev = NULL;  // �� ���� ���� ���� �����ؾ� �ϱ⶧���� ������

	while (rentCurr != NULL)
	{
		if (strcmp(rentCurr->BookTitle, deleteB) == 0)
		{
			printf("�� å�� ���� �뿩 ���Դϴ�.\n\n");
			return;
		}
		rentCurr = rentCurr->next;
	}

	if (curr == NULL)
	{
		printf("������ �ϳ��� �����ϴ�.\n");
		return;
	}

	// ������ å�� ù ��° å�� ���
	if (strcmp(headNode->headNode->BookTitle, deleteB) == 0)
	{
		//printf("%s ����\n", headNode->headNode->BookTitle);
		headNode->headNode = headNode->headNode->next; // ��带 ���� ���� �Űܳ���
		free(curr); // ù ��� ����
		printf("�����߽��ϴ�.\n\n");
		return;
	}

	// ������ ���� ù��°�� �ƴϸ� ����
	while (curr != NULL)
	{
		if (strcmp(curr->BookTitle, deleteB) == 0)
		{
			//printf("%s ����\n", curr->BookTitle);
			prev->next = curr->next;
			free(curr); // ���� ��� ����
			printf("�����߽��ϴ�.\n\n");
			return;
		}
		prev = curr;       // ���� ���縦 prev�� �ٰ�
		curr = curr->next; // �׷��� �� next�� �ɰ�
	}
	printf("\n%s ������ �����ϴ�.\n\n", deleteB);
}

void SearchBook(head* headNode, head* rentHeadNode, const char* searchBook)
{
	node* rentCurr = rentHeadNode->headNode;

	node* curr = headNode->headNode;
	node* prev = NULL;

	while (rentCurr != NULL)
	{
		if (strcmp(rentCurr->BookTitle, searchBook) == 0)
		{
			printf("\n======= %s ���� =======\n\n", rentCurr->BookTitle);
			printf("���� : %s\n", rentCurr->BookTitle);
			printf("���� : %d\n", rentCurr->price);
			printf("�۰� : %s\n", rentCurr->author);
			printf("���ǻ� : %s\n", rentCurr->company);
			printf("ID : %s\n", rentCurr->ID);
			printf("\n=======================\n\n");

			printf("�� å�� ���� �뿩���Դϴ�\n\n");
			return;
		}
		rentCurr = rentCurr->next;
	}

	rentCurr = rentHeadNode->headNode;   // rentCurr �ٽ� �Ǿ����� ��������. �ؿ� �� ����ϰŵ�
	while (curr != NULL)
	{

		if (strcmp(curr->BookTitle, searchBook) == 0)
		{
			printf("\n======= %s ���� =======\n\n", curr->BookTitle);
			printf("���� : %s\n", curr->BookTitle);
			printf("���� : %d\n", curr->price);
			printf("�۰� : %s\n", curr->author);
			printf("���ǻ� : %s\n", curr->company);
			printf("ID : %s\n", curr->ID);
			printf("\n=======================\n\n");

			while (1)
			{
				int rent = -1;
				printf("�� å�� �뿩�Ͻðڽ��ϱ�?\n");
				printf("1. �뿩   2. ���\n");
				printf(">> ");
				scanf("%d", &rent);           // ���� ���� �Է��ϸ� ���ѷ��� �Ǵ°� ���߿� �����ؾߵ�
				while (getchar() != '\n');    // �̰� �����Ѱ���

				if (rent == 1)
				{
					// case1. head����Ʈ ùå�̰�, rentHead ù��°(ù �뿩)�� ���
					if (headNode->headNode->BookTitle == curr->BookTitle && rentHeadNode->headNode == NULL)
					{
						rentHeadNode->headNode = headNode->headNode;
						headNode->headNode = headNode->headNode->next;
						rentHeadNode->headNode->next = NULL;
						printf("�뿩�߽��ϴ�\n\n");
						return;
					}
					// case2. head����Ʈ�� ùå�� �ƴϰ�, rentHead�� ù��°�� ���
					else if (headNode->headNode->BookTitle != curr->BookTitle && rentHeadNode->headNode == NULL)
					{
						prev->next = curr->next;
						curr->next = NULL;
						rentHeadNode->headNode = curr;
						printf("�뿩�߽��ϴ�\n\n");
						return;
					}
					// case3. head����Ʈ�� ùå�̰�, rentHead�� ù��°�� �ƴ� ���
					else if (headNode->headNode->BookTitle == curr->BookTitle && rentHeadNode->headNode != NULL)
					{
						while (rentCurr->next != NULL)
						{
							rentCurr = rentCurr->next;
						}
						rentCurr->next = headNode->headNode;
						headNode->headNode = headNode->headNode->next;
						rentCurr->next->next = NULL;
						printf("�뿩�߽��ϴ�\n\n");
						return;
					}
					// case4. head����Ʈ�� rentHead �Ѵ� ù��°�� �ƴ� ���
					else if (headNode->headNode->BookTitle != curr->BookTitle && rentHeadNode->headNode != NULL)
					{
						prev->next = curr->next;
						curr->next = NULL;
						while (rentCurr->next != NULL)
						{
							rentCurr = rentCurr->next;
						}
						rentCurr->next = curr;
						printf("�뿩�߽��ϴ�\n\n");
						return;
					}
				}

				else if (rent == 2)
				{
					break;
				}

				else
				{
					printf("1�� 2�߿� �����ϼ���\n");
				}
			}
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("\n%s ������ �����ϴ�.\n\n", searchBook);
}

void returningBook(head* headNode, head* rentHeadNode, const char* searchBook)
{
	node* curr = headNode->headNode;
	node* rentCurr = rentHeadNode->headNode;
	node* rentPrev = NULL;
	while (rentCurr != NULL)
	{
		if (strcmp(rentCurr->BookTitle, searchBook) == 0)
		{
			printf("\n======= %s ���� =======\n\n", rentCurr->BookTitle);
			printf("���� : %s\n", rentCurr->BookTitle);
			printf("���� : %d\n", rentCurr->price);
			printf("�۰� : %s\n", rentCurr->author);
			printf("���ǻ� : %s\n", rentCurr->company);
			printf("ID : %s\n", rentCurr->ID);
			printf("\n=======================\n\n");

			while (1)
			{
				int rent = -1;
				printf("�� å�� �ݳ��Ͻðڽ��ϱ�?\n");
				printf("1. �ݳ�   2. ���\n");
				printf(">> ");
				scanf("%d", &rent);  // ���⵵ ���� �Է��ϸ� ���ѷ��� �ɵ�
				while (getchar() != '\n');    // �̰� �����Ѱ���

				if (rent == 1)
				{
					// case1. rentHead����Ʈ ù å�̰�, head����Ʈ ������ ���  // �״ϱ� �Ѱ� �� ��������ϰ� �� �ϳ��� �뿩�ߴ� ��Ȳ�ΰ���
					if (rentHeadNode->headNode->BookTitle == rentCurr->BookTitle && headNode->headNode == NULL)
					{
						headNode->headNode = rentHeadNode->headNode;
						rentHeadNode->headNode = rentHeadNode->headNode->next;
						headNode->headNode->next = NULL;
						printf("�ݳ��߽��ϴ�.\n\n");

						return;
					}

					// case2. rentHead����Ʈ�� 2�� �̻��� �־���, head����Ʈ�� ������ ��� // �ִ� ��� å�� �� �뿩�ߴ� ��Ȳ
					else if (rentHeadNode->headNode->BookTitle != rentCurr->BookTitle && headNode->headNode == NULL)
					{
						rentPrev->next = rentCurr->next;
						rentCurr->next = NULL;
						headNode->headNode = rentCurr;
						printf("�ݳ��߽��ϴ�.\n\n");

						return;
					}

					// case3. rentHead����Ʈ ùå, head�� ù��°�� �ƴ� ���
					else if (rentHeadNode->headNode->BookTitle == rentCurr->BookTitle && headNode->headNode != NULL)
					{
						while (curr->next != NULL)
						{
							curr = curr->next;
						}
						curr->next = rentHeadNode->headNode;
						rentHeadNode->headNode = rentHeadNode->headNode->next;
						curr->next->next = NULL;
						printf("�ݳ��߽��ϴ�.\n\n");

						return;
					}
					// case4. rentHead head �� ù��°�� �ƴ� ���
					else if (rentHeadNode->headNode->BookTitle != rentCurr->BookTitle && headNode->headNode != NULL)
					{
						rentPrev->next = rentCurr->next;
						rentCurr->next = NULL;
						while (curr->next != NULL)
						{
							curr = curr->next;
						}
						curr->next = rentCurr;
						printf("�ݳ��߽��ϴ�.\n\n");

						return;
					}
				}

				else if (rent == 2)
				{
					break;
				}

				else
				{
					printf("1�� 2�߿� �����ϼ���\n");
				}
			}
			return;
		}
		rentPrev = rentCurr;
		rentCurr = rentCurr->next;
	}
	printf("�ش� å�� �뿩 ����Ʈ�� �����ϴ�.\n");
}