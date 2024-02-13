#include<bits/stdc++.h>
using namespace std;
int l, r; 
map<int, pair<int,int> > mp;

pair<int,int> cook(int n, int prev) {
    if(n <= 1) {
        mp[n] = {1, prev};
        return mp[n];
    }
    pair<int,int> res = cook(n/2, n);
    int len = res.first;
    int parent = res.second;
    mp[n] = {2*len + 1, prev};

    return mp[n]; 
}

int cook2(int idx, vector<pair<int,pair<int,int> > > &v) { //index 0 to idx, how many ones
    int cou = 0;
    for(int i=0;i<v.size();i++) {
        int ones = v[i].first;
        int len = v[i].second.first;
        int prev = v[i].second.second;
        if(idx - len < 0) continue;
        if(idx - len >= 0) {
            idx -= len;
            cou += ones;
            // cout << "use " << ones << ", len=" << len << ", new idx=" << idx << "\n";
            if(idx >= 1) {
                idx--;
                cou += prev%2;
                // cout << "add middle " << prev%2 << "\n";
            }
        }
        if(idx == 0) break;
    }
    return cou;
}

int main() {
    int n;
    cin >> n;
    cin >> l >> r;
    cook(n, -1);
    vector<pair<int, pair<int,int> > > v(mp.begin(), mp.end());
    reverse(v.begin(), v.end());
    // v.push_back({1, {1, }});
    // for(auto x: v) {
    //     cout << "num and ones=" << x.first << ",  len=" << x.second.first << ", prev=" << x.second.second << "\n";
    // }
    int st = cook2(l-1, v);
    // cout << "--------\n";
    int ed = cook2(r, v);
    cout << ed - st << "\n";
}