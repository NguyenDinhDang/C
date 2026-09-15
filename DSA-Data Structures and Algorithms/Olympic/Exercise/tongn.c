#include <stdio.h>

int main() {
    long long n;
    long long tong = 0;

    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        tong += i;
        printf("%lld\n", tong);
    }
    printf("%lld", tong);
    return 0;
}