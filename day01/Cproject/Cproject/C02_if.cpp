#include<iostream>
#include<limits>  // 추가: numeric_limits 헤더를 포함해야 합니다.

using namespace std;

int main()
{
	int inKey;

	while (1) {
		cout << "정수입력 > ";
		cin >> inKey;

		if (cin.fail()) {
			cout << "올바른 정수를 입력하세요." << endl;
			cin.clear();  // 에러 상태를 지움
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 버퍼의 잘못된 입력을 무시
			continue;  // 다음 반복으로 이동
		}

	
		if (inKey == 5) {
			cout << "빙고" << endl;
		}

		else if (inKey > 5) {
			cout << "숫자가 큽니다" << endl;
		}
		else if (inKey < 5) {
			cout << "숫자가 작습니다" << endl;
		}
		else {
			continue;
		}
	}
		
	

	return 0;
}
