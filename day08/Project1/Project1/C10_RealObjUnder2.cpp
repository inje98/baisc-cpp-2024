#include<iostream>
using namespace std;

// Ŭ���� Data�� �䳻 �� ����
typedef struct Data
{
	int data;
	void(*ShowData)(Data*);  // ShowData ����Լ� ����
	void(*Add)(Data*, int);   // Add ����Լ� ����
} Data;

void ShowData(Data* THIS)		// ShowData ����Լ� ����
{
	cout << "Data: " << THIS->data << endl;
}

void Add(Data* THIS, int num) // Add ����Լ� ����
{
	THIS->data += num;
}

//������ ����� main �Լ�
int main(void)
{
	Data obj1 = { 15, ShowData, Add };
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);

	return 0;

}