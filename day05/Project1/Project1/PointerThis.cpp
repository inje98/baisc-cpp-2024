#include<iostream>
#include<cstring>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int num) 
	{
		this->num = num;          // this -> num   이게 필드에 있는 num이다~
		cout << "num = " << num << ", ";
		cout << "address = " << this << endl;
	}
	void ShowSimpleData()
	{
		cout << num << endl;
	}
	SoSimple* GetThisPointer()
	{
		return this;
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
}