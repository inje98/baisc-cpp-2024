#include<iostream>
using namespace std;

class SoSimple
{
	int num;
	
public:
	SoSimple(int n):num(n) {}

	SoSimple(const SoSimple& copy) :num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy" << endl;
	}
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;   // 아 얘는 객체 그자체를 반환하는거잖아. 이거 반환할때는 복사생성자 호출 안되지.
	}

	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "return 이전" << endl;
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();
	obj.ShowData();
	return 0;
}