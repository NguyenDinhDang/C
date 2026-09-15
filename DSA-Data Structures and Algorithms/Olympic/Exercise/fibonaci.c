#include <stdio.h>

//F(n) = F(n-1) + F(n-2), n>= 2
//F(4) = F(3) + F(2) = 2 + 1 = 3
//F(3) = F(2) + F(1) = 2
//F(2) = F(1) + F(0) = 1

int fibonaci (int n) {
    if(n == 0) return 0;
    else if( n == 1) return 1;
    else return fibonaci(n-1) + fibonaci(n-2);
}

void testFib(){
    int n = 4;
    fibonaci(n);
    printf("%d", fibonaci(n));
}

int main () {
    testFib();
}