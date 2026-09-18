#include <stdio.h>

void daoNguoc(long long n) {
    if (n == 0) {
        printf("0");
        return;
    }
    if (n < 0) {
        printf("-");
        n = -n;
    }
    while (n > 0) {
        printf("%lld", n % 10);
        n = n / 10;
    }
}

int main() {
    long long n;
    scanf("%lld", &n);
    daoNguoc(n);
    return 0;
}