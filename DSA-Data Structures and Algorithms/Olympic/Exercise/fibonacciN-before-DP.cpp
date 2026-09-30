#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int fibonaci(int n) {
    if(n ==0 ) return 0;
    if(n == 1) return 1;
    return fibonaci(n-1) + fibonaci(n - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    cout << fibonaci(n) <<endl;
    return 0;
}