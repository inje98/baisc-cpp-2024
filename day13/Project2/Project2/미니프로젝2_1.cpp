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

void SearchBook(head* headNode, const char* searchBook)
{
	node* curr = headNode->headNode;
	while (curr != NULL)
	{
		if (strcmp(curr->BookTitle, searchBook) == 0)
		{
			printf("%s 있다!\n", curr->BookTitle);
			return;
		}
		curr = curr->next;
	}
	printf("\n%s 없는데?\n\n", searchBook);
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
		headNode->headNode = headNode->headNode->next; // 헤드를 다음 노드로 옮겨놓고
		free(curr); // 첫 노드 해제
		return;
	}

	// 삭제할 놈이 첫번째만 아니면 여기
	while (curr != NULL)
	{
		if (strcmp(curr->BookTitle, deleteB) == 0)
		{
			prev->next = curr->next;
			free(curr); // 현재 노드 해제
			return;
		}
		prev = curr;       // 나의 현재를 prev에 줄게
		curr = curr->next; // 그러고 난 next가 될게
	}
	printf("%s 없는데?\n", deleteB);
}

int main()
{
	head* headNode = createHead();
	while (1)
	{
		int menuNum;

		printf("1. 도서등록\n2. 도서검색\n3. 도서삭제\n4. 도서출력\n0. 종료\n>>  ");
		scanf("%d", &menuNum);
		getchar();

		if (menuNum != 1 && menuNum != 2 && menuNum != 3 && menuNum != 4 && menuNum != 0)
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

			SearchBook(headNode, search);

		}
		// 3. while 돌면서 if문에 strcmp == 0에 걸린놈 free하는데, 이러면 안되지 않나?
		// 된다. 전에 노드랑 삭제 시킨 다음 노드랑 연결하고 삭제한건 free
		if (menuNum == 3)
		{
			char deleteB[40];
			printf("삭제할 책 이름 >> ");
			scanf("%s", deleteB);

			deleteBook(headNode, deleteB);
			printf("\n%s 삭제!\n\n", deleteB);
		}


		// 4. while 돌면서 다 next next 다 출력
		if (menuNum == 4)
		{
			node* curr = headNode->headNode;

			if (headNode->headNode == NULL)
			{
				printf("\n책이 하나도 없습니다\n");
			}

			else
			{
				printf("\n========== 전체 책 ==========\n");
				while (curr != NULL)
				{
					printf("%s\n", curr->BookTitle);
					curr = curr->next;
				}
				printf("=============================\n");

			}

		}


		// 0. 남은거 전부다 free 하고 exit(1)
		if (menuNum == 0)
		{
			exit(1);
		}

	}
	return 0;
}