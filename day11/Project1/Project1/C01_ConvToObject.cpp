#include<iostream>
using namespace std;

class Number
{
private:
	int num;

public:
	Number(int n = 0) :num(n)
	{
		cout << "Number(int n = 0)" << endl;
	}

	Number& operator=(const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}

	void ShowNumber()
	{
		cout << num << endl;
	}
};

int main(void)
{
	Number num;
	num = 30;  // num = Number(30) 이거랑 같다. num.operator=(Number(30))이랑 같은거. 임시객체가 생성되는거지 여기서도 생성자가 나온다.
	// 임시객체는 자동으로 Number의 객체인거임! 형변환이 일어난거지
	num.ShowNumber();

	return 0;
}