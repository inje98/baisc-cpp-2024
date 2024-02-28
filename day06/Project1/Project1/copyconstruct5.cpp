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

//New Object : 000000447C2FF4C4 : 객체 obj 주소
//New Copy obj : 000000447C2FF5C4 : obj를 복사한 객체 ob 주소
//Parm ADR : 000000447C2FF5C4 : ob 주소
//New Copy obj : 000000447C2FF604 : return ob를 복사한 임시객체의 주소
//Destroy obj : 000000447C2FF5C4 : 함수를 빠져나왔으니 안에서 ob 사망
//Destroy obj : 000000447C2FF604 : 임시객체 아무한테 전달 못하고 사망
//
//New Copy obj : 000000447C2FF624 : obj를 복사한 객체 ob 주소
//Parm ADR : 000000447C2FF624 : ob주소
//New Copy obj : 000000447C2FF4E4 : return ob를 복사한 임시객체의 주소임 = > 이 주소가 tempRef로 가는거임
//Destroy obj : 000000447C2FF624 : 함수를 나왔으니 안에서 ob 사망
//Return Obj 000000447C2FF4E4 : 임시객체주소였던 tempRef 주소
//Destroy obj : 000000447C2FF4E4 : 메인함수 나가면서 객체 tempRef 사망
//Destroy obj : 000000447C2FF4C4 : 메인함수 나가면서 객체 obj 사망