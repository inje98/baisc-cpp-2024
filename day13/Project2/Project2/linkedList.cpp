#include "linkedList.h"
#include<iostream>

void InitList(tLinkedList* pList)
{
    pList->pHeadNode = nullptr;
    pList->iCount = 0;
}

void PushBack(tLinkedList* pList, int iData)
{
    // 데이터를 저장할 노드를 생성. PushBack할때마다 노드객체 하나씩 만들어 지겠지
    tNode* pNode = (tNode*)malloc(sizeof(tNode)); // 그 객체에 iData값 들어갈거고
    pNode->iData = iData;
    pNode->pNextNode = nullptr;  // 데이터를 받아오면 그 노드는 마지막 노드잖아.
    // 그 마지막 노드의 pNextNode는 NULL이어야지. ok?

// 추가한 데이터가 처음인지 아닌지
    if (pList->iCount == 0)
    {
        pList->pHeadNode = pNode;  //처음 들어왔다면 pHeadNode가 들어온 놈을 가리켜야지
    }
    else
    {
        // 현재 가장 마지막 노드를 찾아서
        // 그 노드의 pNextNode가 지금 막 생성한 놈을 가리키게 해야지

        tNode* pCurFinalNode = pList->pHeadNode;
        while (1)
        {
            if (pCurFinalNode->pNextNode == nullptr)
            {
                break;  // 마지막 노드(pNextNode == NULL)이면 나가
            }
            pCurFinalNode = pCurFinalNode->pNextNode; // 계속 NULL찾아
        }
        pCurFinalNode->pNextNode = pNode; // NULL 찾았으니 이제 거기가 새로운 놈 가리키게

    }
    ++pList->iCount;

}
