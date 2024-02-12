#include<bits/stdc++.h>
using namespace std;

int dist(pair<int,int> p1, pair<int,int> p2) {
    int d1 = p1.first - p2.first;
    int d2 = p1.second - p2.second;
    return d1*d1 + d2*d2;
}

int cp(int st, int ed, vector<pair<int,int> > &v) {
    if(st >= ed) return INT_MAX;
    if(ed - st == 1) return dist(v[st], v[ed]);

    int mid = (st+ed)/2;
    int lefthalf = cp(st, mid, v);
    int righthalf = cp(mid+1, ed, v);
    int d = min(lefthalf, righthalf);

    int midx = (v[mid].first + v[mid+1].first) / 2;
    // cout << "st=" << st << ", ed=" << ed << ", d=" << d << ", midx=" << midx << "\n";
    vector<pair<int,int> > tmp;
    for(int i=st;i<=ed;i++) {
        // cout << "point:" << v[i].first << ", " << v[i].second << "\n";
        if(abs(v[i].first - midx) < d) {
            // cout << "have this within d :" << v[i].first << ", " << v[i].second << "\n";
            tmp.push_back({v[i].second, v[i].first});
        }
    }
    sort(tmp.begin(), tmp.end());

    int mindis = d;
    for(int i=0;i<tmp.size();i++) {
        for(int j=i+1;j<tmp.size();j++) {
            if(tmp[j].first - tmp[i].first > d) break;
            mindis = min(mindis, dist(tmp[i], tmp[j]));
        }
    }

    // cout << "dis=" << mindis << "\n";
    return mindis;
}

int main() {
    int n;
    vector<pair<int,int> > v;
    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    int ans = cp(0, n-1, v);
    cout << ans << "\n";
}