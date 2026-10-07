#include <bits/stdc++.h>
using namespace std;

struct Item {
    int gi, vi, loaiDoVat;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, W, gi, vi, loaiDoVat;
    cin >> n >> W;

    vector<Item> items(n);
    for(int i = 0; i < n; i++) {
        cin >> gi >> vi >> loaiDoVat;
        items[i] = {gi, vi, loaiDoVat};
    }
    for(int i = 0; i < n; i++) {
        cout << items[i].gi << " " << items[i].vi << " " << items[i].loaiDoVat << "\n";
    }
    return 0;
}