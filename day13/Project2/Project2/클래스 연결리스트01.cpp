#include<iostream>

#include "클래스연결리스트01.h"

int main()
{
    CList<int> list;

    for (int i = 0; i < 4; ++i)
    {
        list.PushBack(i);
    }

    return 0;
}