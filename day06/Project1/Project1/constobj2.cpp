#include<iostream>
using namespace std;

class Simple
{
private:
	int num;

public:
	Simple(int n): num(n){}

	Simple& AddNum(int n)
	{
		num += n;
		return *this;
	}

	void SimpleFunc()
	{
		cout << "SImpleFunc: " << num << endl;
	}

	void SimpleFunc() const
	{
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const Simple& obj)
{
	obj.SimpleFunc();
}

int main(void)
{
	Simple obj1(2);
	const Simple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();

	YourFunc(obj1);
	YourFunc(obj2);

	return 0;
}

