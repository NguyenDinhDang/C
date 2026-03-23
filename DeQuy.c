#include "stdio.h"

int factorial(int n){
    for(int i=0; i<n;i++){
        if(i==0 || i ==1) return 1;
    }
    return factorial(n-1)*n;
}

int main(){
    int n=5;
    printf("De quy cua n = %d",factorial(n));

    return 0;
}