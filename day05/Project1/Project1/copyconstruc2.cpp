#include<iostream>

using namespace std;

class AA
{
	int a;
	int b;

public:
	AA(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void AAInfo()
	{
		cout << a << " " << b << endl;
	}
};

int main()
{
	AA obj1(10, 20);
	obj1.AAInfo();

	AA obj2(obj1);  // 복사 생성자 없어도 기본 복사디폴트생성자 덕으로 이게 되긴해.
	obj2.AAInfo();

	return 0;
}