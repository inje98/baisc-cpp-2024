#include <iostream>
#include <string>
#include <cstdlib> // exit 함수를 사용하기 위해 추가

using namespace std;

int input_Count = 0;

int BookCount[100];
int BookCounting = 0;

int PhoneCount[100];
int PhoneCounting = 0;

int ComputerCount[100];
int ComputerCounting = 0;

class Product
{
protected:
    string id;
    int price;
    string producer;

public:
    Product(const string& iid, int price, const string& iproducer)
        : id(iid), price(price), producer(iproducer) {}

    virtual ~Product() {}

    string Get_id() const { return id; }
    int Get_price() const { return price; }
    string Get_producer() const { return producer; }

    virtual string Show_id() { return ""; }
    virtual int Show_price() { return 0; }
    virtual string Show_producer() { return ""; }
    virtual bool compareName(const string& inputId) { return false; }
};

class Book : public Product
{
private:
    string ID;
    string author;
    string title;

public:
    Book(const string& id, int price, const string& iproducer, const string& iID, const string& iauthor, const string& ititle)
        : Product(id, price, iproducer), ID(iID), author(iauthor), title(ititle)
    {
        BookCount[BookCounting++] = input_Count;
    }

    ~Book() {}

    string Show_id() override { return id; }
    int Show_price() override { return price; }
    string Show_producer() override { return producer; }

    bool compareName(const string& inputId) override
    {
        return title == inputId;
    }

    string Get_ID() { return ID; }
    string Get_author() { return author; }
    string Get_title() { return title; }
};

class Handphone : public Product
{
private:
    string model;
    int RAM;

public:
    Handphone(const string& id, int price, const string& iproducer, const string& imodel, int RAM)
        : Product(id, price, iproducer), model(imodel), RAM(RAM)
    {
        PhoneCount[PhoneCounting++] = input_Count;
    }

    ~Handphone() {}

    string Show_id() override { return id; }
    int Show_price() override { return price; }
    string Show_producer() override { return producer; }

    bool compareName(const string& inputId) override
    {
        return model == inputId;
    }

    string Get_model() { return model; }
    int Get_RAM() { return RAM; }
};

class Computer : public Product
{
private:
    string model;
    string cpu;
    int RAM;

public:
    Computer(const string& id, int price, const string& iproducer, const string& imodel, const string& icpu, int RAM)
        : Product(id, price, iproducer), model(imodel), cpu(icpu), RAM(RAM)
    {
        ComputerCount[ComputerCounting++] = input_Count;
    }

    ~Computer() {}

    string Show_id() override { return id; }
    int Show_price() override { return price; }
    string Show_producer() override { return producer; }

    bool compareName(const string& inputId) override
    {
        return model == inputId;
    }

    string Get_model() { return model; }
    string Get_cpu() { return cpu; }
    int Get_RAM() { return RAM; }
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

            if (Add_input == 1)
            {
                string ID, producer, ISBN, author, title;
                int price;
                cout << "ID: ";
                cin >> ID;
                cout << "가격: ";
                cin >> price;
                cout << "제조사: ";
                cin >> producer;
                cout << "ISBN: ";
                cin >> ISBN;
                cout << "작가: ";
                cin >> author;
                cout << "제목: ";
                cin >> title;

                product[input_Count++] = new Book(ID, price, producer, ISBN, author, title);
            }

            if (Add_input == 2)
            {
                string ID, producer, model;
                int price, RAM;
                cout << "ID: ";
                cin >> ID;
                cout << "가격: ";
                cin >> price;
                cout << "제조사: ";
                cin >> producer;
                cout << "모델: ";
                cin >> model;
                cout << "RAM: ";
                cin >> RAM;

                product[input_Count++] = new Handphone(ID, price, producer, model, RAM);
            }

            if (Add_input == 3)
            {
                string ID, producer, model, cpu;
                int price, RAM;
                cout << "ID: ";
                cin >> ID;
                cout << "가격: ";
                cin >> price;
                cout << "제조사: ";
                cin >> producer;
                cout << "모델: ";
                cin >> model;
                cout << "CPU: ";
                cin >> cpu;
                cout << "RAM: ";
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
                    cout << "책 출판사: " << product[BookCount[i]]->Show_producer() << endl;
                    cout << "책 ID: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_ID() << endl;
                    cout << "책 작가: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_author() << endl;
                    cout << "책 제목: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_title() << endl << endl;
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
                    cout << "핸드폰 모델: " << dynamic_cast<Handphone*>(product[PhoneCount[i]])->Get_model() << endl;
                    cout << "핸드폰 RAM: " << dynamic_cast<Handphone*>(product[PhoneCount[i]])->Get_RAM() << endl << endl;
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
                    cout << "컴퓨터 모델: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_model() << endl;
                    cout << "컴퓨터 cpu: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_cpu() << endl;
                    cout << "컴퓨터 RAM: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_RAM() << endl << endl;
                }
                cout << "======================================================\n" << endl;
            }
        }

        if (input == 3)
        {
            int search_input;

            cout << "1. 책 검색\n"
                << "2. 핸드폰 검색\n"
                << "3. 컴퓨터 검색\n"
                << ">> ";
            cin >> search_input;
            cout << "\n" << endl;

            if (search_input == 1)
            {
                string findTitle;
                cout << "검색할 책 제목을 입력 >> ";
                cin >> findTitle;
                bool find = false;
                for (int i = 0; i < BookCounting; i++)
                {
                    if (dynamic_cast<Book*>(product[BookCount[i]])->compareName(findTitle))
                    {
                        cout << "\n======== " << dynamic_cast<Book*>(product[BookCount[i]])->Get_title() << " 책의 정보 ==========\n" << endl;
                        cout << "id: " << product[BookCount[i]]->Show_id() << endl;
                        cout << "가격: " << product[BookCount[i]]->Show_price() << endl;
                        cout << "출판사: " << product[BookCount[i]]->Show_producer() << endl;
                        cout << "ISBN: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_ID() << endl;
                        cout << "작가: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_author() << endl;
                        cout << "제목: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_title() << endl;
                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (!find)
                {
                    cout << "그런 책 없음!" << endl;
                }
            }

            if (search_input == 2)
            {
                string findModel;
                cout << "검색할 핸드폰 모델명을 입력 >> ";
                cin >> findModel;
                bool find = false;
                for (int i = 0; i < PhoneCounting; i++)
                {
                    if (dynamic_cast<Handphone*>(product[PhoneCount[i]])->compareName(findModel))
                    {
                        cout << "\n======== " << dynamic_cast<Handphone*>(product[PhoneCount[i]])->Get_model() << " 핸드폰의 정보 ==========\n" << endl;
                        cout << "id: " << product[PhoneCount[i]]->Show_id() << endl;
                        cout << "가격: " << product[PhoneCount[i]]->Show_price() << endl;
                        cout << "제조사: " << product[PhoneCount[i]]->Show_producer() << endl;
                        cout << "모델: " << dynamic_cast<Handphone*>(product[PhoneCount[i]])->Get_model() << endl;
                        cout << "RAM: " << dynamic_cast<Handphone*>(product[PhoneCount[i]])->Get_RAM() << endl;
                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (!find)
                {
                    cout << "그런 핸드폰 없음!" << endl;
                }
            }

            if (search_input == 3)
            {
                string findModel;
                cout << "검색할 컴퓨터 모델명을 입력 >> ";
                cin >> findModel;
                bool find = false;
                for (int i = 0; i < ComputerCounting; i++)
                {
                    if (dynamic_cast<Computer*>(product[ComputerCount[i]])->compareName(findModel))
                    {
                        cout << "\n======== " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_model() << " 컴퓨터의 정보 ==========\n" << endl;
                        cout << "id: " << product[ComputerCount[i]]->Show_id() << endl;
                        cout << "가격: " << product[ComputerCount[i]]->Show_price() << endl;
                        cout << "제조사: "<< product[ComputerCount[i]]->Get_producer() << endl;
                        cout << "모델: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_model() << endl;
                        cout << "CPU: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_cpu() << endl;
                        cout << "RAM: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_RAM() << endl;
                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (!find)
                {
                    cout << "그런 컴퓨터 없음!" << endl;
                }
            }
        }
    }
    
    for (int i = 0; i < input_Count; ++i)
    {
        delete product[i];
    }

    return 0;
}
