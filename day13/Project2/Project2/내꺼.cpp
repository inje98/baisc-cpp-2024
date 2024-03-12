#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include<string>
using namespace std;

int input_Count = 0;

int BookCount[100];
int BookCounting = 0;   // BookCount[BookCounting++] = input_Count   ==> 몇번 인덱스에서 책 객체가 만들어졌는지 알기위해

int PhoneCount[100];
int PhoneCounting = 0;

int ComputerCount[100];
int ComputerCounting = 0;

class Product
{
protected:
    char* id;
    int price;
    char* producer;

public:
    /*Product() :id(), price(), producer()
    {
       cout << "기본생성자 호출" << endl;
    }*/

    Product(const char* iid, int price, const char* iproducer) :id(id), price(price)
    {
        //cout << "product 생성자 호출" << endl;

        id = new char[strlen(iid) + 1];
        strcpy(id, iid);

        producer = new char[strlen(iproducer) + 1];
        strcpy(producer, iproducer);
    }

    ~Product()
    {
        //cout << "product 소멸자 호출" << endl;
        delete[] id;
        delete[] producer;
    }

    char* Get_id() const { return id; }
    int Get_price() const { return price; }
    char* Get_producer() const { return producer; }

    virtual char* Show_id()
    {
        return 0;
    }

    virtual int Show_price()
    {
        return 0;
    }

    virtual char* Show_producer()
    {
        return 0;
    }

    virtual bool compareName(const char* inputId)   // 3번 검색할때 쓸거
    {
        return 0;
    }


    //bool compareName(const char* inputId)
    //{
    //   return strcmp(id, inputId) == 0;  // 같다면 1이 반환, 다르면 0이 반환
    //}


};

class Book : public Product
{
private:
    char* ID;
    char* author;
    char* title;

public:
    Book(const char* id, int price, const char* iproducer, const char* iID, const char* iauthor, const char* ititle)
        :Product(id, price, iproducer)
    {
        //cout << "북 생성자" << endl;
        ID = new char[strlen(iID) + 1];
        strcpy(ID, iID);

        author = new char[strlen(iauthor) + 1];
        strcpy(author, iauthor);

        title = new char[strlen(ititle) + 1];
        strcpy(title, ititle);

        BookCount[BookCounting++] = input_Count;
        // for (int i = 0; i < BookCounting; i++)
        // {
        //      product[BookCount[i]].함수()
        // }
        // 2번 상품출력에서 이런식으로 쓸 생각

    }

    ~Book()
    {
        //cout << "북 소멸자" << endl;
        delete[] ID;
        delete[] author;
        delete[] title;
    }

    char* Show_id()
    {
        return id;
    }

    int Show_price()
    {
        return price;
    }

    char* Show_producer()
    {
        return producer;
    }

    bool compareName(const char* inputId)
    {
        return strcmp(title, inputId) == 0;  // 같다면 1이 반환, 다르면 0이 반환
    }

    char* Get_ID()
    {
        return ID;
    }

    char* Get_author()
    {
        return author;
    }

    char* Get_title()
    {
        return title;
    }
};

class Handphone : public Product
{
private:
    char* model;
    int RAM;

public:
    Handphone(const char* id, int price, const char* iproducer, const char* imodel, int RAM)
        : Product(id, price, iproducer), RAM(RAM)
    {
        //cout << "폰 생성자" << endl;
        model = new char[strlen(imodel) + 1];
        strcpy(model, imodel);

        PhoneCount[PhoneCounting++] = input_Count;
    }

    ~Handphone()
    {
        //cout << "폰 소멸자" << endl;
        delete[] model;
    }

    char* Show_id()
    {
        return id;
    }

    int Show_price()
    {
        return price;
    }

    char* Show_producer()
    {
        return producer;
    }

    bool compareName(const char* inputId)
    {
        return strcmp(model, inputId) == 0;  // 같다면 1이 반환, 다르면 0이 반환
    }

    char* Get_model()
    {
        return model;
    }

    int Get_RAM()
    {
        return RAM;
    }
};

class Computer : public Product
{
private:
    char* model;
    char* cpu;
    int RAM;

public:
    Computer(const char* id, int price, const char* iproducer, const char* imodel, const char* icpu, int RAM)
        :Product(id, price, iproducer), RAM(RAM)
    {
        //cout << "컴 생성자" << endl;
        model = new char[strlen(imodel) + 1];
        strcpy(model, imodel);

        cpu = new char[strlen(icpu) + 1];
        strcpy(cpu, icpu);

        ComputerCount[ComputerCounting++] = input_Count;

    }

    ~Computer()
    {
        //cout << "컴 소멸자" << endl;
        delete[] model;
        delete[] cpu;
    }

    char* Show_id()
    {
        return id;
    }

    int Show_price()
    {
        return price;
    }

    char* Show_producer()
    {
        return producer;
    }

    bool compareName(const char* inputId)
    {
        return strcmp(model, inputId) == 0;  // 같다면 1이 반환, 다르면 0이 반환
    }

    char* Get_model()
    {
        return model;
    }

    char* Get_cpu()
    {
        return cpu;
    }

    int Get_RAM()
    {
        return RAM;
    }
};

int main(void)
{
    Product* product[20];

    while (1)
    {
        int input;
        cout << "-------------상품관리 프로그램-----------------" << endl;
        cout << "1. 상품추가    2. 상품출력    3. 상품검색    0. 종료" << endl;
        cout << ">> ";
        cin >> input;
        cout << "\n" << endl;

        if (input == 0)
        {
            exit(1);
        }

        if (input == 1)
        {
            int Add_input;
            cout << "1. 책 추가\n"
                << "2. 핸드폰 추가\n"
                << "3. 컴퓨터 추가\n"
                << ">> ";
            cin >> Add_input;
            cout << "\n" << endl;

            if (Add_input == 1)  // 책 추가
            {
                char ID[30];
                int price;
                char producer[30];
                char ISBN[30];
                char author[30];
                char title[30];
                cout << "ID(char[30])       >> ";
                cin >> ID;
                cout << "price(int)         >> ";
                cin >> price;
                cout << "producer(char[30]) >> ";
                cin >> producer;
                cout << "ISBN(char[30])     >> ";
                cin >> ISBN;
                cout << "author(char[30])   >> ";
                cin >> author;
                cout << "title(char[30])    >> ";
                cin >> title;

                product[input_Count++] = new Book(ID, price, producer, ISBN, author, title);
                // cout << product[0]->Get_id() << endl;
            }

            if (Add_input == 2) // 핸드폰 추가
            {
                char ID[30];
                int price;
                char producer[30];
                char model[30];
                int RAM;
                cout << "ID(char[30])       >> ";
                cin >> ID;
                cout << "price(int)         >> ";
                cin >> price;
                cout << "producer(char[30]) >> ";
                cin >> producer;
                cout << "model(char[30])    >> ";
                cin >> model;
                cout << "RAM(int)           >> ";
                cin >> RAM;

                product[input_Count++] = new Handphone(ID, price, producer, model, RAM);
            }

            if (Add_input == 3) // 컴퓨터 추가
            {
                char ID[30];
                int price;
                char producer[30];
                char model[30];
                char cpu[30];
                int RAM;
                cout << "ID(char[30])       >> ";
                cin >> ID;
                cout << "price(int)         >> ";
                cin >> price;
                cout << "producer(char[30]) >> ";
                cin >> producer;
                cout << "model(char[30])    >> ";
                cin >> model;
                cout << "cpu(char[30])      >> ";
                cin >> cpu;
                cout << "RAM(int)           >> ";
                cin >> RAM;

                product[input_Count++] = new Computer(ID, price, producer, model, cpu, RAM);
            }

        }

        if (input == 2)
        {
            int print_input;
            cout << "1. 책 출력\n"
                << "2. 핸드폰 출력\n"
                << "3. 컴퓨터 출력\n"
                << ">> ";
            cin >> print_input;
            cout << "\n" << endl;

            if (print_input == 1)
            {
                cout << "================= 입력된 책 리스트 ==================\n" << endl;
                for (int i = 0; i < BookCounting; i++)
                {
                    cout << "책 id: " << product[BookCount[i]]->Show_id() << endl;
                    cout << "책 가격: " << product[BookCount[i]]->Show_price() << endl;
                    cout << "책 출판사: " << product[BookCount[i]]->Show_producer() << endl;    // BookCount[i] 요 값이 몇번 인덱스가 북 객체를 가리키고 있나 그거임
                    cout << "책 ID: " << ((Book*)product[BookCount[i]])->Get_ID() << endl;
                    cout << "책 작가: " << ((Book*)product[BookCount[i]])->Get_author() << endl;
                    cout << "책 제목: " << ((Book*)product[BookCount[i]])->Get_title() << endl << endl;
                }
                cout << "====================================================\n" << endl;
            }

            if (print_input == 2)
            {
                cout << "================= 입력된 핸드폰 리스트 ==================\n" << endl;

                for (int i = 0; i < PhoneCounting; i++)
                {
                    cout << "핸드폰 ID: " << product[PhoneCount[i]]->Show_id() << endl;
                    cout << "핸드폰 가격: " << product[PhoneCount[i]]->Show_price() << endl;
                    cout << "핸드폰 제조사: " << product[PhoneCount[i]]->Show_producer() << endl;
                    cout << "핸드폰 모델: " << ((Handphone*)product[PhoneCount[i]])->Get_model() << endl;
                    cout << "핸드폰 RAM: " << ((Handphone*)product[PhoneCount[i]])->Get_RAM() << endl << endl;
                }
                cout << "======================================================\n" << endl;

            }

            if (print_input == 3)
            {
                cout << "================= 입력된 컴퓨터 리스트 ==================\n" << endl;

                for (int i = 0; i < ComputerCounting; i++)
                {
                    cout << "컴퓨터 ID: " << product[ComputerCount[i]]->Show_id() << endl;
                    cout << "컴퓨터 가격: " << product[ComputerCount[i]]->Show_price() << endl;
                    cout << "컴퓨터 제조사: " << product[ComputerCount[i]]->Show_producer() << endl;
                    cout << "컴퓨터 모델: " << ((Computer*)product[ComputerCount[i]])->Get_model() << endl;
                    cout << "컴퓨터 cpu: " << ((Computer*)product[ComputerCount[i]])->Get_cpu() << endl;
                    cout << "컴퓨터 RAM: " << ((Computer*)product[ComputerCount[i]])->Get_RAM() << endl << endl;
                }
                cout << "======================================================\n" << endl;
            }

        }

        if (input == 3)
        {
            int serch_input;

            cout << "1. 책 검색\n"
                << "2. 핸드폰 검색\n"
                << "3. 컴퓨터 검색\n"
                << ">> ";
            cin >> serch_input;
            cout << "\n" << endl;

            if (serch_input == 1)    // 책 검색
            {
                char findTitle[30];
                cout << "검색할 책 제목을 입력 >> ";
                cin >> findTitle;
                bool find = false;
                for (int i = 0; i < BookCounting; i++)
                {
                    if (product[BookCount[i]]->compareName(findTitle) == 1)  //제목(title)으로 비교
                    {
                        cout << "\n======== " << ((Book*)product[BookCount[i]])->Get_title() << " 책의 정보 ==========\n" << endl;

                        cout << "id: " << product[BookCount[i]]->Show_id() << endl;
                        cout << "가격: " << product[BookCount[i]]->Show_price() << endl;
                        cout << "출판사: " << product[BookCount[i]]->Show_producer() << endl;
                        cout << "ISBN: " << ((Book*)product[BookCount[i]])->Get_ID() << endl;
                        cout << "작가: " << ((Book*)product[BookCount[i]])->Get_author() << endl;
                        cout << "제목: " << ((Book*)product[BookCount[i]])->Get_title() << endl;

                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (find == false)
                {
                    cout << "그런 책 없음!" << endl;
                }
            }

            if (serch_input == 2)  // 폰 검색
            {
                char findModel[30];
                cout << "검색할 핸드폰 모델명을 입력 >> ";
                cin >> findModel;
                bool find = false;
                for (int i = 0; i < PhoneCounting; i++)
                {
                    if (product[PhoneCount[i]]->compareName(findModel) == 1)  // 모델(model)으로 비교
                    {
                        cout << "\n======== " << ((Handphone*)product[PhoneCount[i]])->Get_model() << " 핸드폰의 정보 ==========\n" << endl;
                        cout << "id: " << product[PhoneCount[i]]->Show_id();
                        cout << "가격: " << product[PhoneCount[i]]->Show_price() << endl;
                        cout << "제조사: " << product[PhoneCount[i]]->Show_producer() << endl;
                        cout << "모델: " << ((Handphone*)product[PhoneCount[i]])->Get_model() << endl;
                        cout << "RAM: " << ((Handphone*)product[PhoneCount[i]])->Get_RAM() << endl;
                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (find == false)
                {
                    cout << "그런 핸드폰 없음!" << endl;
                }
            }

            if (serch_input == 3) // 컴퓨터 검색
            {
                char findModel[30];
                cout << "검색할 컴퓨터 모델명을 입력 >> ";
                cin >> findModel;
                bool find = false;
                for (int i = 0; i < ComputerCounting; i++)
                {
                    if (product[ComputerCount[i]]->compareName(findModel) == 1)
                    {
                        cout << "\n======== " << ((Computer*)product[ComputerCount[i]])->Get_model() << " 컴퓨터의 정보 ==========\n" << endl;
                        cout << "id: " << product[ComputerCount[i]]->Show_id() << endl;
                        cout << "가격: " << product[ComputerCount[i]]->Show_price() << endl;
                        cout << "제조사: " << product[ComputerCount[i]]->Show_producer() << endl;
                        cout << "모델: " << ((Computer*)product[ComputerCount[i]])->Get_model() << endl;
                        cout << "컴퓨터 cpu: " << ((Computer*)product[ComputerCount[i]])->Get_cpu() << endl;
                        cout << "컴퓨터 RAM: " << ((Computer*)product[ComputerCount[i]])->Get_RAM() << endl;
                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (find == false)
                {
                    cout << "그런 컴퓨터 없음!\n" << endl;
                }

            }
        }


    }
    for (int i = 0; i < input_Count; i++)
    {
        delete product[i];
    }

    return 0;
}