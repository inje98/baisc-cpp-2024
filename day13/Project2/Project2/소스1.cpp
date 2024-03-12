#include<iostream>
#include<time.h>
using namespace std;
//가변배열 클래스 만들어보기

class Array
{
private:
    int* input;
    int Count;
    int MaxCount;

    void AddSize_Ary()
    {
        int* NewInput = new int[sizeof(int) * 2 * MaxCount];

        for (int i = 0; i < Count; ++i)
        {
            NewInput[i] = input[i];
        }

        input = NewInput;
        MaxCount *= 2;
    }

public:
    Array()
    {
        input = new int[sizeof(int) * 2];  // sizeof(int) ==>    4바이트 x 2 = 8바이트
        Count = 0;
        MaxCount = 2;
    }

    ~Array()
    {
        delete[] input;
    }


    void InputData(int inputData)
    {
        if (Count >= MaxCount)
        {
            AddSize_Ary();
        }

        input[Count++] = inputData;
    }

    void ShowData()
    {
        for (int i = 0; i < Count; ++i)
        {
            cout << this->input[i] << endl;
        }
    }

    int* GetAryNum()
    {
        return input;
    }

    int GetAryCount()
    {
        return Count;
    }

};

void Sort(Array& ary, void(*pFunc)(Array&))
{
    pFunc(ary);
}

//void Sort(Array& ary, void(*pFunc)(int*, int))
//{
//   pFunc(ary.GetAryNum(), ary.GetAryCount());
//}

void BubbleSort(Array& ary)
{
    if (ary.GetAryCount() <= 1)
    {
        return;
    }
    while (1)
    {
        bool sortFinish = true;
        for (int i = 0; i < ary.GetAryCount() - 1; ++i)
        {

            if (ary.GetAryNum()[i] > ary.GetAryNum()[i + 1])
            {
                int temp = ary.GetAryNum()[i];
                ary.GetAryNum()[i] = ary.GetAryNum()[i + 1];
                ary.GetAryNum()[i + 1] = temp;
                sortFinish = false;
            }
        }
        if (sortFinish == true)
        {
            break;
        }
    }
}

void BubbleSort(int* ary, int count)
{
    if (count <= 1)
    {
        return;
    }
    while (1)
    {
        bool sortFinish = true;
        for (int i = 0; i < count - 1; ++i)
        {

            if (ary[i] > ary[i + 1])
            {
                int temp = ary[i];
                ary[i] = ary[i + 1];
                ary[i + 1] = temp;
                sortFinish = false;
            }
        }
        if (sortFinish == true)
        {
            break;
        }
    }
}


int main(void)
{
    Array a1;

    /*int a2[10] = { 42, 677, 3, 754, 75, 35, 785 };

    BubbleSort(a2, 10);*/


    /*for (int i = 0; i < 10; i++)
    {
       cout << a2[i] << endl;
    }*/

    for (int i = 0; i < 10; ++i)
    {
        int inputRand = rand() % 100 + 1;
        a1.InputData(inputRand);
    }

    Sort(a1, BubbleSort);

    cout << "변경전" << endl;
    a1.ShowData();

    cout << "변경후" << endl;


    BubbleSort(a1);
    a1.ShowData();

    return 0;
}