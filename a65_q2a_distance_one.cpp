#include<bits/stdc++.h>
using namespace std;
int r = 100000007;
int k;

int main() {
    int n;
    cin >> n >> k;
    vector<vector<int> > v;
    v.resize(n);
    for(int i=0;i<n;i++) {
        v[i].resize(2);
        v[i][0] = 0;
        v[i][1] = 0;
    }
    v[0][0] = 1;
    v[0][1] = 1;
    for(int i=1;i<n;i++) {
        v[i][0] = (v[i-1][0] + v[i-1][1])%r;
        if(i-k>=0) v[i][1] = (v[i-k][1] + v[i-k][0])%r;
        else v[i][1] = 1;
    }
    // for(int i=0;i<n;i++) {
    //     cout << "i=" << i << ", v[0]=" << v[i][0] << ", v[1]=" << v[i][1] << "\n";
    // }
    cout << (v[n-1][1] + v[n-1][0])%r << "\n";
    // int ans = cook(n-1, 0) + cook(n-1, 1);
    // cout << ans << "\n";
    // for(auto x: mp) {
    //     cout << "n = " << x.first.first << ", val=" << x.first.second << ", count = " << x.second << "\n";
    // }
}