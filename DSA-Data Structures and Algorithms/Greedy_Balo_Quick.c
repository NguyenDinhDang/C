#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int Name;
    int Weight, Value, Price;
    int solution;
} Object;

typedef Object listObject[MAX_SIZE];

void swap(Object *a, Object *b) {
    Object temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(listObject list, int left, int right) {
    if (left >= right) return;
    
    Object pivot = list[(left + right) / 2];
    int i = left;
    int j = right;
    
    while (i <= j) {
        while (list[i].Value * pivot.Weight > pivot.Value * list[i].Weight) i++;
        while (list[j].Value * pivot.Weight < pivot.Value * list[j].Weight) j--;
        
        if (i <= j) {
            swap(&list[i], &list[j]);
            i++;
            j--;
        }
    }
    
    quickSort(list, left, j);
    quickSort(list, i, right);
}

int choose(int a, int b) {
    return a / b;
}

void greedy(listObject list, int Weight, int n){
    for (int i = 0; i < n; i++) {
        list[i].solution = 0;
    }
    
    quickSort(list, 0, n - 1);
    
    for(int i = 0; i < n; i++){
        if (Weight <= 0) break;
        list[i].solution = choose(Weight, list[i].Weight);
        Weight += -(list[i].solution * list[i].Weight);
    }
}

int main() {
    int n;
    int W;
    (void)scanf("%d %d", &n, &W);

    listObject list;
    for (int i = 0; i < n; i++) {
        (void)scanf("%d %d %d", &list[i].Name, &list[i].Weight, &list[i].Value);
        list[i].Price = 0;
    }
    
    greedy(list, W, n);
    
    int total_value = 0;
    for (int i = 0; i < n; i++) {
        total_value += list[i].solution * list[i].Value;
    }
    printf("%d\n", total_value);
    return 0;
}