#pragma once


typedef struct _tagNode
{
	int iData;
	struct _tagNode* pNextNode;
}tNode;


typedef struct _tagList
{
	tNode* pHeadNode;
	int iCount;
}tLinkedList;


// 연결형 리스트 초기화
void InitList(tLinkedList* _pList);


// 리스트에 데이터 추가
void PushBack(tLinkedList* pList, int iData);
