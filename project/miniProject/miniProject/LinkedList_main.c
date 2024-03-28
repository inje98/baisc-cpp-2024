/*
	File: linkedList_main.c
	Created: 24-03-27
	Author: 김인제
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

		printf("1. 도서등록\n2. 도서검색(대여)\n3. 도서반납\n4. 도서삭제\n5. 도서출력\n6. 대여도서 출력\n0. 종료\n>>  ");
		scanf("%d", &menuNum);
		getchar();

		if (menuNum != 1 && menuNum != 2 && menuNum != 3 && menuNum != 4 && menuNum != 5 && menuNum != 6 && menuNum != 0)
		{
			printf("1 2 3 4 5 6 0 중에 입력하세요\n");
			continue;
		}

		// 1. 도서 등록
		if (menuNum == 1)
		{
			char title[40];
			int price = 0;
			char author[40];
			char company[40];
			char ID[40];

			printf("제목   >> ");
			scanf("%s", title);
			printf("가격   >> ");
			scanf("%d", &price);
			while (getchar() != '\n');

			printf("작가   >> ");
			scanf("%s", author);
			printf("출판사 >> ");
			scanf("%s", company);
			printf("ID     >> ");
			scanf("%s", ID);

			addBook(headNode, title, price, author, company, ID);
		}
		// 2. 도서 검색(대여)
		if (menuNum == 2)
		{
			char search[40];
			printf("검색할 책 이름 >> ");
			scanf("%s", search);

			SearchBook(headNode, rentHeadNode, search);
		}

		//3. 도서 반납
		if (menuNum == 3)
		{
			char search[40];
			printf("반납할 책 이름 >> ");
			scanf("%s", search);

			returningBook(headNode, rentHeadNode, search);
		}

		// 4. 도서 삭제
		if (menuNum == 4)
		{
			char deleteB[40];
			printf("삭제할 책 이름 >> ");
			scanf("%s", deleteB);

			deleteBook(headNode, rentHeadNode, deleteB);
		}

		// 5. 도서 출력
		if (menuNum == 5)
		{
			node* curr = headNode->headNode;

			if (headNode->headNode == NULL)
			{
				printf("\n도서가 하나도 없습니다.\n\n");
			}

			else
			{
				printf("\n========== 전체 책 ==========\n");
				while (curr != NULL)
				{
					printf("%s\n", curr->BookTitle);
					curr = curr->next;
				}
				printf("===============================\n");
			}
		}
		// 6. 대여한 도서 출력
		if (menuNum == 6)
		{
			node* curr = rentHeadNode->headNode;

			if (rentHeadNode->headNode == NULL)
			{
				printf("\n대여한 도서가 하나도 없습니다\n\n");
			}

			else
			{
				printf("\n========== 대여한 전체 책 ==========\n");
				while (curr != NULL)
				{
					printf("%s\n", curr->BookTitle);
					curr = curr->next;
				}
				printf("=======================================\n");
			}
		}

		// 0. 남은거 전부다 free 하고 exit(1)
		if (menuNum == 0)
		{
			node* curr = headNode->headNode;
			node* next;

			while (curr != NULL)
			{
				next = curr->next;
				printf("%s 삭제\n", curr->BookTitle);
				free(curr);
				curr = next;
			}

			node* rentCurr = rentHeadNode->headNode;
			node* rentNext;

			while (rentCurr != NULL)
			{
				rentNext = rentCurr->next;
				printf("%s 삭제\n", rentCurr->BookTitle);
				free(rentCurr);
				rentCurr = rentNext;
			}

			free(headNode);
			free(rentHeadNode);
			exit(1);
		}
	}
}