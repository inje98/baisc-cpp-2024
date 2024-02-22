#include<iostream>

using namespace std;

int main()
{
	const int num = 10;
	// num = 10;
	cout << num << endl;
	int num1 = 10;
	int *pnum1;  // 포인터(주소) 변수 pnum1 선언
	pnum1 = &num1;// 변수 num1의 주소를 포인터 변수 pnum1에 저장한다.


	cout << "num에 저장된 값 : " << num << endl;
	cout << "num1에 저장된 값 : " << num1 << endl;
	cout << "num1의 주소값 : " << & num1 << endl;
	cout << "pnum1에 저장된 값 : " << pnum1 << endl;
	cout << "pnum1에 저장된 주소에 있는 데이터 : " << *pnum1 << endl;

	return 0;
}