#include<iostream>
using namespace std;


void swap(int& a, int& b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

}

int main() {

	int num1 = 10;
	int num2 = 20;
	cout << "before" << endl;
	cout << num1 << endl;
	cout << num2 << endl;

	swap(num1, num2);
	
	cout << "\nafter" << endl;
	cout << num1 << endl;
	cout << num2 << endl;


	return 0;
}