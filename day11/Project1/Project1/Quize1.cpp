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
    Grade() : name(nullptr), kr(0), math(0), english(0)
    {
        cout << "기본생성자" << endl;
    }

    Grade(const char* iname, int kr, int math, int english) : kr(kr), math(math), english(english)
    {
        cout << "생성자" << endl;

        int len = strlen(iname) + 1;
        name = new char[len];
        strcpy(name, iname);

    }
    Grade& operator=(const Grade& ref)
    {
        cout << "대입연산자" << endl;
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
        cout << "소멸자" << endl;
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

        cout << "학생 이름: ";
        cin >> name;


        int kr, math, english;

        cout << "국어 점수: ";
        cin >> kr;

        cout << "수학 점수: ";
        cin >> math;

        cout << "영어 점수: ";
        cin >> english;

        student[i] = Grade(name, kr, math, english);
    }




    for (int i = 0; i < 2; i++)
    {
        student[i].GetName();
        cout << " 의 총점: " << student[i].tatalScore() << endl;
        student[i].GetName();
        cout << " 의 평균: " << student[i].everage() << endl << endl;;
    }

    int kr_count = 0;
    int kr_sum = 0;
    for (int i = 0; i < 2; i++)
    {
        kr_sum += student[i].Get_kr();
        kr_count++;
    }

    cout << "국어 총점: " << kr_sum << endl;
    cout << "국어 평균: " << kr_sum / kr_count << endl;


    int math_count = 0;
    int math_sum = 0;
    for (int i = 0; i < 2; i++)
    {
        math_sum += student[i].Get_math();
        math_count++;
    }

    cout << "수학 총점: " << math_sum << endl;
    cout << "수학 평균: " << math_sum / math_count << endl;

    int eng_count = 0;
    int eng_sum = 0;
    for (int i = 0; i < 2; i++)
    {
        eng_sum += student[i].Get_english();
        eng_count++;
    }

    cout << "영어 총점: " << eng_sum << endl;
    cout << "영어 평균: " << eng_sum / eng_count << endl;





    /*for (int i = 0; i < 2; i++)
    {
       student[i].GetName();
    }*/


    return 0;
}