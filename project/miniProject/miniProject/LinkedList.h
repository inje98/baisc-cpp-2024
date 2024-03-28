/*
	File: linkedList.h
	Created: 24-03-27
	Author: ±Ë¿Œ¡¶
*/

#ifndef __LinkedList_H__
#define __LinkedList_H__

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

head* createHead();
void addBook(head* headNode, const char* BookTitle, int price, const char* author, const char* company, const char* ID);
void deleteBook(head* headNode, head* rentHeadNode, const char* deleteB);
void SearchBook(head* headNode, head* rentHeadNode, const char* searchBook);
void returningBook(head* headNode, head* rentHeadNode, const char* searchBook);

#endif