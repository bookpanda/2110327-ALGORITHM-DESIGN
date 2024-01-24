#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q;
    vector<pair<int,int> > v, ans;
    vector<pair<int, pair<int,int> > > qa;

    cin >> n >> q;
    v.resize(n);
    qa.resize(q);
    for(int i=0;i<n;i++) {
        int x, sz;
        cin >> x >> sz;
        v[i] = {x, sz};
    }
    sort(v.begin(), v.end());
    for(int i=1;i<n;i++) {
        v[i].second += v[i-1].second;
    }
    
    // cout << "\n---------------\n";
    // for(int i=0;i<v.size();i++){
        // cout << v[i].first << ", " << v[i].second << "\n";
        // v2[i] = {v[i].second, v[i].first};
    // }

    for(int i=0;i<q;i++) {
        int id;
        cin >> id;
        qa[i] = {id, {i, -1}};
    }
    sort(qa.begin(), qa.end());

    int idx = 0;
    for(int i=0;i<n;i++) {
        int lim = v[i].second;
        int val = v[i].first;
        while(idx<q && qa[idx].first <= lim) {
            qa[idx].second.second = val;
            idx++;
        }
    }
    for(int i=0;i<q;i++) {
        ans.push_back({qa[i].second.first, qa[i].second.second});
    }
    sort(ans.begin(), ans.end());
    for(auto x: ans){
        cout << x.second << "\n";
    }
}