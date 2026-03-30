#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//push back
//rank base for loops
//size
//Iterator giống con trỏ, để lấy gioá trị thì dùng * để giải tham chiếu
//Insert: chèn  v.insert(v.begin(+2)) cèn ở vị tí thứ 2
//Erase: xoá v.erase(v.begin()+ 4); xoá ở vị trí thứ 4 
// v.pop_back(); xoá ở cuối
// assign(số phần tử, value);
// resize(n) thay đổi kích thước vector
//auto it = v.begin();


void hamKkhoidau();


int main(){
    int n; cin>>n;
    vector<int> v(n); 
    for(int i=0; i< n; i++){
        cin >> v[i];
    }
    for(int x : v){
        cout << x <<endl;
    }
    v.insert(v.begin()+2, 100);
    for(auto x : v) cout<< x<<" ";
    auto it = v.begin();
    auto x = 100;
    auto y = "@";

}





















void hamkhoidau(){
    // v.push_back(3); //{3}
    // v.push_back(2);//{3, 2}
    // v.push_back(4); //{3, 2, 4}
    // v.push_back(1); //{3, 2, 4, 1}
    // v.push_back(8);//{3, 2, 4, 1, 5}

    // cout <<v.size()<< endl;
    // cout << v[2]<< endl;
    // for(int i=0; i< v.size(); i++){
    //     cout <<v[i]<<endl;
    // }
//     for(int x : v){
//         cout << x << endl;
//     }
//     vector<int>::iterator it = v.begin();
//     cout << "Day la so da giai tham chieu " <<*it << endl; //*it là để giải tham chiếu
// 
}
