#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct maytinh {
    int maso;  
    char loaiCPU[40];
    int ram;
    int dungluong;
} maytinh;

typedef struct DNode {
    maytinh Info;
    struct DNode* pPre;  
    struct DNode* pNext; 
} DNode;

typedef struct DList {
    DNode* pHead; 
    DNode* pTail; 
} DList;

DNode* GetNode(maytinh x) {
    DNode *p = (DNode*)malloc(sizeof(DNode));
    if (p == NULL) {
        printf("Khong du bo nho!");
        exit(1);
    }
    p->Info = x;
    p->pPre = NULL;
    p->pNext = NULL;
    return p;
}

void Init(DList *l) {
    l->pHead = l->pTail = NULL;
}

void AddFirst(DList *l, DNode* new_ele) {
    if (l->pHead == NULL) { 
        l->pHead = new_ele;
        l->pTail = l->pHead;
    } else {
        new_ele->pNext = l->pHead;
        l->pHead->pPre = new_ele;
        l->pHead = new_ele;
    }
}

void printList(DList l) {
    DNode* p = l.pHead;
    if (p == NULL) {
        printf("\nDanh sach may tinh trong!\n");
        return;
    }

    printf("\n%-10s | %-20s | %-15s | %-20s\n", "Ma so", "Loai CPU", "RAM (GB)", "O cung (GB)");
    printf("--------------------------------------------------------------------------\n");
    while (p != NULL) {
        printf("%-10d | %-20s | %-15d | %-20d\n",
               p->Info.maso,
               p->Info.loaiCPU,
               p->Info.ram,
               p->Info.dungluong);
        p = p->pNext;
    }
}

void FreeList(DList *l) {
    DNode* p = l->pHead;
    while (p != NULL) {
        DNode* temp = p;
        p = p->pNext;
        free(temp);
    }
    l->pHead = l->pTail = NULL;
}

int main() {
    int n;
    maytinh x;
    DList l;
    Init(&l);
    
    printf("Nhap so may tinh ban muon nhap du lieu: ");
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        printf("\n--- Nhap thong tin may tinh %d ---\n", i);
        printf("Nhap ma so may tinh: ");
        scanf("%d", &x.maso);

        getchar(); 
        printf("Loai CPU (Vi du: Core i5, Xeon...): ");
        fgets(x.loaiCPU, sizeof(x.loaiCPU), stdin);

        size_t len = strlen(x.loaiCPU);
        if (len > 0 && x.loaiCPU[len-1] == '\n') {
            x.loaiCPU[len-1] = '\0';
        }

        printf("Dung luong RAM (GB): ");
        scanf("%d", &x.ram);
        
        printf("Dung luong o cung (GB): ");
        scanf("%d", &x.dungluong);
        
        DNode* p = GetNode(x);
        AddFirst(&l, p);
    }
    
    printList(l);
    FreeList(&l); 
    
    return 0;
}