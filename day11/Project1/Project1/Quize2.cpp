#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
//5명의 이름과, 국영수 3과목 점수를 입력받아 학생별 총점과 평균, 그리고 과목별 총점과 평균을 구하시오
class Grade
{
    static int total_Student_num;

    char* name;  // 동적할당
    int kr;
    int math;
    int english;

public:
    Grade() : name(nullptr), kr(0), math(0), english(0)
    {
        //cout << "기본생성자" << endl;
    }

    Grade(const char* iname, int kr, int math, int english) : kr(kr), math(math), english(english)
    {
        //cout << "생성자" << endl;

        int len = strlen(iname) + 1;
        name = new char[len];
        strcpy(name, iname);

        total_Student_num++;

    }
    Grade& operator=(const Grade& ref)
    {
        //cout << "대입연산자" << endl;
        int len = strlen(ref.name) + 1;
        name = new char[len];
        strcpy(name, ref.name);

        kr = ref.kr;
        math = ref.math;
        english = ref.english;


        return *this;
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

    ~Grade()
    {
        //cout << "소멸자" << endl;
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
        cout << "1. 학생 성적 입력\n"
            << "2. 학생 성적 조회\n"
            << "3. 과목별 성적 조회\n"
            << "4. 종료\n"
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


            if (Grade::Total_Student_num() < 5)
            {
                student[Grade::Total_Student_num()] = Grade(StudentName, kr, math, english);
                continue;
            }

            else if (Grade::Total_Student_num() >= 5)
            {
                cout << "더 이상 넣을 수 없음!\n" << endl;
                continue;
            }
        }

        if (input == 2)
        {
            char* name = nullptr;
            cout << "조회할 학생 이름을 입력하세요 >> ";
            cin >> name;

            for (int i = 0; i < Grade::Total_Student_num(); i++)
            {
                if (strcmp(name, student[i].GetName_char()) == 0) // 아마 이게 주소를 가리켜서, 문자열 비교가 아니라 주소값이 그냥 달라서 못들어가는듯
                {
                    student[i].GetName();
                    cout << "의 총점: " << student[i].tatalScore() << endl;
                    student[i].GetName();
                    cout << "의 평균: " << student[i].everage() << endl;
                }
                else if (strcmp(name, student[i].GetName_char()) != 0)
                {
                    cout << "해당 이름이 없습니다" << endl; // 근데 여기로도 못들어가는 이유는 뭐임
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

            cout << "국어 총점: " << kr_sum << endl;
            cout << "국어 평균: " << kr_sum / kr_count << endl;


            int math_count = 0;
            int math_sum = 0;
            for (int i = 0; i < Grade::Total_Student_num(); i++)
            {
                math_sum += student[i].Get_math();
                math_count++;
            }

            cout << "수학 총점: " << math_sum << endl;
            cout << "수학 평균: " << math_sum / math_count << endl;

            int eng_count = 0;
            int eng_sum = 0;
            for (int i = 0; i < Grade::Total_Student_num(); i++)
            {
                eng_sum += student[i].Get_english();
                eng_count++;
            }

            cout << "영어 총점: " << eng_sum << endl;
            cout << "영어 평균: " << eng_sum / eng_count << endl;
        }

        if (input == 4)
        {
            exit(0);
        }








    }
    return 0;
}