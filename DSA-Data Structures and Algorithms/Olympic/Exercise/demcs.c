#include <stdio.h>
long long demCS(long long n);

long long demCS(long long n) {
    if(n == 0 ) return 1;
    else if(n<0) {
        n = -n;
    }
    int count=0;
    while(n >0) {
        count++;
        n = n/10;
    }
    return count;
}



int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld", demCS(n));
    return 0;
}