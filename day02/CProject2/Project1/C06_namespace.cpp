#include<iostream>

using namespace std;

namespace BestComImp1
{
	void SimpleFunc(void);
}

namespace ProgComImp1
{
	void SimpleFunc(void);
}

int main()
{
	BestComImp1::SimpleFunc();
	ProgComImp1::SimpleFunc();

	return 0;
}


void BestComImp1::SimpleFunc(void)
{
	cout << "Bestcom이 정의한 함수" << endl;
}

void ProgComImp1::SimpleFunc(void)
{
	cout << "Progcom이 정의한 함수" << endl;
}