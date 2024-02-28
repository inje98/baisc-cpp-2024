#include<iostream>
using namespace std;

class Simple
{
private:
	int num;
public:
	Simple(int n) :num(n) {}

	Simple& AddNum(int n)
	{
		num += n;
		return *this;
	}

	void ShowData() const
	{
		cout << "num: " << num << endl;
	}
};

int main(void)
{
	const Simple obj(7);
	// obj.AddNum(20);    // const로 obj 값들 못박아놨으니까 값 바꾸려는 시도하면 에러뜨지
	obj.ShowData();
	return 0;
}