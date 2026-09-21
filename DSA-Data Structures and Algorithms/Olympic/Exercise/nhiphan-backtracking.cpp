#include <bits/stdc++.h>

using namespace std;

void printResult (vector<int> &a, int n) {
    for(int i =0; i<n;i++){
        cout << a[i];
    }
    cout << endl;
}

void nhiphan (int n, int pos, vector<int> &a) {
    if(pos == n){ 
        printResult(a, n);
        return ;
    }
    
    a[pos] = 0;
    nhiphan(n, pos + 1, a);
    
    a[pos] = 1;
    nhiphan(n, pos +1, a);
    
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