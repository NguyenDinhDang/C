#include <stdio.h>

bool isPrime(int n ) {
    if(n <2 ) return false;
    for (int i =2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    if(isPrime(n)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}