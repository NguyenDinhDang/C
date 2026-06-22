#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    char Name[50];
    float Weight, Value, Price;
    int solution;
} Object;

typedef Object listObject[MAX_SIZE];

void swap(Object *a, Object *b) {
    Object temp = *a;
    *a = *b;
    *b = temp;
}

void interchangeSort(listObject list, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (list[i].Price < list[j].Price) {
                swap(&list[i], &list[j]);
            }
        }
    }
}

int choose(float a, float b) {
    return (int)(a/b);
}

void greedy(listObject list, float Weight, int n){
    interchangeSort(list, n);
    for(int i=0; i<n; i++){
        if (Weight <= 0) break;
        list[i].solution = choose(Weight, list[i].Weight);
        Weight += -((float)list[i].solution * list[i].Weight);
    }
}

int main() {
    int n;
    float W;
    scanf("%d %f", &n, &W);

    listObject list;
    for (int i = 0; i < n; i++) {
        int loai;
        scanf("%d %f %f", &loai, &list[i].Weight, &list[i].Value);
        list[i].Price = list[i].Value / list[i].Weight;
    }
    greedy(list, W, n);
    float total_value = 0;
    for (int i = 0; i < n; i++) {
        total_value += (float)list[i].solution * list[i].Value;
    }
    printf("%.0f\n", total_value);
    return 0;
}