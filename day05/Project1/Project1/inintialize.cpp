#include<iostream>

using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "empty object" << endl;
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA& ref;
	const int& num;  // const int &num이면 숫자 넣을 수 있음!! (원래 int &num이면 변수와야 했잖아)

public:
	BBB(AAA& r, const int& n) :ref(r), num(n){} // 이렇게 하면 생성자가 호출만 되면 초기화 되는거임!

	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num" << num << endl;
	}
};

int main(void)
{
	AAA obj1; 
	BBB obj2(obj1, 20);  
	obj2.ShowYourName();
	return 0;
}