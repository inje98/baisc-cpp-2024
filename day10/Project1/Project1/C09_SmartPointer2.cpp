#include<iostream>

using namespace std;

class MyClass
{
	int* ptr;

public:
	MyClass(int p) : ptr(new int[100])
	{
		printf("������ ȣ��\n");
	}

	~MyClass()
	{
		printf("�Ҹ��� ȣ��\n");
		delete[] ptr;
	}
};

int main(void)
{
	MyClass* m1 = new MyClass(10);

	cout << "======================================" << endl;

	unique_ptr<MyClass> m2(new MyClass(20));

	return 0;
}