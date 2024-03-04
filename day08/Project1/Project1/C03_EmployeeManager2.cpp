#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;

class Employee  // 이름만
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const
	{
		return 0;
	}

	virtual void ShowSalaryInfo() const
	{}
};

class PerManentWorker : public Employee  // 월급 추가
{
private:
	int salary;
public:
	PerManentWorker(const char* name, int money) : Employee(name), salary(money) {}

	int GetPay() const
	{
		return salary;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime; // 이 달에 일한 시간의 합계
	int payPerHour; // 시간당 급여

public:
	TemporaryWorker(const char*name, int pay): Employee(name), workTime(0), payPerHour(pay)
	{}

	void AddWorkTime(int time) // 일한 시간의 추가
	{
		workTime += time;
	}

	int GetPay() const
	{
		return workTime * payPerHour;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PerManentWorker
{
private:
	int salesResult; // 월 판매 실적
	double bonusRatio; // 상여금 비율

public:
	SalesWorker(const char*name, int money, double ratio) : PerManentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{}
	
	void AddSalesResult(int value)  // value 만큼 벌었다
	{
		salesResult += value; // 판매 실적 추가
	}

	int GetPay() const
	{
		return PerManentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}	// 오버라이딩된 멤버함수(GetPay())는 자식것이 실행된다. 그래서 부모함수( GetPay() )를 불러오려면 저렇게 한다

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empList(), empNum(0) {}

	void AddEmployee(Employee* emp) // Employee* emp 이거 보면 동적할당 하겠는데? 의심해봐도 괜찮을듯
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const
	{
		
		for(int i = 0; i < empNum; i++)
		{
		empList[i]->ShowSalaryInfo();
		}
	}

	void ShowTotalSalary() const
	{
		int sum = 0;
		
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		 }
		cout << "salaty sum: " << sum << endl;
	}

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
		{
			delete empList[i];
		}
	}
};

int main(void)
{
	EmployeeHandler handler;

	//정규직 등록
	handler.AddEmployee(new PerManentWorker("Kim", 1000));
	handler.AddEmployee(new PerManentWorker("Lee", 1500));


	// 임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5); // 5시간 일한 결과 등록
	handler.AddEmployee(alba);

	// 영업직 등록
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(seller);

	//이번달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번달에 지불해야할 급여의 총합
	handler.ShowTotalSalary();

	return 0;

}