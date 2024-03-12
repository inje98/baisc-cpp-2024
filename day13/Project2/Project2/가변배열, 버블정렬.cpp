#include<iostream>
#include<time.h>

using namespace std;

class Array
{
	int* data;
	int count;
	int MaxCount;

public:
	Array()
	{
		data = new int[sizeof(int) * 2];
		count = 0;
		MaxCount = 2;
	}

	~Array()
	{
		delete[] data;
	}

	void SizeUp()
	{
		int* newData;
		newData = new int[sizeof(int) * 2 * MaxCount];
		for (int i = 0; i < count; i++)
		{
			newData[i] = data[i];
		}
		data = newData;
		MaxCount *= 2;
	}

	void inputData(int input)
	{
		if (count >= MaxCount)
		{
			SizeUp();
		}
		data[count++] = input;
	}

	void ShowData()
	{
		for (int i = 0; i < count; i++)
		{
			cout << data[i] << endl;
		}
	}

	int* GetData()
	{
		return data;
	}
	int GetCount()
	{
		return count;
	}
};

void Sort(Array& ary, void(*inFunc)(Array&))
{
	inFunc(ary);
}

void BubbleSort(Array& ary)
{

	while (1)
	{
		bool isFinish = true;
		for (int i = 0; i < ary.GetCount() - 1; i++)
		{
			if (ary.GetData()[i] > ary.GetData()[i + 1])
			{
				int temp;
				temp = ary.GetData()[i];
				ary.GetData()[i] = ary.GetData()[i + 1];
				ary.GetData()[i + 1] = temp;
				isFinish = false;
			}
		}

		if (isFinish == true)
		{
			break;
		}
	}

}

int main(void)
{
	Array a1;

	for (int i = 0; i < 10; i++)
	{
		int randomNum;
		randomNum = rand() % 100 + 1;
		a1.inputData(randomNum);
	}
	cout << "변경 전" << endl;
	a1.ShowData();

	Sort(a1, BubbleSort);
	cout << "변경 후" << endl;
	a1.ShowData();

	//BubbleSort(a1);
	//cout << "변경 후" << endl;
	//a1.ShowData();

	return 0;
}
