#include<iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2;

public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2) {}

	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << endl;
	}

	void CopyToNum2() const  // const가 있어서 원래 num2값 못바꾸는데 mutable int num2로 돼있으니까
	{						  
		num2 = num1;			// 이게 가능하다 
	}

};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();

	return 0;
}