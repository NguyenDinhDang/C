#include <stdio.h>

void swap(int *a, int *b);
void selectionSort(int arr[], int n);
void printArray(int arr[], int n);
void findMaxMin(int arr[], int n);
void test();

void test() {
    int arr[] = {1, 4, 2, 8, 5};
    int n = 5;
    selectionSort(arr, n);
    printArray(arr, n);
    findMaxMin(arr, n);
}

void findMaxMin(int arr[], int n) {
    printf("Min: %d\n", arr[0]);
    printf("Max: %d\n", arr[n-1]);
}

void printArray(int arr[], int n) {
    for( int i =0; i<n; i++) {
	    printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for( int i =0; i<n; i++) {
	int minIndex = i;
        for( int j = i+1; j< n; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        swap(&arr[minIndex], &arr[i]);
        }
    }
}

int main() {
   test();
   return 0;
}

