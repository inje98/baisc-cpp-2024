#include<iostream>
using namespace std;



int main() {

	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;//(num == ref)
	int* (&pref) = ptr;//(=&num)
	int** (&dpref) = dptr;

	cout << pref <<' '<<ptr<< endl;


	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;


	return 0;
}