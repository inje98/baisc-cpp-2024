#include<iostream>

using namespace std;
 // �Լ� �����ε�
 // �Լ� �̸� ���Ƶ� �Ű����� ������, �Ű����� Ÿ���� �ٸ��� �ٸ� �Լ�ó�� �� �� ����
void MyFunc(void)
{
	cout << "Func(void) called" << endl;
}

void MyFunc(char c)
{
	cout << "Func(char c) called" << endl;
}

void MyFunc(int a, int b)
{
	cout << "Func(int a, int b) called" << endl;
}

int main(void)
{
	MyFunc();
	MyFunc('A');
	MyFunc(12, 13);
	
	return 0;
}