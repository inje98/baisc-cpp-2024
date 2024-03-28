#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
int Add(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

	return temp;
}

int main() 
{
	int a = 1;
	int b = 2;
	cout << Add(&a, &b) << endl;

	return 0;
}