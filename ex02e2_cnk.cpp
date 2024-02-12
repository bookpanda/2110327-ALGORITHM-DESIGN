#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>, int> mp;

int cook(int n, int k) {
    if(n == k || k == 0) return 1;
    if(mp.find({n, k}) != mp.end()) return mp[{n, k}];
    
    mp[{n, k}] = cook(n-1, k-1) + cook(n-1, k);
    return mp[{n, k}];
}

int main() {
    int n, k;
    cin >> n >> k;
    int ans = cook(n, k);
    cout << ans << "\n";
}