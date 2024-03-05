#include<iostream>

using namespace std;

class Myclass
{
private:
	int value;

public:
	Myclass(int ivalue) : value(ivalue)
	{}

	void print()
	{
		cout << "value: " << value << endl;
	}

	Myclass operator+(const Myclass& ref)  // 객체1 + 객체2    ==    객체1.operator+(객체2) 같은 말이다.
	{										// 그니까 이게  + --> .operator+() 이거랑 완전 같은거네						 
		value += ref.value;
		return *this;		// 두 객체 안의 멤버변수의 값을 더한 객체(result)를 반환
	}
};

int main()
{
	Myclass a(10);
	a.print();

	Myclass b(a);
	b.print();

	Myclass c = b;
	c.print();

	Myclass d = a + b + c; // a.operator+(b).operator+(c);

	d.print();

	return 0;
}