#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inArr(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
}

void outArr(int arr[], int n) {
    
    long long max = arr[0];
    long long min = arr[0];
    
    for(int i = 0; i<n;i++){
        if(arr[i] > max) {
            max = arr[i];
        }
        else if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    printf("%lld %lld", max, min);
}


int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(int));
    
    inArr(arr, n);
    outArr(arr, n);
    
    free(arr);
    arr = NULL;
    return 0;
}
