#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

using ll = long long;

int main(){
    int n;cin >> n;
    int a[10000]; 
    for(int i=0; i<n;i++){
        cin >>a[i];
    }
    sort(a, a+n, greater<int>());//O(NlogN)
    for(int x : a) cout<<x<<endl;
}

