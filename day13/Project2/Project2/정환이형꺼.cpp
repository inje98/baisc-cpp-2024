#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 도서 정보를 담는 구조체
struct Book {
    char title[50];    // 도서 제목
    char author[50];   // 저자
    int year;          // 출판년도
    int rented;        // 대여 여부 (0: 대여 가능, 1: 대여 중)
    int price;         // 가격
    struct Book* next; // 다음 도서를 가리키는 포인터
};

struct Book* head = NULL; // 도서 목록의 시작을 가리키는 전역 변수

// 도서 추가 함수
void addBook() {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book)); // 새로운 도서를 위한 메모리 할당
    if (newBook == NULL) { // 메모리 할당 실패 시 오류 메시지 출력 후 종료
        printf("메모리 할당 오류\n");
        return;
    }

    printf("도서 제목: ");
    scanf("%s", newBook->title);
    printf("저자: ");
    scanf("%s", newBook->author);
    printf("출판년도: ");
    scanf("%d", &newBook->year);
    printf("가격: ");
    scanf("%d", &newBook->price);
    newBook->rented = 0; // 초기값은 대여 가능

    newBook->next = head; // 새로운 도서를 목록의 맨 앞에 추가
    head = newBook;
}

// 도서 검색 및 대여 함수
void searchBook() {
    char title[50];
    printf("검색할 도서 제목: ");
    scanf("%s", title);

    struct Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) { // 입력한 도서 제목과 일치하는 도서를 찾았을 때
            printf("도서가 존재합니다.\n");
            if (current->rented == 0) {
                printf("도서를 대여합니다.\n");
                current->rented = 1; // 도서를 대여 중으로 변경
            }
            else {
                printf("죄송합니다. 해당 도서는 이미 대여 중입니다.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("도서가 존재하지 않습니다.\n");
}
// 도서 반납 함수
void returnBook() {
    char title[50];
    printf("반납할 도서 제목: ");
    scanf("%s", title);

    struct Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) { // 입력한 도서 제목과 일치하는 도서를 찾았을 때
            if (current->rented == 1) {
                current->rented = 0; // 도서를 대여 가능으로 변경
                printf("도서를 반납했습니다.\n");
            }
            else {
                printf("이 도서는 대여 중이 아닙니다.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

// 도서 삭제 함수
void deleteBook() {
    char title[50];
    printf("삭제할 도서 제목: ");
    scanf("%s", title);

    struct Book* prev = NULL;
    struct Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) { // 입력한 도서 제목과 일치하는 도서를 찾았을 때
            if (prev == NULL) {
                head = current->next; // 첫 번째 도서를 삭제할 때
            }
            else {
                prev->next = current->next;
            }
            free(current); // 메모리 해제
            printf("도서를 삭제했습니다.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("해당 도서를 찾을 수 없습니다.\n");
}

// 도서 목록 출력 함수
void printBooks() {
    printf("도서 목록:\n");
    struct Book* current = head;
    while (current != NULL) {
        printf("%s (%s, %d) - %s\n", current->title, current->author, current->year, current->rented == 0 ? "대여 가능" : "대여 중");
        current = current->next;
    }
}

// 메뉴 함수
void menu() {
    int choice;
    do {
        printf("\n**** 메뉴 ****\n");
        printf("1 도서구입\n");
        printf("2 도서검색\n");
        printf("3 도서반납\n");
        printf("4 도서삭제\n");
        printf("5 도서출력\n");
        printf("0 종료\n");
        printf("선택: ");
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
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다. 다시 선택해주세요.\n");
        }
    } while (choice != 0);
}
// 프로그램 시작점
void main() {
    menu(); // 메뉴 호출
}