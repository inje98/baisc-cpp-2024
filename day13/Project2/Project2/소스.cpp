#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct _tagNode
{
    int iData;
    struct _tagNode* pNextNode;
} tNode;

typedef struct _tagList
{
    tNode* pHeadNode;
    int iCount;
} tLinkedList;

void InitList(tLinkedList* pList)
{
    pList->pHeadNode = nullptr;
    pList->iCount = 0;
}

void PushBack(tLinkedList* pList, int iData)
{
    tNode* pNode = (tNode*)malloc(sizeof(tNode));
    pNode->iData = iData;
    pNode->pNextNode = nullptr;

    if (pList->iCount == 0)
    {
        pList->pHeadNode = pNode;
    }
    else
    {
        tNode* pCurFinalNode = pList->pHeadNode;
        while (1)
        {
            if (pCurFinalNode->pNextNode == nullptr)
            {
                break;
            }
            pCurFinalNode = pCurFinalNode->pNextNode;
        }
        pCurFinalNode->pNextNode = pNode;
    }
    ++pList->iCount;
}

int main()
{
    tLinkedList list = {};

    InitList(&list);
    PushBack(&list, 100);
    PushBack(&list, 200);
    PushBack(&list, 300);

    // 추가적인 연결 리스트 작업을 수행할 수 있음

    return 0;
}
