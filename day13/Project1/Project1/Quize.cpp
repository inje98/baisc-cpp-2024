#define _CRT_SECUER_NO_WARNINGS
#include"Quize.h"
#include<iostream>
using namespace std;



class Product
{
protected:
    char* id;
    int price;
    char* producer;

public:
    /*Product() :id(), price(), producer()
    {
       cout << "�⺻������ ȣ��" << endl;
    }*/

    Product(const char* iid, int price, const char* iproducer) :id(id), price(price)
    {
        //cout << "product ������ ȣ��" << endl;

        id = new char[strlen(iid) + 1];
        strcpy(id, iid);

        producer = new char[strlen(iproducer) + 1];
        strcpy(producer, iproducer);
    }

    ~Product()
    {
        //cout << "product �Ҹ��� ȣ��" << endl;
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

    virtual bool compareName(const char* inputId)   // 3�� �˻��Ҷ� ����
    {
        return 0;
    }


    //bool compareName(const char* inputId)
    //{
    //   return strcmp(id, inputId) == 0;  // ���ٸ� 1�� ��ȯ, �ٸ��� 0�� ��ȯ
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
        //cout << "�� ������" << endl;
        ID = new char[strlen(iID) + 1];
        strcpy(ID, iID);

        author = new char[strlen(iauthor) + 1];
        strcpy(author, iauthor);

        title = new char[strlen(ititle) + 1];
        strcpy(title, ititle);

        BookCount[BookCounting++] = input_Count;
        // for (int i = 0; i < BookCounting; i++)
        // {
        //      product[BookCount[i]].�Լ�()
        // }
        // 2�� ��ǰ��¿��� �̷������� �� ����

    }

    ~Book()
    {
        //cout << "�� �Ҹ���" << endl;
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
        return strcmp(title, inputId) == 0;  // ���ٸ� 1�� ��ȯ, �ٸ��� 0�� ��ȯ
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
        //cout << "�� ������" << endl;
        model = new char[strlen(imodel) + 1];
        strcpy(model, imodel);

        PhoneCount[PhoneCounting++] = input_Count;
    }

    ~Handphone()
    {
        //cout << "�� �Ҹ���" << endl;
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
        return strcmp(model, inputId) == 0;  // ���ٸ� 1�� ��ȯ, �ٸ��� 0�� ��ȯ
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
        //cout << "�� ������" << endl;
        model = new char[strlen(imodel) + 1];
        strcpy(model, imodel);

        cpu = new char[strlen(icpu) + 1];
        strcpy(cpu, icpu);

        ComputerCount[ComputerCounting++] = input_Count;

    }

    ~Computer()
    {
        //cout << "�� �Ҹ���" << endl;
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
        return strcmp(model, inputId) == 0;  // ���ٸ� 1�� ��ȯ, �ٸ��� 0�� ��ȯ
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