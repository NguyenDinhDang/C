#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* next;
};

struct DirectChainingHash {
    int size;
    struct Node** table;
};

struct DirectChainingHash* createDirectHash(int size) {
    struct DirectChainingHash* h = (struct DirectChainingHash*)malloc(sizeof(struct DirectChainingHash));
    h->size = size;
    h->table = (struct Node**)malloc(size * sizeof(struct Node*));
    for (int i = 0; i < size; i++) h->table[i] = NULL;
    return h;
}

int hashDirect(int key, int size) {
    int res = key % size;
    return (res < 0) ? res + size : res;
}

void insertDirect(struct DirectChainingHash* h, int key) {
    int index = hashDirect(key, h->size);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = h->table[index];
    h->table[index] = newNode;
}

int searchDirect(struct DirectChainingHash* h, int key) {
    int index = hashDirect(key, h->size);
    struct Node* curr = h->table[index];
    while (curr != NULL) {
        if (curr->key == key) return 1;
        curr = curr->next;
    }
    return 0;
}

void displayDirect(struct DirectChainingHash* h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d: ", i);
        struct Node* curr = h->table[i];
        while (curr != NULL) {
            printf("%d -> ", curr->key);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

void freeDirectHash(struct DirectChainingHash* h) {
    for (int i = 0; i < h->size; i++) {
        struct Node* curr = h->table[i];
        while (curr != NULL) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(h->table);
    free(h);
}

struct CoalescedNode {
    int key;
    int next;
    int is_empty;
};

struct CoalescedHash {
    int size;
    struct CoalescedNode* table;
    int cursor;
};

struct CoalescedHash* createCoalescedHash(int size) {
    struct CoalescedHash* h = (struct CoalescedHash*)malloc(sizeof(struct CoalescedHash));
    h->size = size;
    h->table = (struct CoalescedNode*)malloc(size * sizeof(struct CoalescedNode));
    for (int i = 0; i < size; i++) {
        h->table[i].key = -1;
        h->table[i].next = -1;
        h->table[i].is_empty = 1;
    }
    h->cursor = size - 1;
    return h;
}

int hashCoalesced(int key, int size) {
    int res = key % size;
    return (res < 0) ? res + size : res;
}

int insertCoalesced(struct CoalescedHash* h, int key) {
    int index = hashCoalesced(key, h->size);
    if (h->table[index].is_empty) {
        h->table[index].key = key;
        h->table[index].is_empty = 0;
        return 1;
    }
    while (h->cursor >= 0 && !h->table[h->cursor].is_empty) {
        h->cursor--;
    }
    if (h->cursor < 0) return 0;
    h->table[h->cursor].key = key;
    h->table[h->cursor].is_empty = 0;
    h->table[h->cursor].next = -1;
    int curr = index;
    while (h->table[curr].next != -1) {
        curr = h->table[curr].next;
    }
    h->table[curr].next = h->cursor;
    return 1;
}

int searchCoalesced(struct CoalescedHash* h, int key) {
    int index = hashCoalesced(key, h->size);
    if (h->table[index].is_empty) return 0;
    int curr = index;
    while (curr != -1) {
        if (h->table[curr].key == key) return 1;
        curr = h->table[curr].next;
    }
    return 0;
}

void displayCoalesced(struct CoalescedHash* h) {
    for (int i = 0; i < h->size; i++) {
        if (h->table[i].is_empty) {
            printf("%d\tEmpty\t%d\n", i, h->table[i].next);
        } else {
            printf("%d\t%d\t%d\n", i, h->table[i].key, h->table[i].next);
        }
    }
}

void freeCoalescedHash(struct CoalescedHash* h) {
    free(h->table);
    free(h);
}

int main() {
    int size = 7;

    struct DirectChainingHash* dc = createDirectHash(size);
    insertDirect(dc, 12);
    insertDirect(dc, 19);
    insertDirect(dc, 26);
    insertDirect(dc, 10);
    displayDirect(dc);
    printf("%d\n", searchDirect(dc, 19));
    printf("%d\n", searchDirect(dc, 99));
    freeDirectHash(dc);

    printf("\n");

    struct CoalescedHash* ch = createCoalescedHash(size);
    insertCoalesced(ch, 12);
    insertCoalesced(ch, 19);
    insertCoalesced(ch, 26);
    insertCoalesced(ch, 10);
    displayCoalesced(ch);
    printf("%d\n", searchCoalesced(ch, 26));
    printf("%d\n", searchCoalesced(ch, 100));
    freeCoalescedHash(ch);

    return 0;
}