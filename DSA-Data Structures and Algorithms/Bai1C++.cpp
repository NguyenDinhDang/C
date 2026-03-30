#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//push back
//rank base for loops

int main(){
    vector<int> v; //{}
    v.push_back(3); //{3}
    v.push_back(2);//{3, 2}
    v.push_back(4); //{3, 2, 4}
    v.push_back(1); //{3, 2, 4, 1}
    v.push_back(8);//{3, 2, 4, 1, 5}

    // cout <<v.size()<< endl;
    // cout << v[2]<< endl;
    // for(int i=0; i< v.size(); i++){
    //     cout <<v[i]<<endl;
    // }
    for(int x : v){
        cout << x <<' ';
    }
    
}

