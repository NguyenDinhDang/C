#include <stdio.h>
#include <stdlib.h>
// Link list là một cấu trúc dữ liệu tuyến tính, trong đó các phần tử được lưu trữ trong các nút (node) và mỗi nút chứa một con trỏ (pointer) đến nút tiếp theo trong danh sách. Điều này cho phép chèn và xóa các phần tử một cách linh hoạt mà không cần phải di chuyển các phần tử khác như trong mảng.
// Link list có thể được triển khai dưới dạng danh sách liên kết đơn (singly linked list), danh sách liên kết đôi (doubly linked list) hoặc danh sách liên kết vòng (circular linked list). Trong danh sách liên kết đơn, mỗi nút chỉ chứa một con trỏ đến nút tiếp theo, trong khi trong danh sách liên kết đôi, mỗi nút chứa hai con trỏ: một đến nút tiếp theo và một đến nút trước đó. Danh sách liên kết vòng là một biến thể của danh sách liên kết đơn hoặc đôi, trong đó nút cuối cùng trỏ lại đến nút đầu tiên, tạo thành một vòng tròn.
//single linked list: [data | next] -> [data | next] -> [data | next] -> NULL
//double linked list: [prev | data | next] <-> [prev | data | next] <-> [prev | data | next] <-> NULL
//circular linked list:
/* [prev | data | next] -> [prev | data | next] -> [prev | data | next] -> [prev | data | next] -> [prev | data | next] -> [prev | data | next] -> NULL */
struct Node {
    int data; // Dữ liệu của nút
    struct Node* next; // Con trỏ đến nút tiếp theo
};

// tạo node mới
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Cấp phát bộ nhớ cho nút mới
    newNode->data = data; // Gán dữ liệu cho nút mới
    newNode->next = NULL; // Khởi tạo con trỏ next của nút mới là NULL
    return newNode; 
}

void insertHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data); // Tạo nút mới
    newNode->next = *head; // Gán con trỏ next của nút mới trỏ đến nút hiện tại đầu danh sách
    *head = newNode; // Cập nhật con trỏ head trỏ đến nút mới
}

void insertTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data); // Tạo nút mới
    if (*head == NULL) { // Nếu danh sách rỗng
        *head = newNode; // Cập nhật con trỏ head trỏ đến nút mới
        return;
    }
    struct Node* current = *head; // Bắt đầu từ nút đầu tiên
    while (current->next != NULL) { // Duyệt đến nút cuối cùng
        current = current->next; 
    }
    current->next = newNode; // Gán con trỏ next của nút cuối cùng trỏ đến nút mới
}

void insertAt(struct Node** head, int data, int position) {
    if (position == 0) { // Nếu vị trí là 0, chèn vào đầu danh sách
        insertHead(head, data);
        return;
    }
    struct Node* newNode = createNode(data); // Tạo nút mới
    struct Node* current = *head; // Bắt đầu từ nút đầu tiên
    for (int i = 0; i < position - 1 && current != NULL; i++) { // Duyệt đến nút trước vị trí chèn
        current = current->next;
    }
    if (current == NULL) { // Nếu vị trí vượt quá độ dài danh sách, chèn vào cuối danh sách
        insertTail(head, data);
        return;
    }
    newNode->next = current->next; // Gán con trỏ next của nút mới trỏ đến nút tiếp theo của nút hiện tại
    current->next = newNode; // Gán con trỏ next của nút hiện tại trỏ đến nút mới
}

void deleteHead(struct Node** head) {
    if (*head == NULL) return; // Nếu danh sách rỗng, không làm gì
    struct Node* temp = *head; // Lưu trữ nút hiện tại đầu danh sách
    *head = (*head)->next; // Cập nhật con trỏ head trỏ đến nút tiếp theo
    free(temp); // Giải phóng bộ nhớ của nút cũ
}

void deleteTail(struct Node** head) {
    if (*head == NULL) return; // Nếu danh sách rỗng, không làm gì
    if ((*head)->next == NULL) { // Nếu danh sách chỉ có một nút
        free(*head); // Giải phóng bộ nhớ của nút đầu tiên
        *head = NULL; // Cập nhật con trỏ head trỏ đến NULL
        return;
    }
    struct Node* current = *head; // Bắt đầu từ nút đầu tiên
    while (current->next->next != NULL) { // Duyệt đến nút trước nút cuối cùng
        current = current->next;
    }
    free(current->next); // Giải phóng bộ nhớ của nút cuối cùng
    current->next = NULL; // Cập nhật con trỏ next của nút hiện tại trỏ đến NULL
}

void deleteAt(struct Node** head, int position) {
    if (*head == NULL) return; // Nếu danh sách rỗng, không làm gì
    if (position == 0) { // Nếu vị trí là 0, xóa nút đầu tiên
        deleteHead(head);
        return;
    }
    struct Node* current = *head; // Bắt đầu từ nút đầu tiên
    for (int i = 0; i < position - 1 && current != NULL; i++) { // Duyệt đến nút trước vị trí xóa
        current = current->next;
    }
    if (current == NULL || current->next == NULL) return; // Nếu vị trí vượt quá độ dài danh sách, không làm gì
    struct Node* temp = current->next; // Lưu trữ nút cần xóa
    current->next = temp->next; // Cập nhật con trỏ next của nút hiện tại trỏ đến nút tiếp theo của nút cần xóa
    free(temp); // Giải phóng bộ nhớ của nút cần xóa
}

void printList(struct Node* head) {
    struct Node* current = head; // Bắt đầu từ nút đầu tiên
    while (current != NULL) { // Duyệt qua danh sách cho đến khi gặp NULL
        printf("%d -> ", current->data); // In dữ liệu của nút hiện tại
        current = current->next; // Di chuyển đến nút tiếp theo
    }
    printf("NULL\n"); // Kết thúc danh sách
}

int main(){
    struct Node* head = NULL; // Khởi tạo danh sách rỗng
    insertHead(&head, 100); // Chèn phần tử 100 vào đầu danh sách
    insertHead(&head, 50); // Chèn phần tử 50 vào đầu danh sách
    insertHead(&head, 60); // Chèn phần tử 60 vào đầu danh sách
    printList(head); // In danh sách: 60 -> 50 -> 100 -> NULL
    return 0;
}