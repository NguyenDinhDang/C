#include <bits/stdc++.h>

using namespace std;

void printResult (vector<int> &a, int n) {
    for(int i =0; i<n;i++){
        cout << a[i];
    }
    cout << endl;
}

void nhiphan (int n, int pos, vector<int> &a) {
    if(pos == n){  // Điều kiện dừng khi đã xét hết các vị trí
        printResult(a, n);
        return ; // Backtrack: quay lại để xét các khả năng khác
    }
    
    a[pos] = 0; // Gán giá trị 0 cho vị trí hiện tại và tiếp tục với vị trí tiếp theo
    nhiphan(n, pos + 1, a); // Gọi đệ quy để xét vị trí tiếp theo
    
    a[pos] = 1; // Gán giá trị 1 cho vị trí hiện tại và tiếp tục với vị trí tiếp theo
    nhiphan(n, pos +1, a); // Gọi đệ quy để xét vị trí tiếp theo
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >>n;
    vector<int> a(n);
    
    nhiphan(n, 0, a); 
    return 0;
}