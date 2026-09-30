#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
Để tối ưu hơn tôi sẽ dùng top-down 
Quy hoạch động 
ý tưởng: tạo 1 mảng để lưu các phần tử đã tính 
-> sau khi tính xong sẽ lưu vào mảng 
-> trước khi bước vào đệ quy sẽ hỏi: Tính chưa |-> Chưa -> tính -> lưu
                                               |-> tính rồi -> lấy ra 
*/

long long fibonaci(int n, vector<long long> &a) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    long long result;
    if(a[n] == -1) {
        result = fibonaci(n-1, a) + fibonaci(n-2, a);
        a[n] = result; 
    } else {
        result = a[n];
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> a(n+1, -1);

    cout << fibonaci(n,a ) <<endl;
    return 0;
}