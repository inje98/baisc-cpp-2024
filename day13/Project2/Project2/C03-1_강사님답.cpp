#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	int inkey;
	int sum = 0;

	while (true)
	{
		cout << "���� �Ѱ� �Է�(0 ����): ";
		cin >> inkey;

		v.push_back(inkey);

		sum += inkey;
		cout << sum / v.size() << endl;







		if (!inkey)
		{
			break;
		}
	}
	cout << "���α׷��� �����մϴ�." << endl;
}