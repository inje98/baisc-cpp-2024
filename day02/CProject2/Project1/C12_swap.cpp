#include<iostream>

using namespace std;
							// 주소를 받을거야
void swap(int* pa, int* pb) //a : 0x000000b61a19f504 이런게 주소값 							
{							//b : 0x000000b61a19f524							
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main() {

	int a = 10;
	int b = 20;

	int* pa = &a;
	int* pb = &b;


	cout << "before" << endl;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	swap(pa, pb);

	cout << "\nafter" << endl;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;


	return 0;
}

