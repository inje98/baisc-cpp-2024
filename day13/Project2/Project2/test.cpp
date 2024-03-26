#include <iostream>
using namespace std;

// 노드 클래스
class Node {
public:
    int data;
    Node* next;

    // 생성자
    Node(int data) : data(data), next(nullptr) {}
};

// 연결 리스트 클래스
class LinkedList {
private:
    Node* head;

public:
    // 생성자
    LinkedList() : head(nullptr) {}

    // 노드 추가
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

    // 리스트 출력
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 소멸자: 동적으로 할당된 메모리 해제
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

    // 노드 추가
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);

    // 리스트 출력
    cout << "List: ";
    list.displayList();

    return 0;
}
