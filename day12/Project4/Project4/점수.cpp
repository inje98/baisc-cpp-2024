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
    Grade() : name(), kr(), math(), english()
    {
        //cout << "�⺻������" << endl;
    }

    void GetGrade(const char* iname, int kr, int math, int english)
    {
        int len = strlen(iname) + 1;
        name = new char[len];
        strcpy(name, iname);

        this->kr = kr;
        this->math = math;
        this->english = english;
    }

    char* GetName_char()
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

    bool compareName(const char* inputName)
    {
        return strcmp(name, inputName) == 0;  // ���ٸ� 1�� ��ȯ, �ٸ��� 0�� ��ȯ
    }

    ~Grade()
    {
        //cout << "�Ҹ���" << endl;
        delete[] name;

    }
};

int main()
{
    Grade student[5];


    int student_Count = 0;
    int kr_sum = 0;
    int math_sum = 0;
    int eng_sum = 0;

    while (1)
    {
        int input;
        cout << "1. �л� ���� �Է�\n"
            << "2. �Էµ� �л� ��ȸ\n"
            << "3. �л� ���� ��ȸ\n"
            << "4. ���� ���� ��ȸ\n"
            << "5. ����\n"
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

            if (student_Count < 5)
            {
                student[student_Count].GetGrade(StudentName, kr, math, english);
                student_Count++;
                cout << "\n" << endl;
                continue;
            }

            else if (student_Count >= 5)
            {
                cout << "�� �̻� ���� �� ����!\n" << endl;
                continue;
            }
        }
        if (input == 2)  // �׳� ������
        {
            for (int i = 0; i < student_Count; i++)
            {
                //cout << "���ؿ�" << endl;
                student[i].GetName(); // 5�� ��ä���� ��
                cout << endl;
            }
            continue;
        }

        if (input == 3)
        {
            char name[50];
            cout << "��ȸ�� �л� �̸��� �Է��ϼ��� >> ";
            cin >> name;

            bool find = false;
            for (int i = 0; i < student_Count; i++)
            {

                if (student[i].compareName(name) == 1)
                {
                    cout << "\n===========" << student[i].GetName_char() << "�� ���� =============\n" << endl;

                    cout << "����: " << student[i].tatalScore() << endl;
                    cout << "���: " << student[i].everage() << endl;
                    cout << "\n==================================================================\n" << endl;
                    find = true;
                    break;
                }
            }
            if (find == false)
            {
                cout << "�л� ����!" << endl;
            }
        }

        if (input == 4)
        {

            for (int i = 0; i < student_Count; i++)
            {
                kr_sum += student[i].Get_kr();
                math_sum += student[i].Get_math();
                eng_sum += student[i].Get_english();

            }
            cout << "\n\n============= ���� ����/��� ==================\n\n";

            cout << "���� ����: " << kr_sum << endl;
            cout << "���� ���: " << kr_sum / student_Count << endl;

            cout << "\n���� ����: " << math_sum << endl;
            cout << "���� ���: " << math_sum / student_Count << endl;

            cout << "\n���� ����: " << eng_sum << endl;
            cout << "���� ���: " << eng_sum / student_Count << endl;

            cout << "\n=================================================\n\n";


        }

        if (input == 5)
        {
            exit(0);
        }
    }
    return 0;
}