#include<iostream>

using namespace std;


// �� �۾��Ҷ� �Լ� �̸� �ߺ� �� ���� �����ϱ�
namespace BestComImp1
{
	void SimpleFunc(void)
	{
		cout << "BestCom�� ������ �Լ�" << endl;
	}
}

namespace ProgComImp1
{
	void SimpleFunc(void)
	{
		cout << "ProgCom�� ������ �Լ�" << endl;
	}
}
int main()
{	
	BestComImp1::SimpleFunc();
	ProgComImp1::SimpleFunc();

	return 0;
}