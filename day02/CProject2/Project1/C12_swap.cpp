#include<iostream>

using namespace std;

void swap(int* pa, int* pb) //a : 0x000000b61a19f504
							//b : 0x000000b61a19f524
{
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

	cout << "\n\nafter" << endl;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;


	return 0;
}

