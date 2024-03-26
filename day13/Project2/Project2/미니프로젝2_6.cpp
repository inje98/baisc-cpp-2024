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
        printf("책이 하나도 없는데요??\n");
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
        printf("\n%s 없는데요?\n\n", deleteB);
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
        printf("\n%s 없는데요?\n\n", searchBook);
        return;
    }

    printf("\n======= %s 정보 =======\n\n", curr->BookTitle);
    printf("제목 : %s\n", curr->BookTitle);
    printf("가격 : %d\n", curr->price);
    printf("작가 : %s\n", curr->author);
    printf("출판사 : %s\n", curr->company);
    printf("ID : %s\n", curr->ID);
    printf("\n=======================\n\n");

    int rent = -1;
    while (rent != 1 && rent != 2) {
        printf("이 책을 대여하시겠습니까?\n");
        printf("1. 대여   2. 취소\n");
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
        printf("그런 책 빌린 적 없습니다.\n");
        return;
    }

    printf("\n======= %s 정보 =======\n\n", curr->BookTitle);
    printf("제목 : %s\n", curr->BookTitle);
    printf("가격 : %d\n", curr->price);
    printf("작가 : %s\n", curr->author);
    printf("출판사 : %s\n", curr->company);
    printf("ID : %s\n", curr->ID);
    printf("\n=======================\n\n");

    int return_choice = -1;
    while (return_choice != 1 && return_choice != 2) {
        printf("이 책을 반납하시겠습니까?\n");
        printf("1. 반납   2. 취소\n");
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

        printf("1. 도서등록\n2. 도서검색(대여)\n3. 도서반납\n4. 도서삭제\n5. 도서출력\n6. 대여한 책 출력\n0. 종료\n>>  ");
        scanf("%d", &menuNum);
        getchar();

        switch (menuNum) {
        case 1: {
            char title[40];
            int price;
            char author[40];
            char company[40];
            char ID[40];

            printf("제목   >> ");
            scanf("%s", title);
            printf("가격   >> ");
            scanf("%d", &price);
            printf("작가   >> ");
            scanf("%s", author);
            printf("출판사 >> ");
            scanf("%s", company);
            printf("ID     >> ");
            scanf("%s", ID);

            addBook(headNode, title, price, author, company, ID);
            break;
        }
        case 2: {
            char search[40];
            printf("검색할 책 이름 >> ");
            scanf("%s", search);
            SearchBook(headNode, rentHeadNode, search);
            break;
        }
        case 3: {
            char return_book[40];
            printf("반납할 책 이름 >> ");
            scanf("%s", return_book);
            returningBook(headNode, rentHeadNode, return_book);
            break;
        }
        case 4: {
            char deleteB[40];
            printf("삭제할 책 이름 >> ");
            scanf("%s", deleteB);
            deleteBook(headNode, deleteB);
            break;
        }
        case 5: {
            node* curr = headNode->headNode;

            if (curr == NULL) {
                printf("\n책이 하나도 없어요.\n\n");
            }
            else {
                printf("\n========== 전체 책 ==========\n");
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
                printf("\n대여한 책이 하나도 없어요.\n\n");
            }
            else {
                printf("\n========== 대여한 전체 책 ==========\n");
                while (curr != NULL) {
                    printf("%s\n", curr->BookTitle);
                    curr = curr->next;
                }
                printf("=======================================\n");
            }
            break;
        }
        case 0: {
            // 종료 전에 모든 메모리 해제
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
            printf("1부터 6까지의 숫자를 입력해주세요.\n");
            break;
        }
    }
}