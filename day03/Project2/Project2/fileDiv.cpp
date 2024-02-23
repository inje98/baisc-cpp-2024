// #include<iostream>
#include"fileDiv.h"


//class AClass {
//private:
//	int num;
//
//public:
//					   // 접근제어지시자
//	AClass(int anum)   // 생성자 : 주로 초기화 담당
//	{
//		num = anum;
//	}
//	void Ainfo() 
//	{
//		std::cout << "A::num : " << num << std::endl;
//	}
//
//};



int main() {
	AClass a(10);
	a.Ainfo();

	return 0;
}