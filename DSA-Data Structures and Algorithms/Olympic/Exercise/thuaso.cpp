#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;

void findPrime (int n) {
    for(int i=2; i<= sqrt(n); i++) {
        while(n%i==0) { 
            cout << i << " ";
            n/=i;
        }
    }
    if(n>1) {
        cout << n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >>n;
    findPrime(n);

    return 0;
}