#include<iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "객체생성" << endl;
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this;  // *this는 객체 자기자신 obj임!
					   // 살짝 모르겠는데 일단 이렇게 받아들이자
	}

	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	SelfRef obj(3);   // 필드에 있는 num = 3 이 됨.
	SelfRef& ref = obj.Adder(2); // num = 5, num = 5를 가지고 있는 객체 obj가 반환 됐자너. 
								 // 자료형이 SelfRef인 변수 ref랑 obj 물아일체

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	
	return 0;
}