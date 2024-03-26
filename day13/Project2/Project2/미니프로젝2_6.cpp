#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE {
    char BookTitle[40];
    int price;
    char author[40];
    char company[40];
    char ID[40];
    struct NODE* next;
} node;

typedef struct HEAD {
    node* headNode;
} head;

head* createHead() {
    head* headNode = (head*)malloc(sizeof(head));
    headNode->headNode = NULL;
    return headNode;
}

void addBook(head* headNode, const char* BookTitle, int price, const char* author, const char* company, const char* ID) {
    node* newBook = (node*)malloc(sizeof(node));
    strcpy(newBook->BookTitle, BookTitle);
    newBook->price = price;
    strcpy(newBook->author, author);
    strcpy(newBook->company, company);
    strcpy(newBook->ID, ID);
    newBook->next = NULL;

    if (headNode->headNode == NULL) {
        headNode->headNode = newBook;
        return;
    }

    node* curr = headNode->headNode;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newBook;
}

void deleteBook(head* headNode, const char* deleteB) {
    node* curr = headNode->headNode;
    node* prev = NULL;

    if (curr == NULL) {
        printf("å�� �ϳ��� ���µ���??\n");
        return;
    }

    if (strcmp(curr->BookTitle, deleteB) == 0) {
        headNode->headNode = curr->next;
        free(curr);
        return;
    }

    while (curr != NULL && strcmp(curr->BookTitle, deleteB) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("\n%s ���µ���?\n\n", deleteB);
        return;
    }

    prev->next = curr->next;
    free(curr);
}

void SearchBook(head* headNode, head* rentHeadNode, const char* searchBook) {
    node* curr = headNode->headNode;
    node* prev = NULL;

    while (curr != NULL && strcmp(curr->BookTitle, searchBook) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("\n%s ���µ���?\n\n", searchBook);
        return;
    }

    printf("\n======= %s ���� =======\n\n", curr->BookTitle);
    printf("���� : %s\n", curr->BookTitle);
    printf("���� : %d\n", curr->price);
    printf("�۰� : %s\n", curr->author);
    printf("���ǻ� : %s\n", curr->company);
    printf("ID : %s\n", curr->ID);
    printf("\n=======================\n\n");

    int rent = -1;
    while (rent != 1 && rent != 2) {
        printf("�� å�� �뿩�Ͻðڽ��ϱ�?\n");
        printf("1. �뿩   2. ���\n");
        printf(">> ");
        scanf("%d", &rent);
        getchar();
    }

    if (rent == 1) {
        deleteBook(headNode, curr->BookTitle);
        addBook(rentHeadNode, curr->BookTitle, curr->price, curr->author, curr->company, curr->ID);
    }
}

void returningBook(head* headNode, head* rentHeadNode, const char* searchBook) {
    node* curr = rentHeadNode->headNode;
    node* prev = NULL;

    while (curr != NULL && strcmp(curr->BookTitle, searchBook) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("�׷� å ���� �� �����ϴ�.\n");
        return;
    }

    printf("\n======= %s ���� =======\n\n", curr->BookTitle);
    printf("���� : %s\n", curr->BookTitle);
    printf("���� : %d\n", curr->price);
    printf("�۰� : %s\n", curr->author);
    printf("���ǻ� : %s\n", curr->company);
    printf("ID : %s\n", curr->ID);
    printf("\n=======================\n\n");

    int return_choice = -1;
    while (return_choice != 1 && return_choice != 2) {
        printf("�� å�� �ݳ��Ͻðڽ��ϱ�?\n");
        printf("1. �ݳ�   2. ���\n");
        printf(">> ");
        scanf("%d", &return_choice);
        getchar();
    }

    if (return_choice == 1) {
        deleteBook(rentHeadNode, curr->BookTitle);
        addBook(headNode, curr->BookTitle, curr->price, curr->author, curr->company, curr->ID);
    }
}

void main() {
    head* headNode = createHead();
    head* rentHeadNode = createHead();

    while (1) {
        int menuNum;

        printf("1. �������\n2. �����˻�(�뿩)\n3. �����ݳ�\n4. ��������\n5. �������\n6. �뿩�� å ���\n0. ����\n>>  ");
        scanf("%d", &menuNum);
        getchar();

        switch (menuNum) {
        case 1: {
            char title[40];
            int price;
            char author[40];
            char company[40];
            char ID[40];

            printf("����   >> ");
            scanf("%s", title);
            printf("����   >> ");
            scanf("%d", &price);
            printf("�۰�   >> ");
            scanf("%s", author);
            printf("���ǻ� >> ");
            scanf("%s", company);
            printf("ID     >> ");
            scanf("%s", ID);

            addBook(headNode, title, price, author, company, ID);
            break;
        }
        case 2: {
            char search[40];
            printf("�˻��� å �̸� >> ");
            scanf("%s", search);
            SearchBook(headNode, rentHeadNode, search);
            break;
        }
        case 3: {
            char return_book[40];
            printf("�ݳ��� å �̸� >> ");
            scanf("%s", return_book);
            returningBook(headNode, rentHeadNode, return_book);
            break;
        }
        case 4: {
            char deleteB[40];
            printf("������ å �̸� >> ");
            scanf("%s", deleteB);
            deleteBook(headNode, deleteB);
            break;
        }
        case 5: {
            node* curr = headNode->headNode;

            if (curr == NULL) {
                printf("\nå�� �ϳ��� �����.\n\n");
            }
            else {
                printf("\n========== ��ü å ==========\n");
                while (curr != NULL) {
                    printf("%s\n", curr->BookTitle);
                    curr = curr->next;
                }
                printf("===============================\n");
            }
            break;
        }
        case 6: {
            node* curr = rentHeadNode->headNode;

            if (curr == NULL) {
                printf("\n�뿩�� å�� �ϳ��� �����.\n\n");
            }
            else {
                printf("\n========== �뿩�� ��ü å ==========\n");
                while (curr != NULL) {
                    printf("%s\n", curr->BookTitle);
                    curr = curr->next;
                }
                printf("=======================================\n");
            }
            break;
        }
        case 0: {
            // ���� ���� ��� �޸� ����
            node* curr = headNode->headNode;
            node* temp;

            while (curr != NULL) {
                temp = curr->next;
                free(curr);
                curr = temp;
            }

            curr = rentHeadNode->headNode;
            while (curr != NULL) {
                temp = curr->next;
                free(curr);
                curr = temp;
            }

            free(headNode);
            free(rentHeadNode);
            exit(0);
        }
        default:
            printf("1���� 6������ ���ڸ� �Է����ּ���.\n");
            break;
        }
    }
}