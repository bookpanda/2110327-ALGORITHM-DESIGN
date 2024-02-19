#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> val, w;
map<pair<int,int>, int> mp;
map<pair<int,int>, vector<int> > bt;

int knap(int idx, int weight) {
    if(idx==0 || weight==0) return 0;
    if(mp.find({idx, weight}) != mp.end()) return mp[{idx, weight}];

    if(weight >= w[idx]) {
        int take = knap(idx-1, weight-w[idx]) + val[idx];
        int old = knap(idx-1, weight);
        if(take > old) {
            mp[{idx, weight}] = take;
            bt[{idx, weight}] = bt[{idx-1, weight-w[idx]}];
            bt[{idx, weight}].push_back(idx);
            return take;
        } else {
            mp[{idx, weight}] = old;
            bt[{idx, weight}] = bt[{idx-1, weight}];
            return old;
        }
    }

    int old = knap(idx-1, weight);
    mp[{idx, weight}] = old;
    bt[{idx, weight}] = bt[{idx-1, weight}];
    return old;
}

int main() {
    cin >> n >> m;
    val.push_back(-1);
    w.push_back(-1);
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        val.push_back(a);
    }
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        w.push_back(a);
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            int a;
            cin >> a;
            // mp[{i, j}] = a;
        }
    }

    int ans = knap(n, m);
    // cout << ans << "\n";
    vector<int> vans = bt[{n, m}];
    cout << vans.size() << "\n";
    for(auto x: vans) {
        cout << x << " ";
    }
}