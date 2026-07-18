#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* pNext;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void InitStack(Stack *s) {
    s->top = NULL;
}

int IsStackEmpty(Stack s) {
    return s.top == NULL ? 1 : 0;
}

void Push(Stack *s, char x) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p != NULL) {
        p->data = x;
        p->pNext = s->top;
        s->top = p;
    }
}

char Pop(Stack *s) {
    if (!IsStackEmpty(*s)) {
        Node* p = s->top;
        char x = p->data;
        s->top = p->pNext;
        free(p);
        return x;
    }
    return '\0';
}

void PrintStack(Stack s) {
    Node* p = s.top;
    if (p == NULL) {
        printf("(Trong)\n");
        return;
    }
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

void GiaiPhongStack(Stack *s) {
    while (!IsStackEmpty(*s)) {
        Pop(s);
    }
}

typedef struct QNode {
    char data;
    struct QNode* pNext;
} QNode;

typedef struct Queue {
    QNode* pHead;
    QNode* pTail;
} Queue;

void InitQueue(Queue *q) {
    q->pHead = NULL;
    q->pTail = NULL;
}

int IsQueueEmpty(Queue q) {
    return q.pHead == NULL ? 1 : 0;
}

void Enqueue(Queue *q, char x) {
    QNode* p = (QNode*)malloc(sizeof(QNode));
    if (p != NULL) {
        p->data = x;
        p->pNext = NULL;

        if (IsQueueEmpty(*q)) {
            q->pHead = q->pTail = p;
        } else {
            q->pTail->pNext = p;
            q->pTail = p;
        }
    }
}

char Dequeue(Queue *q) {
    if (!IsQueueEmpty(*q)) {
        QNode* p = q->pHead;
        char x = p->data;
        q->pHead = q->pHead->pNext;
        if (q->pHead == NULL) {
            q->pTail = NULL;
        }
        free(p);
        return x;
    }
    return '\0';
}

void PrintQueue(Queue q) {
    QNode* p = q.pHead;
    if (p == NULL) {
        printf("(Trong)\n");
        return;
    }
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

void GiaiPhongQueue(Queue *q) {
    while (!IsQueueEmpty(*q)) {
        Dequeue(q);
    }
}

int main() {
    char sequence[] = "EAS*Y**QUE***ST***I*ON";
    int length = strlen(sequence);
    int luachon;

    do {
        printf("\n MENU \n");
        printf("1.STACK\n");
        printf("2. QUEUE\n");
        printf("0. Thoat chuong trinh\n");
        printf("============================================\n");
        printf("Nhap lua chon cua ban (0-2): ");
        scanf("%d", &luachon);

        switch (luachon) {
            case 1: {
                Stack s;
                InitStack(&s);

                printf("\nSTACK\n");
                printf("Chuoi ky tu xu ly: %s\n", sequence);
                printf("Ky tu xuat hien tren man hinh: ");

                for (int i = 0; i < length; i++) {
                    char c = sequence[i];
                    if (c == '*') {
                        char popped = Pop(&s);
                        if (popped != '\0') {
                            printf("%c", popped);
                        }
                    } else {
                        Push(&s, c);
                    }
                }

                printf("\nNoi dung Stack con lai (Trong binh): ");
                PrintStack(s);
                
                // Don dep bo nho sau khi dung xong
                GiaiPhongStack(&s); 
                break;
            }
            case 2: {
                Queue q;
                InitQueue(&q);

                printf("\nQUEUE\n");
                printf("Chuoi ky tu xu ly: %s\n", sequence);
                printf("Ky tu xuat hien tren man hinh: ");

                for (int i = 0; i < length; i++) {
                    char c = sequence[i];
                    if (c == '*') {
                        char dequeued = Dequeue(&q);
                        if (dequeued != '\0') {
                            printf("%c", dequeued);
                        }
                    } else {
                        Enqueue(&q, c);
                    }
                }

                printf("\nNoi dung Queue con lai (Trong ong): ");
                PrintQueue(q);
                
                GiaiPhongQueue(&q);
                break;
            }
            case 0:
                printf("\nDa thoat chuong trinh\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long nhap lai tu 0 den 2.\n");
                break;
        }
    } while (luachon != 0);

    return 0;
}