#include <stdio.h>

#define NULLKEY -1
#define M 10
#define TRUE 1
#define FALSE 0
#define MAX_NAME 50

struct node {
    int key;
    char name[MAX_NAME];
};

struct node hashtable[M];
int N;

int hb(int k) {
    int tong = 0;
    int tmp = (k < 0) ? -k : k;
    while (tmp > 0) {
        tong += tmp % 10;
        tmp /= 10;
    }
    return tong % M;
}

int hp(int k) {
    return 9 - (k % 5);
}

void initialize() {
    int i;
    for (i = 0; i < M; i++) {
        hashtable[i].key = NULLKEY;
        hashtable[i].name[0] = '\0'; // Xóa dữ liệu rác của chuỗi tên
    }
    N = 0;
}

int empty() {
    return (N == 0 ? TRUE : FALSE);
}

int full() {
    return (N == M ? TRUE : FALSE);  //Kiểm tra full chưa
}

int search(int x) {
    int i, j, dem;
    i = hb(x);
    j = hp(x);
    dem = 0;
    while ((hashtable[i].key != x && hashtable[i].key != NULLKEY) && dem < M) {
        i = (i + j) % M;
        dem = dem + 1;
    }
    if (hashtable[i].key == x)
        return i;
    else
        return -1;
}

void insert(struct node a) {
    int i, j, dem;
    if (full()) {
        printf("Bang bam bi day\n");
        return;
    }
    if (search(a.key) != -1) {
        printf("Da co khoa nay trong bang bam\n");
        return;
    }
    i = hb(a.key);
    j = hp(a.key);
    dem = 1;
    while (hashtable[i].key != NULLKEY && dem < M) {
        i = (i + j) % M;
        dem = dem + 1;
    }
    if (hashtable[i].key == NULLKEY) {
        hashtable[i] = a;
        N = N + 1;
    }
}

void input(struct node a[], int n) {
    int i, j, c;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i].key);
        while ((c = getchar()) != '\n' && c != EOF);
        fgets(a[i].name, MAX_NAME, stdin);
        for (j = 0; j < MAX_NAME; j++) {
            if (a[i].name[j] == '\n') {
                a[i].name[j] = '\0';
                break;
            }
        }
    }
}

void output(struct node a[], int n) {
    int i;
    printf("Vi tri:\t");
    for (i = 0; i < n; i++) printf("%d\t", i);
    printf("\nKhoa:\t");
    for (i = 0; i < n; i++) {
        if (a[i].key == NULLKEY)
            printf("null\t");
        else
            printf("%d\t", a[i].key);
    }
    printf("\nHo ten:\t");
    for (i = 0; i < n; i++) printf("%s\t", a[i].name);
    printf("\n");
}

int main() {
    int n, i;
    struct node data[M]; 
    scanf("%d", &n);
    input(data, n);
    output(data, n);
    initialize();
    for (i = 0; i < n; i++) {
        insert(data[i]);
    }
    output(hashtable, M);
    return 0;
}