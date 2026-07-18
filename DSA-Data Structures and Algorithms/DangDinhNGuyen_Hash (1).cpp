#include <stdio.h>

#define NULLKEY -1
#define M 10
#define TRUE 1
#define FALSE 0

// Khai bao cau truc mot nut cua bang bam
struct node {
    int key; // khoa cua nut tren bang bam
};

// Khai bao bang bam co M nut va bien dem N
struct node hashtable[M];
int N; // So luong phan tu hien tai 

int hashfunc(int key) {
    return (key % M);
}

void initialize() {
    int i;
    for (i = 0; i < M; i++)
        hashtable[i].key = NULLKEY;
    N = 0;
}

int empty() {
    return (N == 0 ? TRUE : FALSE);
}

int full() {
    return (N == M ? 1 : -1); 
}

int search(int k) {
    int i;
    i = hashfunc(k);
    while (hashtable[i].key != k && hashtable[i].key != NULLKEY) {
        i = i + 1;
        if (i >= M) i = i - M;
    }
    if (hashtable[i].key == k) return (i);
    else return (M);
}

int insert(int k) {
    int i;
    if (full() == 1) {
        printf("\n-> Full khong them nut co khoa %d duoc!", k);
        return -1;
    }
    if (search(k) < M) {
        printf("\n-> Da co khoa %d ", k);
        return (M);
    }
    i = hashfunc(k);
    while (hashtable[i].key != NULLKEY) {
        // Bam lai (theo phuong phap do tuyen tinh)
        i++;
        if (i >= M) i = i - M;
    }
    hashtable[i].key = k;
    N = N + 1;
    return (i);
}

// Ham bo tro de in toan bo bang bam ra man hinh cho de quan sat
void xuatmang() {
    for (int i = 0; i < M; i++) {
        if (hashtable[i].key == NULLKEY) {
            printf("\nSlot [%d]: %d", i, NULLKEY);
        } else {
            printf("\nSlot [%d]: %d", i, hashtable[i].key);
        }
    }
}

int main() {
    initialize();
    insert(12); // 12 % 10 = slot 2
    insert(22); // 22 % 10 = slot 2 -> Dung do -> Do tuyen tinh xuong slot 3
    insert(45); // 45 % 10 = slot 5
    insert(32); // 32 % 10 = slot 2 -> Dung do liên tiep -> Xuong slot 4
    insert(12); // Thu them trung khoa 12
    
    // In bang bam 
  	 xuatmang();

    //Search
    int keyToSearch = 32;
    int pos = search(keyToSearch);
    if (pos < M) {
        printf("\nTim thay khoa %d tai [%d]", keyToSearch, pos);
    } else {
        printf("\nKhong tim thay khoa %d", keyToSearch);
	}
    keyToSearch = 99; // Khoa khong ton tai
    pos = search(keyToSearch);
    if (pos < M) {
        printf("\nTim thay khoa %d tai [%d]", keyToSearch, pos);
    } else {
        printf("\nKhong tim thay khoa %d", keyToSearch);
    }
    printf("\n");
    return 0;
}