#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
//5���� �̸���, ������ 3���� ������ �Է¹޾� �л��� ������ ���, �׸��� ���� ������ ����� ���Ͻÿ�
class Grade
{
    char* name;  // �����Ҵ�
    int kr;
    int math;
    int english;

public:
    Grade() : name(nullptr), kr(0), math(0), english(0)
    {
        cout << "�⺻������" << endl;
    }

    Grade(const char* iname, int kr, int math, int english) : kr(kr), math(math), english(english)
    {
        cout << "������" << endl;

        int len = strlen(iname) + 1;
        name = new char[len];
        strcpy(name, iname);

    }
    Grade& operator=(const Grade& ref)
    {
        cout << "���Կ�����" << endl;
        int len = strlen(ref.name) + 1;
        name = new char[len];
        strcpy(name, ref.name);

        kr = ref.kr;
        math = ref.math;
        english = ref.english;

        return *this;
    }

    int Get_kr()
    {
        return kr;
    }

    int Get_math()
    {
        return math;
    }

    int Get_english()
    {
        return english;
    }


    float everage()
    {

        return ((float)kr + (float)math + (float)english) / 3;
    }

    int tatalScore()
    {
        return kr + math + english;
    }

    ~Grade()
    {
        cout << "�Ҹ���" << endl;
        delete[] name;

    }

    void GetName()
    {
        cout << name;
    }


};

int main()
{
    Grade student[5];


    for (int i = 0; i < 2; i++)
    {
        char name[50];

        cout << "�л� �̸�: ";
        cin >> name;


        int kr, math, english;

        cout << "���� ����: ";
        cin >> kr;

        cout << "���� ����: ";
        cin >> math;

        cout << "���� ����: ";
        cin >> english;

        student[i] = Grade(name, kr, math, english);
    }




    for (int i = 0; i < 2; i++)
    {
        student[i].GetName();
        cout << " �� ����: " << student[i].tatalScore() << endl;
        student[i].GetName();
        cout << " �� ���: " << student[i].everage() << endl << endl;;
    }

    int kr_count = 0;
    int kr_sum = 0;
    for (int i = 0; i < 2; i++)
    {
        kr_sum += student[i].Get_kr();
        kr_count++;
    }

    cout << "���� ����: " << kr_sum << endl;
    cout << "���� ���: " << kr_sum / kr_count << endl;


    int math_count = 0;
    int math_sum = 0;
    for (int i = 0; i < 2; i++)
    {
        math_sum += student[i].Get_math();
        math_count++;
    }

    cout << "���� ����: " << math_sum << endl;
    cout << "���� ���: " << math_sum / math_count << endl;

    int eng_count = 0;
    int eng_sum = 0;
    for (int i = 0; i < 2; i++)
    {
        eng_sum += student[i].Get_english();
        eng_count++;
    }

    cout << "���� ����: " << eng_sum << endl;
    cout << "���� ���: " << eng_sum / eng_count << endl;





    /*for (int i = 0; i < 2; i++)
    {
       student[i].GetName();
    }*/


    return 0;
}