#include<iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "����Ʈ ������ ȣ��" << endl;
	}
	A(int n)
	{
		cout << "A(int n) ������ ȣ��" << endl;
	}
	A(const A& r)  // �� ���¸� �ϴ� �������. ���� �����ڴ� �̷��� ����
	{			  // �׷��� ������ ���ڸ� �׳� A(const A r)�̸� ���������� �������°͸��� obj3�� obj2�� �ȵ���. �ϴ� �̷��� �������� 
		cout << "A(const A& r) ������ ȣ��" << endl;
	}
};

int main(void)
{
	A obj1;
	A obj2(10);
	A obj3 = obj2;

	return 0;
}