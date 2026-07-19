#include <stdio.h>
#include <stdlib.h>

// ==================== SINGLY LINKED LIST - FULL FUNCTIONS ====================

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
    newNode->next = *head;
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
    current->next = newNode;
}

// ---- Xóa đầu ----
void deleteHead(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
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
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// ---- Xóa tại vị trí ----
void deleteAt(struct Node** head, int position) {
    if (*head == NULL) return;
    if (position <= 0) {
        deleteHead(head);
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    if (current->next == NULL) return;
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// ---- Xóa theo giá trị (xóa node đầu tiên có data == value) ----
void deleteValue(struct Node** head, int value) {
    if (*head == NULL) return;
    if ((*head)->data == value) {
        deleteHead(head);
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    if (current->next == NULL) return; // khong tim thay
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// ---- Tìm kiếm giá trị, trả về vị trí (index) hoặc -1 nếu không có ----
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

// ---- Tìm giá trị lớn nhất ----
int findMax(struct Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        exit(1);
    }
    int max = head->data;
    struct Node* current = head->next;
    while (current != NULL) {
        if (current->data > max) max = current->data;
        current = current->next;
    }
    return max;
}

// ---- Tìm giá trị nhỏ nhất ----
int findMin(struct Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        exit(1);
    }
    int min = head->data;
    struct Node* current = head->next;
    while (current != NULL) {
        if (current->data < min) min = current->data;
        current = current->next;
    }
    return min;
}

// ---- Tính tổng các phần tử ----
int sumList(struct Node* head) {
    int sum = 0;
    struct Node* current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

// ---- Đảo ngược danh sách (reverse) ----
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// ---- Sắp xếp tăng dần (bubble sort - đổi data, không đổi con trỏ) ----
void sortAscending(struct Node* head) {
    if (head == NULL) return;
    int swapped;
    struct Node* ptr1;
    struct Node* lastNode = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lastNode) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lastNode = ptr1;
    } while (swapped);
}

// ---- In danh sách ----
void printList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
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

    printf("Danh sach ban dau: ");
    printList(head);

    printf("So luong node: %d\n", countNodes(head));
    printf("Tong cac phan tu: %d\n", sumList(head));
    printf("Gia tri lon nhat: %d\n", findMax(head));
    printf("Gia tri nho nhat: %d\n", findMin(head));
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

    insertTail(&head, 1);
    insertTail(&head, 99);
    insertTail(&head, 3);
    printf("Truoc khi sap xep: ");
    printList(head);
    sortAscending(head);
    printf("Sau khi sap xep tang dan: ");
    printList(head);

    reverseList(&head);
    printf("Sau khi dao nguoc: ");
    printList(head);

    deleteTail(&head);
    printf("Sau khi xoa cuoi: ");
    printList(head);

    freeList(&head);
    printf("Sau khi giai phong: ");
    printList(head);

    return 0;
}