// �޸� �����Ҵ�: new ������ ���
// ���α׷� ���� �߿� �޸𸮸� �Ҵ� �޴´�

#include<iostream>
using namespace std;

int main()
{
	cout << "int size: "<< sizeof(int) << endl;
	int *pi = new int;  // int ũ��(4) ��ŭ �� ������ ������ �Ҵ�, �Ҵ� ���� �޸��� �ּҸ� ����

	*pi = 10;

	cout << "pi�� ����Ű�� ���� ����� ��: " << *pi << endl;
	delete pi;
	//cout << "pi�� ����Ű�� ���� ����� ��: " << *pi << endl;   // �����ϰ� ���� �� ������

	int* pary = new int[10]; // int 10ĭ[4 x 10] ����Ʈ ��ŭ�� ������ �� ������ �Ҵ�

	return 0;
}