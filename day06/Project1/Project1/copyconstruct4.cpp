#include<iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) :num(n)
	{
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}

	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main(void)
{
	Temporary(100);  // 이름없는 임시객체를 생성한거임!
	cout << "************* after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "************* after make!" << endl << endl;

	const Temporary& ref = Temporary(300);  //const 빼면 실행안됨
	cout << "************* end of main!" << endl << endl;

	return 0;
}