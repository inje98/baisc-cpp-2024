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

	Myclass operator+(const Myclass& ref)  // ��ü1 + ��ü2    ==    ��ü1.operator+(��ü2) ���� ���̴�.
	{										// �״ϱ� �̰�  + --> .operator+() �̰Ŷ� ���� �����ų�						 
		value += ref.value;
		return *this;		// �� ��ü ���� ��������� ���� ���� ��ü(result)�� ��ȯ
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