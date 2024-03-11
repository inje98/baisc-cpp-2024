#define _CRT_SECUER_NO_WARNINGS
#include"Quize.h"
#include<iostream>
using namespace std;

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

            if (Add_input == 2) // �ڵ��� �߰�
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

            if (Add_input == 3) // ��ǻ�� �߰�
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
                    cout << "å ���ǻ�: " << product[BookCount[i]]->Show_producer() << endl;    // BookCount[i] �� ���� ��� �ε����� �� ��ü�� ����Ű�� �ֳ� �װ���
                    cout << "å ID: " << ((Book*)product[BookCount[i]])->Get_ID() << endl;
                    cout << "å �۰�: " << ((Book*)product[BookCount[i]])->Get_author() << endl;
                    cout << "å ����: " << ((Book*)product[BookCount[i]])->Get_title() << endl << endl;
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
                    cout << "�ڵ��� ��: " << ((Handphone*)product[PhoneCount[i]])->Get_model() << endl;
                    cout << "�ڵ��� RAM: " << ((Handphone*)product[PhoneCount[i]])->Get_RAM() << endl << endl;
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
                    cout << "��ǻ�� ��: " << ((Computer*)product[ComputerCount[i]])->Get_model() << endl;
                    cout << "��ǻ�� cpu: " << ((Computer*)product[ComputerCount[i]])->Get_cpu() << endl;
                    cout << "��ǻ�� RAM: " << ((Computer*)product[ComputerCount[i]])->Get_RAM() << endl << endl;
                }
                cout << "======================================================\n" << endl;
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

            if (serch_input == 1)    // å �˻�
            {
                char findTitle[30];
                cout << "�˻��� å ������ �Է� >> ";
                cin >> findTitle;
                bool find = false;
                for (int i = 0; i < BookCounting; i++)
                {
                    if (product[BookCount[i]]->compareName(findTitle) == 1)  //����(title)���� ��
                    {
                        cout << "\n======== " << ((Book*)product[BookCount[i]])->Get_title() << " å�� ���� ==========\n" << endl;

                        cout << "id: " << product[BookCount[i]]->Show_id() << endl;
                        cout << "����: " << product[BookCount[i]]->Show_price() << endl;
                        cout << "���ǻ�: " << product[BookCount[i]]->Show_producer() << endl;
                        cout << "ISBN: " << ((Book*)product[BookCount[i]])->Get_ID() << endl;
                        cout << "�۰�: " << ((Book*)product[BookCount[i]])->Get_author() << endl;
                        cout << "����: " << ((Book*)product[BookCount[i]])->Get_title() << endl;

                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (find == false)
                {
                    cout << "�׷� å ����!" << endl;
                }
            }

            if (serch_input == 2)  // �� �˻�
            {
                char findModel[30];
                cout << "�˻��� �ڵ��� �𵨸��� �Է� >> ";
                cin >> findModel;
                bool find = false;
                for (int i = 0; i < PhoneCounting; i++)
                {
                    if (product[PhoneCount[i]]->compareName(findModel) == 1)  // ��(model)���� ��
                    {
                        cout << "\n======== " << ((Handphone*)product[PhoneCount[i]])->Get_model() << " �ڵ����� ���� ==========\n" << endl;
                        cout << "id: " << product[PhoneCount[i]]->Show_id();
                        cout << "����: " << product[PhoneCount[i]]->Show_price() << endl;
                        cout << "������: " << product[PhoneCount[i]]->Show_producer() << endl;
                        cout << "��: " << ((Handphone*)product[PhoneCount[i]])->Get_model() << endl;
                        cout << "RAM: " << ((Handphone*)product[PhoneCount[i]])->Get_RAM() << endl;
                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (find == false)
                {
                    cout << "�׷� �ڵ��� ����!" << endl;
                }
            }

            if (serch_input == 3) // ��ǻ�� �˻�
            {
                char findModel[30];
                cout << "�˻��� ��ǻ�� �𵨸��� �Է� >> ";
                cin >> findModel;
                bool find = false;
                for (int i = 0; i < ComputerCounting; i++)
                {
                    if (product[ComputerCount[i]]->compareName(findModel) == 1)
                    {
                        cout << "\n======== " << ((Computer*)product[ComputerCount[i]])->Get_model() << " ��ǻ���� ���� ==========\n" << endl;
                        cout << "id: " << product[ComputerCount[i]]->Show_id() << endl;
                        cout << "����: " << product[ComputerCount[i]]->Show_price() << endl;
                        cout << "������: " << product[ComputerCount[i]]->Show_producer() << endl;
                        cout << "��: " << ((Computer*)product[ComputerCount[i]])->Get_model() << endl;
                        cout << "��ǻ�� cpu: " << ((Computer*)product[ComputerCount[i]])->Get_cpu() << endl;
                        cout << "��ǻ�� RAM: " << ((Computer*)product[ComputerCount[i]])->Get_RAM() << endl;
                        cout << "\n===============================\n" << endl;
                        find = true;
                    }
                }
                if (find == false)
                {
                    cout << "�׷� ��ǻ�� ����!\n" << endl;
                }

            }
        }


    }
    for (int i = 0; i < input_Count; i++)
    {
        delete product[i];
    }

    re