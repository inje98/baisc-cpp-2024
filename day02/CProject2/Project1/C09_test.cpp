#include<iostream>

using namespace std;

int global = 100;		// �������� : ���α׷� ��ü���� ��밡��
int global1 = 200;

void func();

int main()
{

	const int num = 10;
	// num = 100;  // �ȵ�. num�� �׳� 10 �� ��ü


	int val = 100;		// �������� : ����� ���������� ��밡��
	global = 200;

	cout << "�������� : " << global << endl;
	cout << "�������� : " << val << endl;

	cout << "�������� : " << global1 << endl;

	func();

	cout << global << ' ' << global1 << endl;

	return 0;
}

void func()
{
	global = 10;
	global1 = 10;
	// val = 10; // �ȵ�
}