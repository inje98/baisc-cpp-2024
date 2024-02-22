#include<iostream>

using namespace std;

int global = 100;		// 전역변수 : 프로그램 전체에서 사용가능
int global1 = 200;

void func();

int main()
{

	const int num = 10;
	// num = 100;  // 안됨. num은 그냥 10 그 자체


	int val = 100;		// 지역변수 : 선언된 범위에서만 사용가능
	global = 200;

	cout << "전역변수 : " << global << endl;
	cout << "지역변수 : " << val << endl;

	cout << "전역변수 : " << global1 << endl;

	func();

	cout << global << ' ' << global1 << endl;

	return 0;
}

void func()
{
	global = 10;
	global1 = 10;
	// val = 10; // 안됨
}