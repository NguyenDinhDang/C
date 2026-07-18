#include <stdio.h>

void outputArr(int n, int a[]);
void swap(int *a, int *b);
void quickSort(int a[], int n, int left, int right);
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n);
void interChangeSort(int a[], int n);
void heapSort(int a[], int n);
void shift(int a[], int l, int r);
void createHeap(int a[], int n);
int main() {
    int n = 8;
    int left = 1;
    int right = n;

    printf("\n Quick Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        quickSort(arr , n, left, right);
    }
	
    printf("\n Selection Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        selectionSort(arr, n);
    }
    
    printf("\n Heap Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        heapSort(arr, n);
    }

    printf("\n Bubble Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        bubbleSort(arr, n);
    }

    printf("\n Insertion Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        insertionSort(arr, n);
    }

    printf("\n Interchange Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
    	interChangeSort(arr, n);
    }
    
	printf("--- Chuc Thay Mot Ngay Vui ---");
    return 0;
}

void inputArr(int a, int arr[]) {
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr[i]);
    }
}

void outputArr(int n, int a[]) {
    for (int i = 1; i <= n; i++) { 
        printf("%d ", a[i]);
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void linearSearch(int a, int arr[], int key) {
    for (int i = 0; i < a; i++) {
        if (arr[i] == key) printf("Found in Array[%d]\n", i + 1);
        else printf("Not found in Array[%d]\n", i + 1);
    }
}

void quickSort(int arr[], int n, int left, int right) {
    int i, j, x;
    if (left >= right) return;
    x = arr[(left + right) / 2];
    i = left; j = right;
    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    quickSort(arr, n, left, j);
    quickSort(arr, n, i, right);
    outputArr(n, arr);
    printf("\n");
}

void selectionSort(int arr[], int n) {
    int min;
    for (int i = 1; i < n; i++) { 
        min = i;
        for (int j = i + 1; j <= n; j++) { 
            if (arr[j] < arr[min]) min = j;
        }
        swap(&arr[min], &arr[i]);
        printf("Buoc %d: ", i);
        outputArr(n, arr);
        printf("\n");
    }
}

void insertionSort(int a[], int n) {
    int i, j, x;
    for (i = 2; i <= n; i++) { 
        x = a[i];
        j = i - 1;
        while (j >= 1 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
        printf("Buoc %d: ", i - 1);
        outputArr(n, a);
        printf("\n");
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 1; i < n; i++) { 
        for (int j = n; j > i; j--) { 
            if (arr[j] < arr[j - 1]) swap(&arr[j], &arr[j - 1]);
        }
        printf("Buoc %d: ", i);
        outputArr(n, arr);
        printf("\n");
    }
}

void interChangeSort(int a[], int n) {
    for (int i = 1; i < n; i++) { 
        for (int j = i + 1; j <= n; j++) { 
            if (a[j] < a[i]) swap(&a[i], &a[j]);
        }
        printf("Buoc %d: ", i);
        outputArr(n, a);
        printf("\n");
    }
}
void shift(int a[], int l, int r) {
    int i = l, j = 2 * i;
    int x = a[i];
    while (j <= r) {
        if (j < r && a[j] < a[j + 1]) j++;
        if (a[j] <= x) break;
        a[i] = a[j];
        i = j; j = 2 * i;
    }
    a[i] = x;
}

void createHeap(int a[], int n) {
    for (int l = n / 2; l >= 1; l--) shift(a, l, n);
}

void heapSort(int a[], int n) {
    createHeap(a, n);
    int r = n;
    int step = 1;
    while (r > 1) {
        swap(&a[1], &a[r]);
        r--;
        shift(a, 1, r);
        printf("Buoc %d: ", step++);
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}