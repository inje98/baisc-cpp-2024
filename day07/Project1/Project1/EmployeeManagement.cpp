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
        cout << "이름: " << name << endl;
        cout << "급여: " << GetPay() << endl << endl;
    }
};

class Employeehandler
{
private:
    PermanentWorker* empList[50]; // 정규직 객체의 주소 배열(50칸)
    int empNum;

public:
    Employeehandler() : empNum(0)
    {}

    void AddEmployee(PermanentWorker* emp)  // 정규직 객체의 주소를 받아// 힙영역에 임시객체 만들고 그 주소를 받는거임!
    {
        empList[empNum++] = emp;// 필드에 있는 그 50칸 배열에 입력받은 객체의 주소를 차곡차곡 넣어
    }                              // 힙영역에 임시객체가 있고 그 힙영역의 주소를 가리키는 empList인거지
                                    // empList는 각각 다 객체가 아닌가싶음
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
        {
            empList[i]->ShowSalaryInfo();  // 넣은거 전부 다 보여줘
        }                                  // 객체의 '주소'니까 (->) 이거 쓰는거지
    }

    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
        {
            sum += empList[i]->GetPay();
        }
        cout << "총 급여 합계: " << sum << endl;
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
