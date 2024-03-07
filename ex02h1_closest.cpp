#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int> > v;

int dist(pair<int,int> p1, pair<int,int> p2) {
    int difx = p1.first - p2.first;
    int dify = p1.second - p2.second;
    return difx*difx + dify*dify;
}

int cp(int st, int ed) {
    if(st >= ed) return INT_MAX;

    int mid = (st + ed) / 2;
    int minhalf = min(cp(st, mid), cp(mid+1, ed));

    int d = minhalf;
    int middlex = (v[mid].first + v[mid+1].first) / 2;
    vector<pair<int,int> > vy;
    for(int i=st;i<=ed;i++) {
        int dis = abs(v[i].first - middlex);
        if(dis > d) continue;
        vy.push_back({v[i].second, v[i].first});
    }
    sort(vy.begin(), vy.end());

    int ans = d;
    for(int i=0;i<vy.size();i++) {
        for(int j=i+1;j<vy.size();j++) {
            int dis = abs(vy[i].first - vy[j].first);
            if(dis > d) continue;
            ans = min(ans, dist(vy[i], vy[j]));
        }
    }

    return ans;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int ans = cp(0, n-1);
    cout << ans << "\n";
}