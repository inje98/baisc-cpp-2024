#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
//5���� �̸���, ������ 3���� ������ �Է¹޾� �л��� ������ ���, �׸��� ���� ������ ����� ���Ͻÿ�
class Grade
{
    static int total_Student_num;

    string name;  // �����Ҵ�
    int kr;
    int math;
    int english;

public:
    Grade() : name(nullptr), kr(0), math(0), english(0)
    {
        //cout << "�⺻������" << endl;
    }

    Grade(string iname, int kr, int math, int english) : kr(kr), math(math), english(english)
    {
        //cout << "������" << endl;

        int len = iname.size() + 1;
        name = new char[len];
        name = iname;

        total_Student_num++;

    }
    Grade& operator=(const Grade& ref)
    {
        //cout << "���Կ�����" << endl;
        int len = ref.name.size() + 1;
        name = new char[len];
        name = ref.name;

        kr = ref.kr;
        math = ref.math;
        english = ref.english;


        return *this;
    }

    string GetName_char()
    {
        return name;
    }

    void GetName()
    {
        cout << name;
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
        //cout << "�Ҹ���" << endl;
        delete[] name;

    }

    static int Total_Student_num()
    {
        return Grade::total_Student_num;
    }


};

int Grade::total_Student_num = 0;


int main()
{
    Grade student[5];

    while (1)
    {
        int input;
        cout << "1. �л� ���� �Է�\n"
            << "2. �л� ���� ��ȸ\n"
            << "3. ���� ���� ��ȸ\n"
            << "4. ����\n"
            << ">> ";
        cin >> input;
        cout << "\n\n" << endl;


        char StudentName[50];
        if (input == 1)
        {
            int kr, math, english;
            cout << "�л� �̸�: ";
            cin >> StudentName;
            cout << "���� ����: ";
            cin >> kr;
            cout << "���� ����: ";
            cin >> math;
            cout << "���� ����: ";
            cin >> english;


            if (Grade::Total_Student_num() < 5)
            {
                student[Grade::Total_Student_num()] = Grade(StudentName, kr, math, english);
                continue;
            }

            else if (Grade::Total_Student_num() >= 5)
            {
                cout << "�� �̻� ���� �� ����!\n" << endl;
                continue;
            }
        }

        if (input == 2)
        {
            string iname;
            cout << "��ȸ�� �л� �̸��� �Է��ϼ��� >> ";
            cin >> iname;

            for (int i = 0; i < Grade::Total_Student_num(); i++)
            {
                if (iname == student[i].GetName_char()) 
                {
                    student[i].GetName();
                    cout << "�� ����: " << student[i].tatalScore() << endl;
                    student[i].GetName();
                    cout << "�� ���: " << student[i].everage() << endl;
                }
                else
                {
                    cout << "�ش� �̸��� �����ϴ�" << endl; // �ٵ� ����ε� ������ ������ ����
                    break;
                }
            }
        }

        if (input == 3)
        {
            int kr_count = 0;
            int kr_sum = 0;
            for (int i = 0; i < Grade::Total_Student_num(); i++)
            {
                kr_sum += student[i].Get_kr();
                kr_count++;
            }

            cout << "���� ����: " << kr_sum << endl;
            cout << "���� ���: " << kr_sum / kr_count << endl;


            int math_count = 0;
            int math_sum = 0;
            for (int i = 0; i < Grade::Total_Student_num(); i++)
            {
                math_sum += student[i].Get_math();
                math_count++;
            }

            cout << "���� ����: " << math_sum << endl;
            cout << "���� ���: " << math_sum / math_count << endl;

            int eng_count = 0;
            int eng_sum = 0;
            for (int i = 0; i < Grade::Total_Student_num(); i++)
            {
                eng_sum += student[i].Get_english();
                eng_count++;
            }

            cout << "���� ����: " << eng_sum << endl;
            cout << "���� ���: " << eng_sum / eng_count << endl;
        }

        if (input == 4)
        {
            exit(0);
        }








    }
    return 0;
}