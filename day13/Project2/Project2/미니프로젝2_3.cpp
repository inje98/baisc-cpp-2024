#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE
{
	char BookTitle[40];
	int price;
	char author[40];
	char company[40];
	char ID[40];
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

void deleteBook(head* headNode, const char* deleteB)
{
	node* curr = headNode->headNode;
	node* prev = NULL;  // 전 노드랑 다음 노드랑 연결해야 하기때문에 만들어둠

	if (curr == NULL)
	{
		printf("책이 하나도 없는데용??\n");
		return;
	}

	// 삭제할 책이 첫 번째 책인 경우
	if (strcmp(headNode->headNode->BookTitle, deleteB) == 0)
	{
		//printf("%s 삭제\n", headNode->headNode->BookTitle);
		headNode->headNode = headNode->headNode->next; // 헤드를 다음 노드로 옮겨놓고
		free(curr); // 첫 노드 해제
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
			return;
		}
		prev = curr;       // 나의 현재를 prev에 줄게
		curr = curr->next; // 그러고 난 next가 될게
	}
	printf("\n%s 없는데?\n\n", deleteB);
}


void SearchBook(head* headNode, head* rentHeadNode, const char* searchBook)
{
	node* rentCurr = rentHeadNode->headNode;

	node* curr = headNode->headNode;
	node* prev = NULL;
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

			//node* rentCurr = curr;

			while (1)    
			{
				int rent = -1;
				printf("이 책을 대여하시겠습니까?\n");
				printf("1. 대여   2. 취소\n");
				printf(">> ");
				scanf("%d", &rent);           // 여기 문자 입력하면 무한루프 되는거 나중에 예외해야됨

				if (rent == 1)
				{
					// case1. head리스트 첫책이고, rentHead 첫번째(첫 대여)인 경우
					if (headNode->headNode->BookTitle == curr->BookTitle && rentHeadNode->headNode == NULL)   
					{
						rentHeadNode->headNode == headNode->headNode;
						headNode->headNode = headNode->headNode->next;
						rentHeadNode->headNode->next == NULL;
						return;
					}
					// case2. head리스트는 첫책이 아니고, rentHead는 첫번째인 경우
					else if (headNode->headNode->BookTitle != curr->BookTitle && rentHeadNode->headNode == NULL)
					{
						prev->next = curr->next;
						curr->next = NULL;
						rentHeadNode->headNode = curr;  
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
			//return rentCurr;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("\n%s 없는데?\n\n", searchBook);
	//return NULL;
}



int main()
{
	head* headNode = createHead();
	head* rentHeadNode = createHead();
	
	while (1)
	{
		int menuNum;

		printf("1. 도서등록\n2. 도서검색\n3. 도서삭제\n4. 도서출력\n5. 대여한 책 출력\n0. 종료\n>>  ");
		scanf("%d", &menuNum);
		getchar();

		if (menuNum != 1 && menuNum != 2 && menuNum != 3 && menuNum != 4 && menuNum != 5 && menuNum != 0)
		{
			printf("1 2 3 4 0 중에 입력하셈\n");
			continue;
		}


		// 1. 노드생성하면서 next에 연결시켜 놓기
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
			printf("작가   >> ");
			scanf("%s", author);
			printf("출판사 >> ");
			scanf("%s", company);
			printf("ID     >> ");
			scanf("%s", ID);


			addBook(headNode, title, price, author, company, ID);

		}
		// 2. while 돌면서 if문에 strcmp == 0에 걸린놈 출력하게 하면 될듯?
		if (menuNum == 2)
		{
			char search[40];
			printf("검색할 책 이름 >> ");
			scanf("%s", search);


			SearchBook(headNode, rentHeadNode, search);

			//node* rentBook = SearchBook(headNode, search);

			//int rent = -1;
			//printf("이 책을 대여하시겠습니까?\n");
			//printf("1. 대여   2. 취소\n");
			//printf(">> ");
			//scanf("%d", &rent);

			//if (rent == 1)
			//{
			//	if (rentHeadNode->headNode == NULL)  // 대여한게 처음이라면 여기
			//	{
			//		rentHeadNode->headNode = rentBook;
			//	}
			//}
		}
		// 3. while 돌면서 if문에 strcmp == 0에 걸린놈 free하는데, 이러면 안되지 않나?
		// 된다. 전에 노드랑 삭제 시킨 다음 노드랑 연결하고 삭제한건 free
		if (menuNum == 3)
		{
			char deleteB[40];
			printf("삭제할 책 이름 >> ");
			scanf("%s", deleteB);

			deleteBook(headNode, deleteB);

		}


		// 4. while 돌면서 다 next next 다 출력
		if (menuNum == 4)
		{
			node* curr = headNode->headNode;

			if (headNode->headNode == NULL)
			{
				printf("\n책이 하나도 없는데?\n\n");
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

		if (menuNum == 5)
		{
			node* curr = rentHeadNode->headNode;

			if (rentHeadNode->headNode == NULL)
			{
				printf("\n대여한 책이 하나도 없는데?\n\n");
			}

			else
			{
				printf("\n========== 대여한 전체 책 ==========\n");
				while (curr != NULL)
				{
					printf("%s\n", curr->BookTitle);
					curr = curr->next;
				}
				printf("===============================\n");
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

			free(headNode);
			exit(1);
		}

	}
	return 0;
}