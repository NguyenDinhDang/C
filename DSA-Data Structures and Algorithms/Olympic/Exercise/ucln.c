#include <stdio.h>

long long gcd(long long a, long long b) {
    long long temp;
    if(b==0) return a;
    else {
        temp = a%b;
    }
    return gcd(b, temp);
}

void testGcd() {
    long long a = 252;
    long long b = 105;
    printf("%lld",gcd(a, b));
}

int main() {
    testGcd();
}