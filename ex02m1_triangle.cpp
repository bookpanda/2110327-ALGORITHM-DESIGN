#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>, int> mp;

int cook(int r, int c, vector<vector<int> > &v) {
    if(c > r || r<0 || c<0) return -INT_MAX;
    if(mp.find({r, c}) != mp.end()) return mp[{r, c}];


    int tl = cook(r-1, c-1, v);
    int tr = cook(r-1, c, v);
    mp[{r, c}] = max(tl, tr) + v[r][c];
    // cout << "r=" << r << ", c=" << c << ", tl=" << tl << ", tr=" << tr << "\n";

    return mp[{r, c}];
}

int main() {
    int n;
    vector<vector<int> > v;
    cin >> n;
    for(int i=0;i<n;i++) {
        vector<int> tmp;
        for(int j=0;j<i+1;j++) {
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        v.push_back(tmp);
    }
    int maxsum = -INT_MAX;
    mp[{0, 0}] = v[0][0];
    for(int i=0;i<n;i++) {
        int sum = cook(n-1, i, v);
        // cout << "endr=" << n-1 << ", endc=" << i << ", sum = " << sum << "\n";
        maxsum = max(maxsum, sum);
    }
    cout << maxsum << "\n";
}