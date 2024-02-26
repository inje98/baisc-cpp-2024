#include<iostream>

using namespace std;

class MyClass
{
	int num;

public:
	MyClass()
	{
		cout << "생성자 호출" << endl;
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
	//MyClass*m = new MyClass();   // 이것도 객체 생성한거임(m)
	//m->MyClassInfo(99);

	MyClass m1(10);
	//MyClass m2();
	return 0;
}