#include<iostream>

using namespace std;

int main() {
	
	int inKey;

	cout << "숫자입력 > ";
	cin >> inKey;

	switch (inKey) {
	case 1:
		cout << "1입니다." << endl;
		break;
	case 2:
		cout << "2입니다." << endl;
		break;
	case 3:
		cout << "3입니다." << endl;
		break;
	default:
		cout << "이것도 저것도 아닙니다" << endl;
		break;
	}



	return 0;
}