#include<iostream>

using namespace std;
 // 함수 오버로딩
 // 함수 이름 같아도 매개변수 갯수랑, 매개변수 타입이 다르면 다른 함수처럼 쓸 수 있음
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