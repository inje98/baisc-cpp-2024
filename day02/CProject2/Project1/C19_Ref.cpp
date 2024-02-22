#include<iostream>
using namespace std;

int num = 20;


int& Func1(int n)
{
	num += n;
	return num;
}



int main() {

	int& ref = Func1(10);
	
	cout << ref << endl;

	num = 100;

	cout << num << endl;

	cout << ref << endl;

	return 0;
}