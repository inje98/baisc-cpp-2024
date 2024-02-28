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
	// obj.AddNum(20);    // const�� obj ���� ���ھƳ����ϱ� �� �ٲٷ��� �õ��ϸ� ��������
	obj.ShowData();
	return 0;
}