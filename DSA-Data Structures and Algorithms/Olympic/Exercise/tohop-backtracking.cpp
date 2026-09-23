#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void tohop (int n, int k, int start, vector<int> &a) {
    for(int i = start; i<=n; i++) {
        a.push_back(i); // them phan tu vao cuối a hay CHỌN 
        if(a.size() == k) { // neu kich thuoc cua a bang k thi in ra
            for(int j = 0; j<k; j++) {
                cout << a[j] << " ";
            }
            cout << endl;
        } else {
            tohop(n, k, i+1, a); // goi de quy CHỌN tiep
        }
        a.pop_back(); // xoa phan tu cuoi a hay BỎ CHỌN
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> a;
    tohop(n, k, 1, a);
    
    return 0;
}