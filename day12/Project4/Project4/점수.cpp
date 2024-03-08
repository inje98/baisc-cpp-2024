#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
//5명의 이름과, 국영수 3과목 점수를 입력받아 학생별 총점과 평균, 그리고 과목별 총점과 평균을 구하시오
class Grade
{
    char* name;  // 동적할당
    int kr;
    int math;
    int english;

public:
    Grade() : name(), kr(), math(), english()
    {
        //cout << "기본생성자" << endl;
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
        return strcmp(name, inputName) == 0;  // 같다면 1이 반환, 다르면 0이 반환
    }

    ~Grade()
    {
        //cout << "소멸자" << endl;
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
        cout << "1. 학생 성적 입력\n"
            << "2. 입력된 학생 조회\n"
            << "3. 학생 성적 조회\n"
            << "4. 과목별 성적 조회\n"
            << "5. 종료\n"
            << ">> ";
        cin >> input;
        cout << "\n\n" << endl;


        char StudentName[50];
        if (input == 1)
        {
            int kr, math, english;
            cout << "학생 이름: ";
            cin >> StudentName;
            cout << "국어 점수: ";
            cin >> kr;
            cout << "수학 점수: ";
            cin >> math;
            cout << "영어 점수: ";
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
                cout << "더 이상 넣을 수 없음!\n" << endl;
                continue;
            }
        }
        if (input == 2)  // 그냥 나가짐
        {
            for (int i = 0; i < student_Count; i++)
            {
                //cout << "이준용" << endl;
                student[i].GetName(); // 5개 다채워야 됨
                cout << endl;
            }
            continue;
        }

        if (input == 3)
        {
            char name[50];
            cout << "조회할 학생 이름을 입력하세요 >> ";
            cin >> name;

            bool find = false;
            for (int i = 0; i < student_Count; i++)
            {

                if (student[i].compareName(name) == 1)
                {
                    cout << "\n===========" << student[i].GetName_char() << "의 성적 =============\n" << endl;

                    cout << "총점: " << student[i].tatalScore() << endl;
                    cout << "평균: " << student[i].everage() << endl;
                    cout << "\n==================================================================\n" << endl;
                    find = true;
                    break;
                }
            }
            if (find == false)
            {
                cout << "학생 없음!" << endl;
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
            cout << "\n\n============= 과목별 총점/평균 ==================\n\n";

            cout << "국어 총점: " << kr_sum << endl;
            cout << "국어 평균: " << kr_sum / student_Count << endl;

            cout << "\n수학 총점: " << math_sum << endl;
            cout << "수학 평균: " << math_sum / student_Count << endl;

            cout << "\n영어 총점: " << eng_sum << endl;
            cout << "영어 평균: " << eng_sum / student_Count << endl;

            cout << "\n=================================================\n\n";


        }

        if (input == 5)
        {
            exit(0);
        }
    }
    return 0;
}