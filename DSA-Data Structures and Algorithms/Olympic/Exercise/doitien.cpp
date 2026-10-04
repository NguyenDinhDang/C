#include <bits/stdc++.h>
using namespace std;

int doitien(int sotien, vector<int> dsTien) {
    int count = 0;

    for (int i = 0; i < dsTien.size(); i++) {
        // Tham lam: Dùng mệnh giá lớn nhất có thể nhiều lần nhất có thể
        while (sotien >= dsTien[i]) { // Nếu số tiền còn lại lớn hơn hoặc bằng mệnh giá hiện tại
            sotien -= dsTien[i]; // Trừ mệnh giá hiện tại khỏi số tiền còn lại 
            count++; // Tăng số lượng tờ tiền đã sử dụng
        }
    }
    return count;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int tienDu = 500000 - n;

    
    vector<int> dsTien = {100000, 50000, 10000, 5000, 1000};
    cout << doitien(tienDu, dsTien);
    
    return 0;
}