#include<iostream>
#include<limits>  // �߰�: numeric_limits ����� �����ؾ� �մϴ�.

using namespace std;

int main()
{
	int inKey;

	while (1) {
		cout << "�����Է� > ";
		cin >> inKey;

		if (cin.fail()) {
			cout << "�ùٸ� ������ �Է��ϼ���." << endl;
			cin.clear();  // ���� ���¸� ����
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ �߸��� �Է��� ����
			continue;  // ���� �ݺ����� �̵�
		}

	
		if (inKey == 5) {
			cout << "����" << endl;
		}

		else if (inKey > 5) {
			cout << "���ڰ� Ů�ϴ�" << endl;
		}
		else if (inKey < 5) {
			cout << "���ڰ� �۽��ϴ�" << endl;
		}
		else {
			continue;
		}
	}
		
	

	return 0;
}
