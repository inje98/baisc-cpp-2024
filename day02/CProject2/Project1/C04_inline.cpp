#include<iostream>

using namespace std;

inline int SQUARY(int x)
{
	return x * x;
}


int main()
{
	cout << SQUARY(5) << endl;
	cout << SQUARY(12) << endl;

	return 0;
}