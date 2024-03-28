/*
	File: linkedList_main.c
	Created: 24-03-27
	Author: ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

void main()
{
	head* headNode = createHead();
	head* rentHeadNode = createHead();

	while (1)
	{
		int menuNum;

		printf("1. �������\n2. �����˻�(�뿩)\n3. �����ݳ�\n4. ��������\n5. �������\n6. �뿩���� ���\n0. ����\n>>  ");
		scanf("%d", &menuNum);
		getchar();

		if (menuNum != 1 && menuNum != 2 && menuNum != 3 && menuNum != 4 && menuNum != 5 && menuNum != 6 && menuNum != 0)
		{
			printf("1 2 3 4 5 6 0 �߿� �Է��ϼ���\n");
			continue;
		}

		// 1. ���� ���
		if (menuNum == 1)
		{
			char title[40];
			int price = 0;
			char author[40];
			char company[40];
			char ID[40];

			printf("����   >> ");
			scanf("%s", title);
			printf("����   >> ");
			scanf("%d", &price);
			while (getchar() != '\n');

			printf("�۰�   >> ");
			scanf("%s", author);
			printf("���ǻ� >> ");
			scanf("%s", company);
			printf("ID     >> ");
			scanf("%s", ID);

			addBook(headNode, title, price, author, company, ID);
		}
		// 2. ���� �˻�(�뿩)
		if (menuNum == 2)
		{
			char search[40];
			printf("�˻��� å �̸� >> ");
			scanf("%s", search);

			SearchBook(headNode, rentHeadNode, search);
		}

		//3. ���� �ݳ�
		if (menuNum == 3)
		{
			char search[40];
			printf("�ݳ��� å �̸� >> ");
			scanf("%s", search);

			returningBook(headNode, rentHeadNode, search);
		}

		// 4. ���� ����
		if (menuNum == 4)
		{
			char deleteB[40];
			printf("������ å �̸� >> ");
			scanf("%s", deleteB);

			deleteBook(headNode, rentHeadNode, deleteB);
		}

		// 5. ���� ���
		if (menuNum == 5)
		{
			node* curr = headNode->headNode;

			if (headNode->headNode == NULL)
			{
				printf("\n������ �ϳ��� �����ϴ�.\n\n");
			}

			else
			{
				printf("\n========== ��ü å ==========\n");
				while (curr != NULL)
				{
					printf("%s\n", curr->BookTitle);
					curr = curr->next;
				}
				printf("===============================\n");
			}
		}
		// 6. �뿩�� ���� ���
		if (menuNum == 6)
		{
			node* curr = rentHeadNode->headNode;

			if (rentHeadNode->headNode == NULL)
			{
				printf("\n�뿩�� ������ �ϳ��� �����ϴ�\n\n");
			}

			else
			{
				printf("\n========== �뿩�� ��ü å ==========\n");
				while (curr != NULL)
				{
					printf("%s\n", curr->BookTitle);
					curr = curr->next;
				}
				printf("=======================================\n");
			}
		}

		// 0. ������ ���δ� free �ϰ� exit(1)
		if (menuNum == 0)
		{
			node* curr = headNode->headNode;
			node* next;

			while (curr != NULL)
			{
				next = curr->next;
				printf("%s ����\n", curr->BookTitle);
				free(curr);
				curr = next;
			}

			node* rentCurr = rentHeadNode->headNode;
			node* rentNext;

			while (rentCurr != NULL)
			{
				rentNext = rentCurr->next;
				printf("%s ����\n", rentCurr->BookTitle);
				free(rentCurr);
				rentCurr = rentNext;
			}

			free(headNode);
			free(rentHeadNode);
			exit(1);
		}
	}
}