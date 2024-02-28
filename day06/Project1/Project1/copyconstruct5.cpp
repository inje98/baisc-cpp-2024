#include<iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n): num(n)
	{
		cout << "New Object: " << this << endl;
	}

	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "New Copy obj: " << this << endl;
	}

	~SoSimple()
	{
		cout << "Destroy obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "Parm ADR: " << &ob << endl;
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);
	cout << "Return Obj " << &tempRef << endl;
	return 0;
}

//New Object : 000000447C2FF4C4 : ��ü obj �ּ�
//New Copy obj : 000000447C2FF5C4 : obj�� ������ ��ü ob �ּ�
//Parm ADR : 000000447C2FF5C4 : ob �ּ�
//New Copy obj : 000000447C2FF604 : return ob�� ������ �ӽð�ü�� �ּ�
//Destroy obj : 000000447C2FF5C4 : �Լ��� ������������ �ȿ��� ob ���
//Destroy obj : 000000447C2FF604 : �ӽð�ü �ƹ����� ���� ���ϰ� ���
//
//New Copy obj : 000000447C2FF624 : obj�� ������ ��ü ob �ּ�
//Parm ADR : 000000447C2FF624 : ob�ּ�
//New Copy obj : 000000447C2FF4E4 : return ob�� ������ �ӽð�ü�� �ּ��� = > �� �ּҰ� tempRef�� ���°���
//Destroy obj : 000000447C2FF624 : �Լ��� �������� �ȿ��� ob ���
//Return Obj 000000447C2FF4E4 : �ӽð�ü�ּҿ��� tempRef �ּ�
//Destroy obj : 000000447C2FF4E4 : �����Լ� �����鼭 ��ü tempRef ���
//Destroy obj : 000000447C2FF4C4 : �����Լ� �����鼭 ��ü obj ���