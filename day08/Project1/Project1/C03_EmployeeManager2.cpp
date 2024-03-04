#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;

class Employee  // �̸���
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

class PerManentWorker : public Employee  // ���� �߰�
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
	int workTime; // �� �޿� ���� �ð��� �հ�
	int payPerHour; // �ð��� �޿�

public:
	TemporaryWorker(const char*name, int pay): Employee(name), workTime(0), payPerHour(pay)
	{}

	void AddWorkTime(int time) // ���� �ð��� �߰�
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
	int salesResult; // �� �Ǹ� ����
	double bonusRatio; // �󿩱� ����

public:
	SalesWorker(const char*name, int money, double ratio) : PerManentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{}
	
	void AddSalesResult(int value)  // value ��ŭ ������
	{
		salesResult += value; // �Ǹ� ���� �߰�
	}

	int GetPay() const
	{
		return PerManentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}	// �������̵��� ����Լ�(GetPay())�� �ڽİ��� ����ȴ�. �׷��� �θ��Լ�( GetPay() )�� �ҷ������� ������ �Ѵ�

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

	void AddEmployee(Employee* emp) // Employee* emp �̰� ���� �����Ҵ� �ϰڴµ�? �ǽ��غ��� ��������
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

	//������ ���
	handler.AddEmployee(new PerManentWorker("Kim", 1000));
	handler.AddEmployee(new PerManentWorker("Lee", 1500));


	// �ӽ��� ���
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5); // 5�ð� ���� ��� ���
	handler.AddEmployee(alba);

	// ������ ���
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000); // �������� 7000
	handler.AddEmployee(seller);

	//�̹��޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹��޿� �����ؾ��� �޿��� ����
	handler.ShowTotalSalary();

	return 0;

}