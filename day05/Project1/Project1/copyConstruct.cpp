#include<iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "디폴트 생성자 호출" << endl;
	}
	A(int n)
	{
		cout << "A(int n) 생성자 호출" << endl;
	}
	A(const A& r)  // 이 형태를 일단 기억하자. 복사 생성자는 이렇게 쓴다
	{			  // 그래도 이유를 보자면 그냥 A(const A r)이면 지역변수라서 없어지는것마냥 obj3에 obj2가 안들어간다. 일단 이렇게 이해하자 
		cout << "A(const A& r) 생성자 호출" << endl;
	}
};

int main(void)
{
	A obj1;
	A obj2(10);
	A obj3 = obj2;

	return 0;
}