#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* next;
} node;

typedef struct
{
    node* head;
}headNode;

headNode* createHeadNode(void)
{
    headNode* Head = (headNode*)malloc(sizeof(headNode));
    Head->head = NULL;
    /*Head->head->data = 0;
    Head->head->next = NULL;*/
    
    return Head;
}

void pre_addNode(headNode* pnode, int data) 
{
    // 새로운 노드 생성
    node* newNode = (node*)malloc(sizeof(node));
    // 새로운 노드에 데이터 할당
    newNode->data = data;
    newNode->next = pnode->head;
    // 새로운 노드를 연결
    pnode->head= newNode;
}

void rear_addNode(headNode* pnode, int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (pnode->head == NULL) 
    {
        pnode->head = newNode;
        return;
    }

   /* while (pnode->head->next != NULL)
    {
        pnode->head = pnode->head->next;
    }
    pnode->head->next = newNode;*/
    node* curr = pnode->head;
    while (curr->next != NULL) 
    {
        curr = curr->next;
    }
    curr->next = newNode;
}




void freeList(headNode* pnode)
{
    node* curr = pnode->head;
    node* next;

    while (curr != NULL)
    {
        next = curr->next;
        printf("삭제\n");
        free(curr);
        curr = next;
    }
    free(pnode);
}


void ShowList(headNode* pnode)
{
    node* curr = pnode->head;
    while (curr != NULL)
    {
        printf("현재 Node Data: %d\n", curr->data);
        curr = curr->next;
    }
}

node* searchNode(headNode* pnode, int data)
{
    node* curr = pnode->head;
    while (curr != NULL)
    {
        if (curr->data == data)
        {
           printf("검색한 데이터: %d\n", curr->data);
           return curr;
        }
        curr = curr->next;
    }
}

void main() {
   
    headNode* Head = createHeadNode();
    // 새로운 노드 추가
   // InitHeadNode(Head);
    pre_addNode(Head, 10); // 첫번째 노드로 삽입
    pre_addNode(Head, 20); // 두번째 노드로 삽입
    pre_addNode(Head, 30);
    pre_addNode(Head, 40);
    pre_addNode(Head, 50);
    rear_addNode(Head, 100);
    rear_addNode(Head, 200);
    rear_addNode(Head, 300);
    rear_addNode(Head, 400);
    rear_addNode(Head, 500);

    ShowList(Head);
    
    searchNode(Head, 30);

    // 연결 리스트의 메모리 삭제
    freeList(Head);
}