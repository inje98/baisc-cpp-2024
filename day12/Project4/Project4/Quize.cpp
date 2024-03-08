#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int input_Count = 0;

int BookCount[100];
int BookCounting = 0;   // BookCount[BookCounting++] = input_Count   ==> ��� �ε������� å ��ü�� ����������� �˱�����

int PhoneCount[100];
int PhoneCounting = 0;

int ComputerCount[100];
int ComputerCounting = 0;

class Product
{
private:
	int id;
	int price;
	char* producer;

public:
	Product():id(), price(), producer()
	{
		cout << "�⺻������ ȣ��" << endl;
	}

	Product(int id, int price, const char* iproducer) :id(id), price(price)
	{
		cout << "product ������ ȣ��" << endl;
		producer = new char[strlen(iproducer) + 1];
		strcpy(producer, iproducer);
	}

	~Product()
	{
		cout << "product �Ҹ��� ȣ��" << endl;
		delete[] producer;
	}

	int Get_id() const { return id; }
	int Get_price() const { return price; }
	char* Get_producer() const { return producer; }

	virtual int Show_id()
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

	bool compareName(const char* inputName)
	{
		return strcmp(name, inputName) == 0;  // ���ٸ� 1�� ��ȯ, �ٸ��� 0�� ��ȯ
	}


};

class Book : public Product
{
private:
	char* ID;
	char* author;
	char* title;

public:
	Book(int id, int price, const char* iproducer, const char* iID, const char* iauthor, const char* ititle) 
	:Product(id, price, iproducer)
	{
		cout << "�� ������" << endl;
		ID = new char[strlen(iID) + 1];
		strcpy(ID, iID);

		author = new char[strlen(iauthor) + 1];
		strcpy(author, iauthor);

		title = new char[strlen(ititle) + 1];
		strcpy(ID, ititle);

		BookCount[BookCounting++] = input_Count;
		// for (int i = 0; i < BookCounting; i++)
		// {
		//		product[BookCount[i]].�Լ�()
		// }
		// 2�� ��ǰ��¿��� �̷������� �� ����

	}

	~Book()
	{
		cout << "�� �Ҹ���" << endl;
		delete[] ID;
		delete[] author;
		delete[] title;
	}

	int Show_id()
	{
		return Get_id();
	}

	int Show_price()
	{
		return Get_price();
	}

	char* Show_producer()
	{
		return Get_producer();
	}

	
};

class Handphone : public Product
{
private:
	char* model;
	int RAM;

public:
	Handphone(int id, int price, const char* iproducer, const char* imodel, int RAM)
		: Product(id, price, iproducer), RAM(RAM)
	{
		cout << "�� ������" << endl;
		model = new char[strlen(imodel) + 1];
		strcpy(model, imodel);

		PhoneCount[PhoneCounting++] = input_Count;
	}

	~Handphone()
	{
		cout << "�� �Ҹ���" << endl;
		delete[] model;
	}

	int Show_id()
	{
		return Get_id();
	}

	int Show_price()
	{
		return Get_price();
	}

	char* Show_producer()
	{
		return Get_producer();
	}
};

class Computer: public Product
{
private:
	char* model;
	char* cpu;
	int RAM;

public:
	Computer(int id, int price, const char* iproducer, const char* imodel, const char* icpu, int RAM)
		:Product(id, price, iproducer), RAM(RAM)
	{
		cout << "�� ������" << endl;
		model = new char[strlen(imodel) + 1];
		strcpy(model, imodel);

		cpu = new char[strlen(icpu) + 1];
		strcpy(cpu, icpu);

		ComputerCount[ComputerCounting++] = input_Count;

	}

	~Computer()
	{
		cout << "�� �Ҹ���" << endl;
		delete[] model;
		delete[] cpu;
	}

	int Show_id()
	{
		return Get_id();
	}

	int Show_price()
	{
		return Get_price();
	}

	char* Show_producer()
	{
		return Get_producer();
	}
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

			if (Add_input == 1)  // å �߰�
			{
				int ID;
				int price;
				char producer[30];
				char ISBN[30];
				char author[30];
				char title[30];
				cout << "ID(int) >> ";
				cin >> ID;
				cout << "price(int) >> ";
				cin >> price;
				cout << "producer(char[30]) >> ";
				cin >> producer;
				cout << "ISBN(char[30]) >> ";
				cin >> ISBN;
				cout << "author(char[30]) >> ";
				cin >> author;
				cout << "title(char[30]) >> ";
				cin >> title;
				
				product[input_Count++] = new Book(ID, price, producer, ISBN, author, title);
				// cout << product[0]->Get_id() << endl;
			}

			if (Add_input == 2) // �ڵ��� �߰�
			{
				int ID;
				int price;
				char producer[30];
				char model[30];
				int RAM;
				cout << "ID(int) >> ";
				cin >> ID;
				cout << "price(int) >> ";
				cin >> price;
				cout << "producer(char[30]) >> ";
				cin >> producer;
				cout << "model(char[30]) >> ";
				cin >> model;
				cout << "RAM(int) >> ";
				cin >> RAM;

				product[input_Count++] = new Handphone(ID, price, producer, model, RAM);
			}

			if (Add_input == 3) // ��ǻ�� �߰�
			{
				int ID;
				int price;
				char producer[30];
				char model[30];
				char cpu[30];
				int RAM;
				cout << "ID(int) >> ";
				cin >> ID;
				cout << "price(int) >> ";
				cin >> price;
				cout << "producer(char[30]) >> ";
				cin >> producer;
				cout << "model(char[30]) >> ";
				cin >> model;
				cout << "cpu(char[30]) >> ";
				cin >> cpu;
				cout << "RAM(int) >> ";
				cin >> RAM;

				product[input_Count++] = new Computer(ID, price, producer, model,cpu, RAM);
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
				for (int i = 0; i < BookCounting; i++)
				{
					cout <<"å ID: " << product[BookCount[i]]->Show_id() << endl;
					cout <<"å ����: " << product[BookCount[i]]->Show_price() << endl;
					cout << "å ���ǻ�: " << product[BookCount[i]]->Get_producer() << endl << endl;
				}
			}

			if (print_input == 2)
			{
				for (int i = 0; i < PhoneCounting; i++)
				{
					cout << "�ڵ��� ID: " << product[PhoneCount[i]]->Show_id() << endl;
					cout << "�ڵ��� ����: " << product[PhoneCount[i]]->Show_price() << endl;
					cout << "�ڵ��� ���ǻ�: " << product[PhoneCount[i]]->Get_producer() << endl << endl;
				}
			}

			if (print_input == 3)
			{
				for (int i = 0; i < ComputerCounting; i++)
				{
					cout << "��ǻ�� ID: " << product[ComputerCount[i]]->Show_id() << endl;
					cout << "��ǻ�� ����: " << product[ComputerCount[i]]->Show_price() << endl;
					cout << "��ǻ�� ���ǻ�: " << product[ComputerCount[i]]->Get_producer() << endl << endl;
				}
			}

		}

		if (input == 3)
		{
			int serch_input;

			cout << "1. å �˻�\n"
				<< "2. �ڵ��� �˻�\n"
				<< "3. ��ǻ�� �˻�\n"
				<< ">> ";
			cin >> serch_input;
			cout << "\n" << endl;
			
			if (serch_input == 1)
			{

			}

		}

	}






	for (int i = 0; i < input_Count; i++)
	{
		delete product[i];
	}

	return 0;
}






