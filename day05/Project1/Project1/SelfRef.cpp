#include<iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "��ü����" << endl;
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this;  // *this�� ��ü �ڱ��ڽ� obj��!
					   // ��¦ �𸣰ڴµ� �ϴ� �̷��� �޾Ƶ�����
	}

	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	SelfRef obj(3);   // �ʵ忡 �ִ� num = 3 �� ��.
	SelfRef& ref = obj.Adder(2); // num = 5, num = 5�� ������ �ִ� ��ü obj�� ��ȯ ���ڳ�. 
								 // �ڷ����� SelfRef�� ���� ref�� obj ������ü

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	
	return 0;
}