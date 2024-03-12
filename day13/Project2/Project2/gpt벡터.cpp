#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string>
#include<vector>  // 헤더 추가: 동적 배열 사용을 위해 vector 헤더 추가
using namespace std;

int input_Count = 0;

vector<int> BookCount;  // 배열에서 vector로 변경
vector<int> PhoneCount;
vector<int> ComputerCount;

class Product {
protected:
    char* id;
    int price;
    char* producer;

public:
    Product(const char* iid, int price, const char* iproducer) : id(nullptr), price(price), producer(nullptr) {
        id = new char[strlen(iid) + 1];
        strcpy(id, iid);

        producer = new char[strlen(iproducer) + 1];
        strcpy(producer, iproducer);
    }

    virtual ~Product() {  // 가상 소멸자 추가
        delete[] id;
        delete[] producer;
    }

    char* Get_id() const { return id; }
    int Get_price() const { return price; }
    char* Get_producer() const { return producer; }

    virtual char* Show_id() const { return nullptr; }
    virtual int Show_price() const { return 0; }
    virtual char* Show_producer() const { return nullptr; }
    virtual bool compareName(const char* inputId) const { return false; }
};

class Book : public Product {
private:
    char* ID;
    char* author;
    char* title;

public:
    Book(const char* id, int price, const char* iproducer, const char* iID, const char* iauthor, const char* ititle)
        : Product(id, price, iproducer), ID(nullptr), author(nullptr), title(nullptr) {
        ID = new char[strlen(iID) + 1];
        strcpy(ID, iID);

        author = new char[strlen(iauthor) + 1];
        strcpy(author, iauthor);

        title = new char[strlen(ititle) + 1];
        strcpy(title, ititle);

        BookCount.push_back(input_Count);
    }

    ~Book() {
        delete[] ID;
        delete[] author;
        delete[] title;
    }

    char* Show_id() const override { return id; }
    int Show_price() const override { return price; }
    char* Show_producer() const override { return producer; }

    bool compareName(const char* inputId) const override {
        return strcmp(title, inputId) == 0;
    }

    char* Get_ID() const { return ID; }
    char* Get_author() const { return author; }
    char* Get_title() const { return title; }
};

class Handphone : public Product {
private:
    char* model;
    int RAM;

public:
    Handphone(const char* id, int price, const char* iproducer, const char* imodel, int RAM)
        : Product(id, price, iproducer), model(nullptr), RAM(RAM) {
        model = new char[strlen(imodel) + 1];
        strcpy(model, imodel);

        PhoneCount.push_back(input_Count);
    }

    ~Handphone() {
        delete[] model;
    }

    char* Show_id() const override { return id; }
    int Show_price() const override { return price; }
    char* Show_producer() const override { return producer; }

    bool compareName(const char* inputId) const override {
        return strcmp(model, inputId) == 0;
    }

    char* Get_model() const { return model; }
    int Get_RAM() const { return RAM; }
};

class Computer : public Product {
private:
    char* model;
    char* cpu;
    int RAM;

public:
    Computer(const char* id, int price, const char* iproducer, const char* imodel, const char* icpu, int RAM)
        : Product(id, price, iproducer), model(nullptr), cpu(nullptr), RAM(RAM) {
        model = new char[strlen(imodel) + 1];
        strcpy(model, imodel);

        cpu = new char[strlen(icpu) + 1];
        strcpy(cpu, icpu);

        ComputerCount.push_back(input_Count);
    }

    ~Computer() {
        delete[] model;
        delete[] cpu;
    }

    char* Show_id() const override { return id; }
    int Show_price() const override { return price; }
    char* Show_producer() const override { return producer; }

    bool compareName(const char* inputId) const override {
        return strcmp(model, inputId) == 0;
    }

    char* Get_model() const { return model; }
    char* Get_cpu() const { return cpu; }
    int Get_RAM() const { return RAM; }
};

int main(void) {
    vector<Product*> products;  // 동적 배열 사용을 위해 vector 사용

    while (1) {
        int input;
        cout << "-------------상품관리 프로그램-----------------" << endl;
        cout << "1. 상품추가    2. 상품출력    3. 상품검색    0. 종료" << endl;
        cout << ">> ";
        cin >> input;
        cout << "\n" << endl;

        if (input == 0) {
            // 벡터의 동적 할당된 객체들을 해제
            for (Product* p : products) {
                delete p;
            }
            exit(1);
        }

        if (input == 1) {
            int Add_input;
            cout << "1. 책 추가\n"
                << "2. 핸드폰 추가\n"
                << "3. 컴퓨터 추가\n"
                << ">> ";
            cin >> Add_input;
            cout << "\n" << endl;

            // ... (입력 부분은 그대로 유지)

        }

        if (input == 2) {
            int print_input;
            cout << "1. 책 출력\n"
                << "2. 핸드폰 출력\n"
                << "3. 컴퓨터 출력\n"
                << ">> ";
            cin >> print_input;
            cout << "\n" << endl;

            // ... (출력 부분은 그대로 유지)

        }

        if (input == 3) {
            int search_input;

            cout << "1. 책 검색\n"
                << "2. 핸드폰 검색\n"
                << "3. 컴퓨터 검색\n"
                << ">> ";
            cin >> search_input;
            cout << "\n" << endl;

            // ... (검색 부분은 그대로 유지)

        }
    }

    return 0;
}
