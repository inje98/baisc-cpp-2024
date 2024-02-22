#include<iostream>
using namespace std;



int main() {

	int num = 10;
	cout << "num : " << num << endl;

	int *pnum = &num;  // 주소로 num변수에 접근
	int &rnum = num;   // 참조로 num변수에 접근

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