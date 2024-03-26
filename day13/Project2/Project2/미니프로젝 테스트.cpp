#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE
{
	char BookTitle[30];
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

int main()
{
	head* headNode = createHead();
	addBook(headNode, "¾î¸°¿ÕÀÚ");
	addBook(headNode, "ÇØ¸®Æ÷ÅÍ");
	addBook(headNode, "´ëÇÑ¹Î±¹");
	addBook(headNode, "¼±´ö¿©¿Õ");


	return 0;
}

