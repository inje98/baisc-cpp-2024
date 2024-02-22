#include<iostream>

using namespace std;


// 팀 작업할때 함수 이름 중복 될 수도 있으니까
namespace BestComImp1
{
	void SimpleFunc(void)
	{
		cout << "BestCom이 정의한 함수" << endl;
	}
}

namespace ProgComImp1
{
	void SimpleFunc(void)
	{
		cout << "ProgCom이 정의한 함수" << endl;
	}
}
int main()
{	
	BestComImp1::SimpleFunc();
	ProgComImp1::SimpleFunc();

	return 0;
}