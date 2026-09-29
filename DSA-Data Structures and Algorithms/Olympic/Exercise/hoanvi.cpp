#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Hình dung n là một cái giỏ 
n sẽ chọn phần tử đầu tiên vào giỏ (i)
-> sau đó đi xuống tiếp để chọn thêm phần tử vào giỏ 
-> Khi chọn xong thì bỏ phần tử đó ra ngoài giỏ để có thể chọn tiếp 
==> CHỌN -> ĐI SÂU -> BỎ CHỌN -> CHỌN TIẾP
*/

void printResult (vector<long long> &a, int n) {
    for(int i =0; i<n;i++){
        cout << a[i];
    }
    cout << endl;
}

void hoanvi (int n, vector<long long> &a, vector<bool> &used) {
    if(a.size() == n) {  //Hàm xác định, nếu đủ 3 phần tử thì dừng lại
        printResult(a, n);
        return; // Đệ quy - Backtracking
    }

    for(int i = 1; i<=n; i++) {
        if(used[i]){
            continue;
        }

        a.push_back(i); // CHỌN
        used[i] = true;

        hoanvi(n, a, used); // ĐI SÂU

        a.pop_back(); // BỎ CHỌN
        used[i] = false; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >>n;

    vector<long long> a;
    vector<bool> used(n+1, false);
    hoanvi(n, a, used);
    return 0;
}