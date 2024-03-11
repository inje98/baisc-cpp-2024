#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string>
#include<vector>  // ��� �߰�: ���� �迭 ����� ���� vector ��� �߰�
using namespace std;

int input_Count = 0;

vector<int> BookCount;  // �迭���� vector�� ����
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

    virtual ~Product() {  // ���� �Ҹ��� �߰�
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
    vector<Product*> products;  // ���� �迭 ����� ���� vector ���

    while (1) {
        int input;
        cout << "-------------��ǰ���� ���α׷�-----------------" << endl;
        cout << "1. ��ǰ�߰�    2. ��ǰ���    3. ��ǰ�˻�    0. ����" << endl;
        cout << ">> ";
        cin >> input;
        cout << "\n" << endl;

        if (input == 0) {
            // ������ ���� �Ҵ�� ��ü���� ����
            for (Product* p : products) {
                delete p;
            }
            exit(1);
        }

        if (input == 1) {
            int Add_input;
            cout << "1. å �߰�\n"
                << "2. �ڵ��� �߰�\n"
                << "3. ��ǻ�� �߰�\n"
                << ">> ";
            cin >> Add_input;
            cout << "\n" << endl;

            // ... (�Է� �κ��� �״�� ����)

        }

        if (input == 2) {
            int print_input;
            cout << "1. å ���\n"
                << "2. �ڵ��� ���\n"
                << "3. ��ǻ�� ���\n"
                << ">> ";
            cin >> print_input;
            cout << "\n" << endl;

            // ... (��� �κ��� �״�� ����)

        }

        if (input == 3) {
            int search_input;

            cout << "1. å �˻�\n"
                << "2. �ڵ��� �˻�\n"
                << "3. ��ǻ�� �˻�\n"
                << ">> ";
            cin >> search_input;
            cout << "\n" << endl;

            // ... (�˻� �κ��� �״�� ����)

        }
    }

    return 0;
}
