#include <stdio.h>
#include <stdlib.h>
// Link list là một cấu trúc dữ liệu tuyến tính, trong đó các phần tử được lưu trữ trong các nút (node) và mỗi nút chứa một con trỏ (pointer) đến nút tiếp theo trong danh sách. Điều này cho phép chèn và xóa các phần tử một cách linh hoạt mà không cần phải di chuyển các phần tử khác như trong mảng.
// Link list có thể được triển khai dưới dạng danh sách liên kết đơn (singly linked list), danh sách liên kết đôi (doubly linked list) hoặc danh sách liên kết vòng (circular linked list). Trong danh sách liên kết đơn, mỗi nút chỉ chứa một con trỏ đến nút tiếp theo, trong khi trong danh sách liên kết đôi, mỗi nút chứa hai con trỏ: một đến nút tiếp theo và một đến nút trước đó. Danh sách liên kết vòng là một biến thể của danh sách liên kết đơn hoặc đôi, trong đó nút cuối cùng trỏ lại đến nút đầu tiên, tạo thành một vòng tròn.
//single linked list: [data | next] -> [data | next] -> [data | next] -> NULL
//double linked list: [prev | data | next] <-> [prev | data | next] <-> [prev | data | next] <-> NULL
//circular linked list: [prev | data | next] -> [prev | data | next] -> [prev | data | next] -> [prev | data | next]
struct Node {
    int data;  // Dữ liệu của nút   
    struct Node* prev; // Con trỏ đến nút trước đó
    struct Node* next; // Con trỏ đến nút tiếp theo
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Cấp phát bộ nhớ cho nút mới
    newNode->data = data; // Gán dữ liệu cho nút mới
    newNode->prev = NULL; // Khởi tạo con trỏ prev của nút mới là NULL
    newNode->next = NULL; // Khởi tạo con trỏ next của nút mới là NULL
    return newNode;
}

void insertHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data); // Tạo nút mới
    if (*head == NULL) { // Nếu danh sách rỗng
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertHead(&head, 100);
    insertHead(&head, 50);
    insertHead(&head, 60);
    printList(head);
    return 0;
}