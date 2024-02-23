#include<iostream>
#include<stdlib.h>

using namespace std;


class Simple
{
public:
	Simple()  // 생성자(클래스 이름과 같은 매서드)
	{
		cout << "Im simple constructor!" << endl;
	}
};


int main()
{
	cout << "case 1 : ";
	Simple* sp1 = new Simple;

	cout << sp1 << endl;

	cout << "case 2 : ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);
	//cout << sizeof(Simple) << endl;  --> 1이넹

	cout << endl << "end of main" << endl;
	delete sp1;
	free(sp2);

	return 0;
}