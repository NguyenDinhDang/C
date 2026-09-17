#include <stdio.h>

void inputArr(int arr[], int n) {
    for ( int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
}

void outputArr(int arr[], int n) {
    for ( int i = 0; i<n; i++) {
        printf("%d", &arr[i]);
    }
}

int countingArr(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0 ; i<n ; i ++) {
        if(arr[i] == x) {
            count += 1;
        }
    }
    return count;
}

int main() {
    int n, x;
    scanf("%d%d",&n,&x);
    int *arr = (int*)malloc(n*sizeof(int));
    inputArr(arr, n);
    printf("%d", countingArr(arr, n, x));
    return 0;
}
