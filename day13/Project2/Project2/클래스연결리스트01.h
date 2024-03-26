#pragma once
#pragma once

template<typename T>
struct tListNode
{
    T data;
    tListNode* pPrev;
    tListNode* pNext;  // tListNode<T> 지꺼엔 이렇게 안적어도 됨

    tListNode() : data(), pNext(nullptr), pPrev(nullptr)
    {}

    tListNode(const T& data, tListNode* pPrev, tListNode* pNext)
        : data(data), pPrev(pPrev), pNext(pNext)
    {}
};


template<typename T>
class CList
{
private:
    tListNode<T>* pHeadNode; // 얘는 지께 아니니까 tListNode<T> 해야한다
    tListNode<T>* pTail;
    int iCount;

public:
    CList();
    ~CList();
    void PushBack(const T& data);
    void PushFront(const T& data);
};

template<typename T>
CList<T>::CList() : pHeadNode(nullptr), pTail(nullptr), iCount(0)
{}

template<typename T>
CList<T> ::~CList()
{
    tListNode<T>* Curr = pHeadNode;

    while (Curr != nullptr)
    {
        tListNode<T>* Next = Curr->pNext;
        delete(Curr);
        Curr = Next;
    }
}

template<typename T>
void CList<T>::PushBack(const T& data)
{
    tListNode<T>* newNode = new tListNode<T>(data, nullptr, nullptr);

    if (pHeadNode == nullptr)
    {
        pHeadNode = newNode;
        pTail = newNode;
    }

    else
    {
        pTail->pNext = newNode;
        newNode->pPrev = pTail;

        pTail = newNode;
    }
    ++iCount;
}

template<typename T>
void CList<T>::PushFront(const T& data)
{
    tListNode<T>* newNode = new tListNode<T>(data, nullptr, pHeadNode);
    pHeadNode->pPrev = newNode;
    pHeadNode = newNode;
    iCount++;
}
