#include <iostream>
using namespace std;

// ��� Ŭ����
class Node {
public:
    int data;
    Node* next;

    // ������
    Node(int data) : data(data), next(nullptr) {}
};

// ���� ����Ʈ Ŭ����
class LinkedList {
private:
    Node* head;

public:
    // ������
    LinkedList() : head(nullptr) {}

    // ��� �߰�
    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // ����Ʈ ���
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // �Ҹ���: �������� �Ҵ�� �޸� ����
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;

    // ��� �߰�
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);

    // ����Ʈ ���
    cout << "List: ";
    list.displayList();

    return 0;
}
