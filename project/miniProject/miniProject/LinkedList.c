/*
	File: linkedList.c
	Created: 24-03-27
	Author: 김인제
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
	node* prev = NULL;  // 전 노드랑 다음 노드랑 연결해야 하기때문에 만들어둠

	while (rentCurr != NULL)
	{
		if (strcmp(rentCurr->BookTitle, deleteB) == 0)
		{
			printf("이 책은 현재 대여 중입니다.\n\n");
			return;
		}
		rentCurr = rentCurr->next;
	}

	if (curr == NULL)
	{
		printf("도서가 하나도 없습니다.\n");
		return;
	}

	// 삭제할 책이 첫 번째 책인 경우
	if (strcmp(headNode->headNode->BookTitle, deleteB) == 0)
	{
		//printf("%s 삭제\n", headNode->headNode->BookTitle);
		headNode->headNode = headNode->headNode->next; // 헤드를 다음 노드로 옮겨놓고
		free(curr); // 첫 노드 해제
		printf("삭제했습니다.\n\n");
		return;
	}

	// 삭제할 놈이 첫번째만 아니면 여기
	while (curr != NULL)
	{
		if (strcmp(curr->BookTitle, deleteB) == 0)
		{
			//printf("%s 삭제\n", curr->BookTitle);
			prev->next = curr->next;
			free(curr); // 현재 노드 해제
			printf("삭제했습니다.\n\n");
			return;
		}
		prev = curr;       // 나의 현재를 prev에 줄게
		curr = curr->next; // 그러고 난 next가 될게
	}
	printf("\n%s 도서가 없습니다.\n\n", deleteB);
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
			printf("\n======= %s 정보 =======\n\n", rentCurr->BookTitle);
			printf("제목 : %s\n", rentCurr->BookTitle);
			printf("가격 : %d\n", rentCurr->price);
			printf("작가 : %s\n", rentCurr->author);
			printf("출판사 : %s\n", rentCurr->company);
			printf("ID : %s\n", rentCurr->ID);
			printf("\n=======================\n\n");

			printf("이 책은 현재 대여중입니다\n\n");
			return;
		}
		rentCurr = rentCurr->next;
	}

	rentCurr = rentHeadNode->headNode;   // rentCurr 다시 맨앞으로 보내놓기. 밑에 또 써야하거든
	while (curr != NULL)
	{

		if (strcmp(curr->BookTitle, searchBook) == 0)
		{
			printf("\n======= %s 정보 =======\n\n", curr->BookTitle);
			printf("제목 : %s\n", curr->BookTitle);
			printf("가격 : %d\n", curr->price);
			printf("작가 : %s\n", curr->author);
			printf("출판사 : %s\n", curr->company);
			printf("ID : %s\n", curr->ID);
			printf("\n=======================\n\n");

			while (1)
			{
				int rent = -1;
				printf("이 책을 대여하시겠습니까?\n");
				printf("1. 대여   2. 취소\n");
				printf(">> ");
				scanf("%d", &rent);           // 여기 문자 입력하면 무한루프 되는거 나중에 예외해야됨
				while (getchar() != '\n');    // 이게 예외한거임

				if (rent == 1)
				{
					// case1. head리스트 첫책이고, rentHead 첫번째(첫 대여)인 경우
					if (headNode->headNode->BookTitle == curr->BookTitle && rentHeadNode->headNode == NULL)
					{
						rentHeadNode->headNode = headNode->headNode;
						headNode->headNode = headNode->headNode->next;
						rentHeadNode->headNode->next = NULL;
						printf("대여했습니다\n\n");
						return;
					}
					// case2. head리스트는 첫책이 아니고, rentHead는 첫번째인 경우
					else if (headNode->headNode->BookTitle != curr->BookTitle && rentHeadNode->headNode == NULL)
					{
						prev->next = curr->next;
						curr->next = NULL;
						rentHeadNode->headNode = curr;
						printf("대여했습니다\n\n");
						return;
					}
					// case3. head리스트는 첫책이고, rentHead는 첫번째가 아닌 경우
					else if (headNode->headNode->BookTitle == curr->BookTitle && rentHeadNode->headNode != NULL)
					{
						while (rentCurr->next != NULL)
						{
							rentCurr = rentCurr->next;
						}
						rentCurr->next = headNode->headNode;
						headNode->headNode = headNode->headNode->next;
						rentCurr->next->next = NULL;
						printf("대여했습니다\n\n");
						return;
					}
					// case4. head리스트랑 rentHead 둘다 첫번째가 아닌 경우
					else if (headNode->headNode->BookTitle != curr->BookTitle && rentHeadNode->headNode != NULL)
					{
						prev->next = curr->next;
						curr->next = NULL;
						while (rentCurr->next != NULL)
						{
							rentCurr = rentCurr->next;
						}
						rentCurr->next = curr;
						printf("대여했습니다\n\n");
						return;
					}
				}

				else if (rent == 2)
				{
					break;
				}

				else
				{
					printf("1과 2중에 선택하세요\n");
				}
			}
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("\n%s 도서가 없습니다.\n\n", searchBook);
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
			printf("\n======= %s 정보 =======\n\n", rentCurr->BookTitle);
			printf("제목 : %s\n", rentCurr->BookTitle);
			printf("가격 : %d\n", rentCurr->price);
			printf("작가 : %s\n", rentCurr->author);
			printf("출판사 : %s\n", rentCurr->company);
			printf("ID : %s\n", rentCurr->ID);
			printf("\n=======================\n\n");

			while (1)
			{
				int rent = -1;
				printf("이 책을 반납하시겠습니까?\n");
				printf("1. 반납   2. 취소\n");
				printf(">> ");
				scanf("%d", &rent);  // 여기도 문자 입력하면 무한루프 될듯
				while (getchar() != '\n');    // 이게 예외한거임

				if (rent == 1)
				{
					// case1. rentHead리스트 첫 책이고, head리스트 없었던 경우  // 그니까 한개 딱 도서등록하고 그 하나를 대여했던 상황인거지
					if (rentHeadNode->headNode->BookTitle == rentCurr->BookTitle && headNode->headNode == NULL)
					{
						headNode->headNode = rentHeadNode->headNode;
						rentHeadNode->headNode = rentHeadNode->headNode->next;
						headNode->headNode->next = NULL;
						printf("반납했습니다.\n\n");

						return;
					}

					// case2. rentHead리스트에 2개 이상이 있었고, head리스트는 없었던 경우 // 있던 모든 책을 다 대여했던 상황
					else if (rentHeadNode->headNode->BookTitle != rentCurr->BookTitle && headNode->headNode == NULL)
					{
						rentPrev->next = rentCurr->next;
						rentCurr->next = NULL;
						headNode->headNode = rentCurr;
						printf("반납했습니다.\n\n");

						return;
					}

					// case3. rentHead리스트 첫책, head는 첫번째가 아닌 경우
					else if (rentHeadNode->headNode->BookTitle == rentCurr->BookTitle && headNode->headNode != NULL)
					{
						while (curr->next != NULL)
						{
							curr = curr->next;
						}
						curr->next = rentHeadNode->headNode;
						rentHeadNode->headNode = rentHeadNode->headNode->next;
						curr->next->next = NULL;
						printf("반납했습니다.\n\n");

						return;
					}
					// case4. rentHead head 다 첫번째가 아닌 경우
					else if (rentHeadNode->headNode->BookTitle != rentCurr->BookTitle && headNode->headNode != NULL)
					{
						rentPrev->next = rentCurr->next;
						rentCurr->next = NULL;
						while (curr->next != NULL)
						{
							curr = curr->next;
						}
						curr->next = rentCurr;
						printf("반납했습니다.\n\n");

						return;
					}
				}

				else if (rent == 2)
				{
					break;
				}

				else
				{
					printf("1과 2중에 선택하세요\n");
				}
			}
			return;
		}
		rentPrev = rentCurr;
		rentCurr = rentCurr->next;
	}
	printf("해당 책이 대여 리스트에 없습니다.\n");
}