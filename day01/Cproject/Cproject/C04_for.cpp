#include<iostream>

using namespace std;

int main()
{
	int sum = 0; // �ʱ�ȭ �ݵ�� ����� ��. �ֳ�
	for (int i = 1; i <= 100; i++) {
		sum += i; // �갡 sum = sum + 1 ���ݾ� rvalue�� sum�� ���� �־�� �ϴϱ�.
	}
	cout << sum << endl;

	return 0;
}