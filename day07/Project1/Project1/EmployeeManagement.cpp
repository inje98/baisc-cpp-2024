#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

class PermanentWorker
{
private:
    char name[100];
    int salary;

public:
    PermanentWorker(const char* name, int money) : salary(money)
    {
        strcpy(this->name, name);
    }

    int GetPay() const
    {
        return salary;
    }

    void ShowSalaryInfo() const
    {
        cout << "�̸�: " << name << endl;
        cout << "�޿�: " << GetPay() << endl << endl;
    }
};

class Employeehandler
{
private:
    PermanentWorker* empList[50]; // ������ ��ü�� �ּ� �迭(50ĭ)
    int empNum;

public:
    Employeehandler() : empNum(0)
    {}

    void AddEmployee(PermanentWorker* emp)  // ������ ��ü�� �ּҸ� �޾�// �������� �ӽð�ü ����� �� �ּҸ� �޴°���!
    {
        empList[empNum++] = emp;// �ʵ忡 �ִ� �� 50ĭ �迭�� �Է¹��� ��ü�� �ּҸ� �������� �־�
    }                              // �������� �ӽð�ü�� �ְ� �� �������� �ּҸ� ����Ű�� empList�ΰ���
                                    // empList�� ���� �� ��ü�� �ƴѰ�����
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
        {
            empList[i]->ShowSalaryInfo();  // ������ ���� �� ������
        }                                  // ��ü�� '�ּ�'�ϱ� (->) �̰� ���°���
    }

    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
        {
            sum += empList[i]->GetPay();
        }
        cout << "�� �޿� �հ�: " << sum << endl;
    }

    ~Employeehandler()
    {
        for (int i = 0; i < empNum; i++)
        {
            delete empList[i];
        }
    }
};

int main(void)
{
    Employeehandler handler;

    handler.AddEmployee(new PermanentWorker("Kim", 1000));
    handler.AddEmployee(new PermanentWorker("Lee", 1500));
    handler.AddEmployee(new PermanentWorker("Jun", 2000));

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();

    return 0;
}
