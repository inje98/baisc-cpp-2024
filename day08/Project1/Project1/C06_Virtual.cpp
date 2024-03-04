#include<iostream>
using namespace std;

class Base
{
public:
	Base() {};
	~Base() {};

	virtual void func1() {cout << "Base::func1()" << endl;}

	virtual void func2() {cout << "Base::func2()" << endl;}

	void func3() {cout << "Base::func3()" << endl;}
};

class Derived :public Base
{
public:

	Derived() {};
	~Derived() {};


	void func1() {cout << "Derived::func1()" << endl;}

	void func3() {cout << "Derived::func2()" << endl;}

	void func4() {cout << "Derived::func4()" << endl;}
};

int main()
{
	Base b;
	Derived d;

	Base* pb = new Derived();  // Base 타입의 객체 포인터

	pb->func1();
	pb->func2();
	pb->func3();


	Derived* pd = &d;

	pd->func1();
	pd->func2();
	pd->func3();
	pd->func4();

	delete pb;

	return 0;
}// virtual을 쓰면 
//Base* pb = new Derived();
// 이런 경우에 Base 중심이 아니라 객체인 Derived 중심이 되는거지