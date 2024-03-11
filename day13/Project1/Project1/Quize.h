#pragma once

class Product
{
protected:
    char* id;
    int price;
    char* producer;

public:
    Product(const char* iid, int price, const char* iproducer) :id(id), price(price) {};
   

    ~Product();
   

    char* Get_id() const;
    int Get_price() const;
    char* Get_producer() const;

    virtual char* Show_id();
    virtual int Show_price();
    virtual char* Show_producer();
    virtual bool compareName(const char* inputId);   // 3번 검색할때 쓸거

};

class Book : public Product
{
private:
    char* ID;
    char* author;
    char* title;

public:
    Book(const char* id, int price, const char* iproducer, const char* iID, const char* iauthor, const char* ititle)
        :Product(id, price, iproducer) {}
        ;
    ~Book();
    char* Show_id();
    int Show_price();
    char* Show_producer();
    bool compareName(const char* inputId);
    char* Get_ID();
    char* Get_author();
    char* Get_title();
};

int input_Count = 0;

int BookCount[100];
int BookCounting = 0;   // BookCount[BookCounting++] = input_Count   ==> 몇번 인덱스에서 책 객체가 만들어졌는지 알기위해

int PhoneCount[100];
int PhoneCounting = 0;

int ComputerCount[100];
int ComputerCounting = 0;