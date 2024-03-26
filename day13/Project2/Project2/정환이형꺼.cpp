#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� ������ ��� ����ü
struct Book {
    char title[50];    // ���� ����
    char author[50];   // ����
    int year;          // ���ǳ⵵
    int rented;        // �뿩 ���� (0: �뿩 ����, 1: �뿩 ��)
    int price;         // ����
    struct Book* next; // ���� ������ ����Ű�� ������
};

struct Book* head = NULL; // ���� ����� ������ ����Ű�� ���� ����

// ���� �߰� �Լ�
void addBook() {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book)); // ���ο� ������ ���� �޸� �Ҵ�
    if (newBook == NULL) { // �޸� �Ҵ� ���� �� ���� �޽��� ��� �� ����
        printf("�޸� �Ҵ� ����\n");
        return;
    }

    printf("���� ����: ");
    scanf("%s", newBook->title);
    printf("����: ");
    scanf("%s", newBook->author);
    printf("���ǳ⵵: ");
    scanf("%d", &newBook->year);
    printf("����: ");
    scanf("%d", &newBook->price);
    newBook->rented = 0; // �ʱⰪ�� �뿩 ����

    newBook->next = head; // ���ο� ������ ����� �� �տ� �߰�
    head = newBook;
}

// ���� �˻� �� �뿩 �Լ�
void searchBook() {
    char title[50];
    printf("�˻��� ���� ����: ");
    scanf("%s", title);

    struct Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) { // �Է��� ���� ����� ��ġ�ϴ� ������ ã���� ��
            printf("������ �����մϴ�.\n");
            if (current->rented == 0) {
                printf("������ �뿩�մϴ�.\n");
                current->rented = 1; // ������ �뿩 ������ ����
            }
            else {
                printf("�˼��մϴ�. �ش� ������ �̹� �뿩 ���Դϴ�.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("������ �������� �ʽ��ϴ�.\n");
}
// ���� �ݳ� �Լ�
void returnBook() {
    char title[50];
    printf("�ݳ��� ���� ����: ");
    scanf("%s", title);

    struct Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) { // �Է��� ���� ����� ��ġ�ϴ� ������ ã���� ��
            if (current->rented == 1) {
                current->rented = 0; // ������ �뿩 �������� ����
                printf("������ �ݳ��߽��ϴ�.\n");
            }
            else {
                printf("�� ������ �뿩 ���� �ƴմϴ�.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("������ ã�� �� �����ϴ�.\n");
}

// ���� ���� �Լ�
void deleteBook() {
    char title[50];
    printf("������ ���� ����: ");
    scanf("%s", title);

    struct Book* prev = NULL;
    struct Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) { // �Է��� ���� ����� ��ġ�ϴ� ������ ã���� ��
            if (prev == NULL) {
                head = current->next; // ù ��° ������ ������ ��
            }
            else {
                prev->next = current->next;
            }
            free(current); // �޸� ����
            printf("������ �����߽��ϴ�.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("�ش� ������ ã�� �� �����ϴ�.\n");
}

// ���� ��� ��� �Լ�
void printBooks() {
    printf("���� ���:\n");
    struct Book* current = head;
    while (current != NULL) {
        printf("%s (%s, %d) - %s\n", current->title, current->author, current->year, current->rented == 0 ? "�뿩 ����" : "�뿩 ��");
        current = current->next;
    }
}

// �޴� �Լ�
void menu() {
    int choice;
    do {
        printf("\n**** �޴� ****\n");
        printf("1 ��������\n");
        printf("2 �����˻�\n");
        printf("3 �����ݳ�\n");
        printf("4 ��������\n");
        printf("5 �������\n");
        printf("0 ����\n");
        printf("����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            returnBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            printBooks();
            break;
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
        }
    } while (choice != 0);
}
// ���α׷� ������
void main() {
    menu(); // �޴� ȣ��
}