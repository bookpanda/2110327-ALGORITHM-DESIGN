#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;

int cook(int n, vector<int> &v) {
    if(n<0) return -INT_MAX;
    if(n==0) return v[n];
    if(mp.find(n) != mp.end()) return mp[n];
    // cout << "n=" << n << "\n";

    int b1 = cook(n-1, v);
    int b2 = cook(n-2, v);
    int b3 = cook(n-3, v);
    int maxb = max(max(b1, b2), b3);

    mp[n] = maxb + v[n];
    return mp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int ans = cook(n-1, v);
    cout << ans << "\n";
}