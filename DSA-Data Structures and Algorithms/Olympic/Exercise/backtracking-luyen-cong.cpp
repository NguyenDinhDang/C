#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void backtracking(int n, int pos, int k, int count, vector<int> &a) {
    if(n == pos) {
        if (count == k) {
            for(int i = 0; i < n; i++) {
                cout << a[i];
            }
            cout << endl;
        }
        return;
    }

    a[pos] = 0;
    backtracking(n, pos + 1, k, count, a);
    a[pos] = 1;
    backtracking(n, pos + 1, k, count + 1, a);
}



int main () {
    int n, k, count = 0;
    cin >> n >> k;

    vector<int> a(n);

    backtracking(n, 0, k, count, a);
    return 0;
}

