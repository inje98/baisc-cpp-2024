#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �뿩 ����Ʈ ���� �뿩 ��� �����ű��� �Ȱ�
// ���� �ݳ� �޴� �ϳ� �� �ļ� �ݳ� �ϸ� �뿩 ����Ʈ���� ���� ����Ʈ�� �ű�� �۾�

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
	node* prev = NULL;  // �� ���� ���� ���� �����ؾ� �ϱ⶧���� ������

	if (curr == NULL)
	{
		printf("å�� �ϳ��� ���µ���??\n");
		return;
	}

	// ������ å�� ù ��° å�� ���
	if (strcmp(headNode->headNode->BookTitle, deleteB) == 0)
	{
		//printf("%s ����\n", headNode->headNode->BookTitle);
		headNode->headNode = headNode->headNode->next; // ��带 ���� ���� �Űܳ���
		free(curr); // ù ��� ����
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
			return;
		}
		prev = curr;       // ���� ���縦 prev�� �ٰ�
		curr = curr->next; // �׷��� �� next�� �ɰ�
	}
	printf("\n%s ���µ�?\n\n", deleteB);
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
			printf("\n======= %s ���� =======\n\n", curr->BookTitle);
			printf("���� : %s\n", curr->BookTitle);
			printf("���� : %d\n", curr->price);
			printf("�۰� : %s\n", curr->author);
			printf("���ǻ� : %s\n", curr->company);
			printf("ID : %s\n", curr->ID);
			printf("\n=======================\n\n");

			//node* rentCurr = curr;

			while (1)
			{
				int rent = -1;
				printf("�� å�� �뿩�Ͻðڽ��ϱ�?\n");
				printf("1. �뿩   2. ���\n");
				printf(">> ");
				scanf("%d", &rent);           // ���� ���� �Է��ϸ� ���ѷ��� �Ǵ°� ���߿� �����ؾߵ�

				if (rent == 1)
				{
					// case1. head����Ʈ ùå�̰�, rentHead ù��°(ù �뿩)�� ���
					if (headNode->headNode->BookTitle == curr->BookTitle && rentHeadNode->headNode == NULL)
					{
						rentHeadNode->headNode = headNode->headNode;
						headNode->headNode = headNode->headNode->next;
						rentHeadNode->headNode->next = NULL;
						return;
					}
					// case2. head����Ʈ�� ùå�� �ƴϰ�, rentHead�� ù��°�� ���
					else if (headNode->headNode->BookTitle != curr->BookTitle && rentHeadNode->headNode == NULL)
					{
						prev->next = curr->next;
						curr->next = NULL;
						rentHeadNode->headNode = curr;
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
			//return rentCurr;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("\n%s ���µ�?\n\n", searchBook);
	//return NULL;
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

				if (rent == 1)
				{
					// case1. rentHead����Ʈ ù å�̰�, head����Ʈ ������ ���  // �״ϱ� �Ѱ� �� ��������ϰ� �� �ϳ��� �뿩�ߴ� ��Ȳ�ΰ���
					if (rentHeadNode->headNode->BookTitle == rentCurr->BookTitle && headNode->headNode == NULL)
					{
						headNode->headNode = rentHeadNode->headNode;
						rentHeadNode->headNode = rentHeadNode->headNode->next;
						headNode->headNode->next = NULL;
						return;
					}

					// case2. rentHead����Ʈ�� 2�� �̻��� �־���, head����Ʈ�� ������ ��� // �ִ� ��� å�� �� �뿩�ߴ� ��Ȳ
					else if (rentHeadNode->headNode->BookTitle != rentCurr->BookTitle && headNode->headNode == NULL)
					{
						rentPrev->next = rentCurr->next;
						rentCurr->next = NULL;
						headNode->headNode = rentCurr;
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
	printf("�׷�å ������ �����ϴ�\n");
}

void main()
{
	head* headNode = createHead();
	head* rentHeadNode = createHead();

	while (1)
	{
		int menuNum;

		printf("1. �������\n2. �����˻�(�뿩)\n3. �����ݳ�\n4. ��������\n5. �������\n6. �뿩�� å ���\n0. ����\n>>  ");
		scanf("%d", &menuNum);
		getchar();

		if (menuNum != 1 && menuNum != 2 && menuNum != 3 && menuNum != 4 && menuNum != 5 && menuNum != 6 && menuNum != 0)
		{
			printf("1 2 3 4 5 6 0 �߿� �Է��ϼ�\n");
			continue;
		}

		// 1. �������ϸ鼭 next�� ������� ����
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
			printf("�۰�   >> ");
			scanf("%s", author);
			printf("���ǻ� >> ");
			scanf("%s", company);
			printf("ID     >> ");
			scanf("%s", ID);

			addBook(headNode, title, price, author, company, ID);
		}
		// 2. while ���鼭 if���� strcmp == 0�� �ɸ��� ����ϰ� �ϸ� �ɵ�?
		if (menuNum == 2)
		{
			char search[40];
			printf("�˻��� å �̸� >> ");
			scanf("%s", search);

			SearchBook(headNode, rentHeadNode, search);
		}


		//3. �뿩 ����Ʈ���� �˻��ѳ� ������ ���� ���� ���� ����Ʈ�� ����
		if (menuNum == 3)
		{
			char search[40];
			printf("�ݳ��� å �̸� >> ");
			scanf("%s", search);

			returningBook(headNode, rentHeadNode, search);
		}




		// 4. while ���鼭 if���� strcmp == 0�� �ɸ��� free�ϴµ�, �̷��� �ȵ��� �ʳ�?
		// �ȴ�. ���� ���� ���� ��Ų ���� ���� �����ϰ� �����Ѱ� free
		if (menuNum == 4)
		{
			char deleteB[40];
			printf("������ å �̸� >> ");
			scanf("%s", deleteB);

			deleteBook(headNode, deleteB);
		}

		// 5. while ���鼭 �� next next �� ���
		if (menuNum == 5)
		{
			node* curr = headNode->headNode;

			if (headNode->headNode == NULL)
			{
				printf("\nå�� �ϳ��� ���µ�?\n\n");
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

		if (menuNum == 6)
		{
			node* curr = rentHeadNode->headNode;

			if (rentHeadNode->headNode == NULL)
			{
				printf("\n�뿩�� å�� �ϳ��� ���µ�?\n\n");
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