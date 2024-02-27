// 메모리 동적할당: new 연산자 사용
// 프로그램 실행 중에 메모리를 할당 받는다

#include<iostream>
using namespace std;

int main()
{
	cout << "int size: "<< sizeof(int) << endl;
	int *pi = new int;  // int 크기(4) 만큼 힙 영역에 공간을 할당, 할당 받은 메모리의 주소를 리턴

	*pi = 10;

	cout << "pi가 가리키는 곳에 저장된 값: " << *pi << endl;
	delete pi;
	cout << "pi가 가리키는 곳에 저장된 값: " << *pi << endl;


	return 0;
}