#include<iostream>
using namespace std;



int main() {

	int num = 10;
	cout << "num : " << num << endl;

	int *pnum = &num;  // �ּҷ� num������ ����
	int &rnum = num;   // ������ num������ ����

	num = 20;
	cout << "\nnum : " << num << endl;
	cout << "num : " << *pnum << endl;
	cout << "num : " << rnum << endl;

	*pnum = 30;
	cout << "\nnum : " << num << endl;
	cout << "num : " << *pnum << endl;
	cout << "num : " << rnum << endl;


	rnum = 40;
	cout << "\nnum : " << num << endl;
	cout << "num : " << *pnum << endl;
	cout << "num : " << rnum << endl;

	return 0;
}