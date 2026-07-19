#include <stdio.h>
#include <stdlib.h>

// ==================== CIRCULAR SINGLY LINKED LIST - FULL FUNCTIONS ====================
// Quy uoc: con tro "head" tro toi nut dau tien.
// Nut cuoi cung co "next" tro nguoc lai ve "head" (thay vi NULL).

struct Node {
    int data;
    struct Node* next;
};

// ---- Tạo node mới ----
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ---- Kiểm tra danh sách rỗng ----
int isEmpty(struct Node* head) {
    return head == NULL;
}

// ---- Chèn đầu ----
void insertHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // tro vao chinh no
        *head = newNode;
        return;
    }
    // Tim nut cuoi cung (nut co next == head)
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    newNode->next = *head;
    last->next = newNode;
    *head = newNode;
}

// ---- Chèn cuối ----
void insertTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = *head;
}

// ---- Chèn vào vị trí bất kỳ (position tính từ 0) ----
void insertAt(struct Node** head, int data, int position) {
    if (position <= 0 || *head == NULL) {
        insertHead(head, data);
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == *head) break; // vuot qua het danh sach thi dung lai
    }
    struct Node* newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
}

// ---- Xóa đầu ----
void deleteHead(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) { // chi co 1 nut
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    last->next = *head;
    free(temp);
}

// ---- Xóa cuối ----
void deleteTail(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    while (current->next->next != *head) {
        current = current->next;
    }
    free(current->next);
    current->next = *head;
}

// ---- Xóa tại vị trí ----
void deleteAt(struct Node** head, int position) {
    if (*head == NULL) return;
    if (position <= 0) {
        deleteHead(head);
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    struct Node* temp = current->next;
    if (temp == *head) return; // vi tri khong hop le (vong het roi)
    current->next = temp->next;
    free(temp);
}

// ---- Xóa theo giá trị ----
void deleteValue(struct Node** head, int value) {
    if (*head == NULL) return;
    if ((*head)->data == value) {
        deleteHead(head);
        return;
    }
    struct Node* current = *head;
    while (current->next != *head && current->next->data != value) {
        current = current->next;
    }
    if (current->next == *head) return; // khong tim thay
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// ---- Tìm kiếm giá trị, trả về vị trí (index) hoặc -1 ----
int search(struct Node* head, int value) {
    if (head == NULL) return -1;
    struct Node* current = head;
    int index = 0;
    do {
        if (current->data == value) return index;
        current = current->next;
        index++;
    } while (current != head);
    return -1;
}

// ---- Đếm số lượng node ----
int countNodes(struct Node* head) {
    if (head == NULL) return 0;
    int count = 0;
    struct Node* current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

// ---- In danh sách (duyệt đúng 1 vòng) ----
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(quay ve head)\n");
}

// ---- Giải phóng toàn bộ danh sách ----
void freeList(struct Node** head) {
    if (*head == NULL) return;
    struct Node* current = (*head)->next;
    while (current != *head) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(*head);
    *head = NULL;
}

// ==================== MAIN TEST ====================
int main() {
    struct Node* head = NULL;

    insertTail(&head, 10);
    insertTail(&head, 20);
    insertTail(&head, 30);
    insertHead(&head, 5);
    insertAt(&head, 15, 2);

    printf("Danh sach: ");
    printList(head);

    printf("So luong node: %d\n", countNodes(head));
    printf("Vi tri cua 20: %d\n", search(head, 20));

    deleteAt(&head, 2);
    printf("Sau khi xoa vi tri 2: ");
    printList(head);

    deleteValue(&head, 5);
    printf("Sau khi xoa gia tri 5: ");
    printList(head);

    deleteHead(&head);
    printf("Sau khi xoa dau: ");
    printList(head);

    deleteTail(&head);
    printf("Sau khi xoa cuoi: ");
    printList(head);

    freeList(&head);
    printf("Sau khi giai phong: ");
    printList(head);

    return 0;
}