#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v, w;
map<pair<int, int>, pair<int, vector<int> > > mp;

pair<int, vector<int> > knap(int last, int maxw) {
    if(last == 0 || maxw == 0) return {0, {}};
    if(mp.find({last, maxw}) != mp.end()) return mp[{last, maxw}];
    pair<int, vector<int> > ans;
    if(maxw >= w[last]) {
        pair<int, vector<int> > a = knap(last-1, maxw);
        pair<int, vector<int> > b = knap(last-1, maxw-w[last]);
        b.first += v[last];
        if(b > a) {
            ans = b;
            ans.second.push_back(last);
        } else ans = a;
    } else ans = knap(last-1, maxw);

    mp[{last, maxw}] = ans;
    return ans;
}

int main() {
    cin >> n >> m;
    v.push_back(-1);
    w.push_back(-1);
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
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
        }
    }
    pair<int, vector<int> > ans = knap(n, m);
    cout << ans.second.size() << "\n";
    for(auto x: ans.second) {
        cout << x << " ";
    }
}