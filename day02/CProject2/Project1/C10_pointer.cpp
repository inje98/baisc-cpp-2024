#include<iostream>

using namespace std;

int main()
{
	const int num = 10;
	// num = 10;
	cout << num << endl;
	int num1 = 10;
	int *pnum1;  // ������(�ּ�) ���� pnum1 ����
	pnum1 = &num1;// ���� num1�� �ּҸ� ������ ���� pnum1�� �����Ѵ�.


	cout << "num�� ����� �� : " << num << endl;
	cout << "num1�� ����� �� : " << num1 << endl;
	cout << "num1�� �ּҰ� : " << & num1 << endl;
	cout << "pnum1�� ����� �� : " << pnum1 << endl;
	cout << "pnum1�� ����� �ּҿ� �ִ� ������ : " << *pnum1 << endl;

	return 0;
}