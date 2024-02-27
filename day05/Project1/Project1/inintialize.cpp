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
	const int& num;  // const int &num�̸� ���� ���� �� ����!! (���� int &num�̸� �����;� ���ݾ�)

public:
	BBB(AAA& r, const int& n) :ref(r), num(n){} // �̷��� �ϸ� �����ڰ� ȣ�⸸ �Ǹ� �ʱ�ȭ �Ǵ°���!

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