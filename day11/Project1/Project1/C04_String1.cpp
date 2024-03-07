#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int code = 97;
	cout << code << endl;
	cout << (char)code << endl;
	cout << "======================" << endl;

	char ary[6] = { 'a', 'b', 'c', 'd', 'e' }; // ���ڿ� Ÿ���� �迭����
	cout << ary << endl;
	cout << "========================" << endl;

	char ary1[] = { 'a', 'b', 'c', '\0', 'e' }; // �ι���, ���ڿ��� ���� �˷��ش�
	cout << ary1 << endl;
	cout << sizeof(ary) << endl;
	cout << sizeof(ary1) << endl; // ���ڿ� ��ü ũ��, ÷���� 6ĭ �����ϸ� �׳� 6�� //��ü ������ ���ش�

	cout << strlen(ary1) << endl; // �ι��� �տ������� ũ��, //���ڿ� ���̸� ���ش�.
	cout << "========================" << endl;

	char str[] = "string";  // �̷��� ������ �ڵ����� �ι��ڰ� �ٴ´�
	cout << str << endl;
	cout << sizeof(str) << endl; // �׷��� �̰� 7�� ���´�
	cout << strlen(str) << endl; // �ι��� �տ������� ũ��
	str[0] = 'S';
	cout << str << endl;
	cout << "========================" << endl;

	const char* pstr = "String";
	cout << pstr << endl;
	cout << sizeof(pstr) << endl;
	cout << strlen(pstr) << endl;
	//pstr[0] = 's'  ���ڿ� �����ͷ� ����ϴ� ��� ������ �Ұ����ϴ�

	cout << "========================" << endl;

	string s = "string";  // heap����
	cout << s << endl;
	cout << sizeof(s) << endl;
	cout << s.size() << endl;
	return 0;
}