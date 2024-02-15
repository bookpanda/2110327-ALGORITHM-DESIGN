#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>, int> mp;

int mcm(int l, int r, vector<int> &v) {
    if(l == r) return 0;
    if(mp.find({l, r}) != mp.end()) return mp[{l, r}];
    
    int mincost = INT_MAX;
    for(int i=l;i<r;i++) { // if v[i] = r, v[i+1] = c
        int sum = mcm(l, i, v) + mcm(i+1, r, v) + v[l]*v[i+1]*v[r+1];
        mincost = min(mincost, sum);
    }

    mp[{l, r}] = mincost;
    return mincost;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<=n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int ans = mcm(0, n-1, v);
    cout << ans << "\n";
}