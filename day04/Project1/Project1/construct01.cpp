#include<iostream>

using namespace std;

class MyClass
{
	int num;

public:
	MyClass()
	{
		cout << "������ ȣ��" << endl;
		num = 10;
	}

	MyClass(int anum)
	{
		num = anum;
		cout << num << endl;
	}

	void MyClassInfo(int anum)
	{
		cout << "num: " << anum << endl;
	}

};




int main()
{
	//MyClass*m = new MyClass();   // �̰͵� ��ü �����Ѱ���(m)
	//m->MyClassInfo(99);

	MyClass m1(10);
	//MyClass m2();
	return 0;
}