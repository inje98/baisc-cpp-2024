#include<iostream>
#include<cstring>
using namespace std;


class Person {
private:
	char* name;   // 필드에서 이런 변수 나오면 아, 동적할당 할라는구나 예상 한번 해보는것도 괜찮을듯?
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}


	Person(const Person& other) :age(other.age)
	{
		name = new char[strlen(other.name) + 1];  // 이렇게 하면 새로운 힙영역 할당되니까 
		strcpy(name, other.name);				  // 그치 쟤따로 얘따로니까 객체1 없어져도 이동우 남아있겠지
		cout << "복사생성자 호출" << endl;
	}

	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}