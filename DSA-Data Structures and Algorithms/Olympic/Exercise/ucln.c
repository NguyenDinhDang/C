#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b) {
    long long temp;
    if(b==0) return a;
    else {
        temp = a%b;
    }
    return gcd(b, temp);
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return llabs((a / gcd(a, b)) * b);
}

void test() {
    long long a = 252;
    long long b = 105;
    printf("gcd: %lld\n",gcd(a, b));
    printf("lcm: %lld\n", lcm(a, b));
}

int main() {
    test();
}