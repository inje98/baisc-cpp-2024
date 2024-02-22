#include<iostream>
using namespace std;



int main() {
	int a = 10;
	int b = 20;

	cout << "바꾸기 전" << endl;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	cout << "\n\n바뀐 후" << endl;

	int temp;

	temp = a;
	a = b;
	b = temp;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	return 0;
}