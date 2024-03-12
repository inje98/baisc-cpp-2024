#include <iostream>
#include <string>
#include <cstdlib> // exit �Լ��� ����ϱ� ���� �߰�

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
        cout << "-------------��ǰ���� ���α׷�-----------------" << endl;
        cout << "1. ��ǰ�߰�    2. ��ǰ���    3. ��ǰ�˻�    0. ����" << endl;
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
            cout << "1. å �߰�\n"
                << "2. �ڵ��� �߰�\n"
                << "3. ��ǻ�� �߰�\n"
                << ">> ";
            cin >> Add_input;
            cout << "\n" << endl;

            if (Add_input == 1)
            {
                string ID, producer, ISBN, author, title;
                int price;
                cout << "ID: ";
                cin >> ID;
                cout << "����: ";
                cin >> price;
                cout << "������: ";
                cin >> producer;
                cout << "ISBN: ";
                cin >> ISBN;
                cout << "�۰�: ";
                cin >> author;
                cout << "����: ";
                cin >> title;

                product[input_Count++] = new Book(ID, price, producer, ISBN, author, title);
            }

            if (Add_input == 2)
            {
                string ID, producer, model;
                int price, RAM;
                cout << "ID: ";
                cin >> ID;
                cout << "����: ";
                cin >> price;
                cout << "������: ";
                cin >> producer;
                cout << "��: ";
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
                cout << "����: ";
                cin >> price;
                cout << "������: ";
                cin >> producer;
                cout << "��: ";
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
            cout << "1. å ���\n"
                << "2. �ڵ��� ���\n"
                << "3. ��ǻ�� ���\n"
                << ">> ";
            cin >> print_input;
            cout << "\n" << endl;

            if (print_input == 1)
            {
                cout << "================= �Էµ� å ����Ʈ ==================\n" << endl;
                for (int i = 0; i < BookCounting; i++)
                {
                    cout << "å id: " << product[BookCount[i]]->Show_id() << endl;

                    cout << "å ����: " << product[BookCount[i]]->Show_price() << endl;
                    cout << "å ���ǻ�: " << product[BookCount[i]]->Show_producer() << endl;
                    cout << "å ID: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_ID() << endl;
                    cout << "å �۰�: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_author() << endl;
                    cout << "å ����: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_title() << endl << endl;
                }
                cout << "====================================================\n" << endl;
            }

            if (print_input == 2)
            {
                cout << "================= �Էµ� �ڵ��� ����Ʈ ==================\n" << endl;

                for (int i = 0; i < PhoneCounting; i++)
                {
                    cout << "�ڵ��� ID: " << product[PhoneCount[i]]->Show_id() << endl;
                    cout << "�ڵ��� ����: " << product[PhoneCount[i]]->Show_price() << endl;
                    cout << "�ڵ��� ������: " << product[PhoneCount[i]]->Show_producer() << endl;
                    cout << "�ڵ��� ��: " << dynamic_cast<Handphone*>(product[PhoneCount[i]])->Get_model() << endl;
                    cout << "�ڵ��� RAM: " << dynamic_cast<Handphone*>(product[PhoneCount[i]])->Get_RAM() << endl << endl;
                }
                cout << "======================================================\n" << endl;
            }

            if (print_input == 3)
            {
                cout << "================= �Էµ� ��ǻ�� ����Ʈ ==================\n" << endl;

                for (int i = 0; i < ComputerCounting; i++)
                {
                    cout << "��ǻ�� ID: " << product[ComputerCount[i]]->Show_id() << endl;
                    cout << "��ǻ�� ����: " << product[ComputerCount[i]]->Show_price() << endl;
                    cout << "��ǻ�� ������: " << product[ComputerCount[i]]->Show_producer() << endl;
                    cout << "��ǻ�� ��: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_model() << endl;
                    cout << "��ǻ�� cpu: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_cpu() << endl;
                    cout << "��ǻ�� RAM: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_RAM() << endl << endl;
                }
                cout << "======================================================\n" << endl;
            }
        }

        if (input == 3)
        {
            int search_input;

            cout << "1. å �˻�\n"
                << "2. �ڵ��� �˻�\n"
                << "3. ��ǻ�� �˻�\n"
                << ">> ";
            cin >> search_input;
            cout << "\n" << endl;

            if (search_input == 1)
            {
                string findTitle;
                cout << "�˻��� å ������ �Է� >> ";
                cin >> findTitle;
                bool find = false;
                for (int i = 0; i < BookCounting; i++)
                {
                    if (dynamic_cast<Book*>(product[BookCount[i]])->compareName(findTitle))
                    {
                        cout << "\n======== " << dynamic_cast<Book*>(product[BookCount[i]])->Get_title() << " å�� ���� ==========\n" << endl;
                        cout << "id: " << product[BookCount[i]]->Show_id() << endl;
                        cout << "����: " << product[BookCount[i]]->Show_price() << endl;
                        cout << "���ǻ�: " << product[BookCount[i]]->Show_producer() << endl;
                        cout << "ISBN: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_ID() << endl;
                        cout << "�۰�: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_author() << endl;
                        cout << "����: " << dynamic_cast<Book*>(product[BookCount[i]])->Get_title() << endl;
                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (!find)
                {
                    cout << "�׷� å ����!" << endl;
                }
            }

            if (search_input == 2)
            {
                string findModel;
                cout << "�˻��� �ڵ��� �𵨸��� �Է� >> ";
                cin >> findModel;
                bool find = false;
                for (int i = 0; i < PhoneCounting; i++)
                {
                    if (dynamic_cast<Handphone*>(product[PhoneCount[i]])->compareName(findModel))
                    {
                        cout << "\n======== " << dynamic_cast<Handphone*>(product[PhoneCount[i]])->Get_model() << " �ڵ����� ���� ==========\n" << endl;
                        cout << "id: " << product[PhoneCount[i]]->Show_id() << endl;
                        cout << "����: " << product[PhoneCount[i]]->Show_price() << endl;
                        cout << "������: " << product[PhoneCount[i]]->Show_producer() << endl;
                        cout << "��: " << dynamic_cast<Handphone*>(product[PhoneCount[i]])->Get_model() << endl;
                        cout << "RAM: " << dynamic_cast<Handphone*>(product[PhoneCount[i]])->Get_RAM() << endl;
                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (!find)
                {
                    cout << "�׷� �ڵ��� ����!" << endl;
                }
            }

            if (search_input == 3)
            {
                string findModel;
                cout << "�˻��� ��ǻ�� �𵨸��� �Է� >> ";
                cin >> findModel;
                bool find = false;
                for (int i = 0; i < ComputerCounting; i++)
                {
                    if (dynamic_cast<Computer*>(product[ComputerCount[i]])->compareName(findModel))
                    {
                        cout << "\n======== " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_model() << " ��ǻ���� ���� ==========\n" << endl;
                        cout << "id: " << product[ComputerCount[i]]->Show_id() << endl;
                        cout << "����: " << product[ComputerCount[i]]->Show_price() << endl;
                        cout << "������: "<< product[ComputerCount[i]]->Get_producer() << endl;
                        cout << "��: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_model() << endl;
                        cout << "CPU: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_cpu() << endl;
                        cout << "RAM: " << dynamic_cast<Computer*>(product[ComputerCount[i]])->Get_RAM() << endl;
                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (!find)
                {
                    cout << "�׷� ��ǻ�� ����!" << endl;
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
