#include <stdio.h>
#include <stdlib.h>

// ==================== DOUBLY LINKED LIST - FULL FUNCTIONS ====================

struct Node {
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
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
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// ---- Chèn cuối ----
void insertTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// ---- Chèn vào vị trí bất kỳ (position tính từ 0) ----
void insertAt(struct Node** head, int data, int position) {
    if (position <= 0 || *head == NULL) {
        insertHead(head, data);
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    struct Node* newNode = createNode(data);
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// ---- Xóa đầu ----
void deleteHead(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// ---- Xóa cuối ----
void deleteTail(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
}

// ---- Xóa tại vị trí ----
void deleteAt(struct Node** head, int position) {
    if (*head == NULL) return;
    if (position <= 0) {
        deleteHead(head);
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) return; // vi tri khong ton tai
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    free(current);
}

// ---- Xóa theo giá trị ----
void deleteValue(struct Node** head, int value) {
    struct Node* current = *head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    if (current == NULL) return; // khong tim thay
    if (current == *head) {
        deleteHead(head);
        return;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    current->prev->next = current->next;
    free(current);
}

// ---- Tìm kiếm giá trị, trả về vị trí (index) hoặc -1 ----
int search(struct Node* head, int value) {
    int index = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) return index;
        current = current->next;
        index++;
    }
    return -1;
}

// ---- Đếm số lượng node ----
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// ---- Đảo ngược danh sách ----
void reverseList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // di chuyen theo huong cu (da bi doi)
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// ---- In danh sách từ đầu đến cuối ----
void printForward(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ---- In danh sách từ cuối về đầu ----
void printBackward(struct Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// ---- Giải phóng toàn bộ danh sách ----
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
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

    printf("Danh sach (xuoi): ");
    printForward(head);
    printf("Danh sach (nguoc): ");
    printBackward(head);

    printf("So luong node: %d\n", countNodes(head));
    printf("Vi tri cua 20: %d\n", search(head, 20));

    deleteAt(&head, 2);
    printf("Sau khi xoa vi tri 2: ");
    printForward(head);

    deleteValue(&head, 5);
    printf("Sau khi xoa gia tri 5: ");
    printForward(head);

    deleteHead(&head);
    printf("Sau khi xoa dau: ");
    printForward(head);

    deleteTail(&head);
    printf("Sau khi xoa cuoi: ");
    printForward(head);

    insertTail(&head, 1);
    insertTail(&head, 2);
    insertTail(&head, 3);
    printf("Truoc khi dao nguoc: ");
    printForward(head);
    reverseList(&head);
    printf("Sau khi dao nguoc: ");
    printForward(head);

    freeList(&head);
    printf("Sau khi giai phong: ");
    printForward(head);

    return 0;
}