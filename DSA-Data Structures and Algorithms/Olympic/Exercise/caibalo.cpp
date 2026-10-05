#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, W, gi, vi, loaiDoVat;
    cin >> n >> W;

    vector<tuple<int, int, int>> items(n);
    for (int i = 0; i < n; i++) {
        cin >> gi >> vi >> loaiDoVat;
        items[i] = {gi, vi, loaiDoVat};
    }

    return 0;
}