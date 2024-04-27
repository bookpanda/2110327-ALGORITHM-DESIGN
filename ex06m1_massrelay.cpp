#include<bits/stdc++.h>
using namespace std;
int n, m, k, p[5010], s[5010], ans[5010];
vector<pair<int, pair<int, int> > > edges;

int findP(int x) {
    if(p[x] == x) return x;
    p[x] = findP(p[x]);
    return p[x];
}

void unionSet(int x, int y) {
    int fx = findP(x);
    int fy = findP(y);
    if(s[x] >= s[y]) {
        s[x] += s[y];
        p[fy] = fx;
        return;
    }
    s[y] += s[x];
    p[fx] = fy;
}

int main() {
    cin >> n >> m >> k;
    for(int i=0;i<m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    for(int i=0;i<n;i++) {
        p[i] = i;
        s[i] = 1;
    }

    int cc = n;
    ans[cc] = 0;
    for(int i=0;i<edges.size();i++) {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int w = edges[i].first;
        if(findP(a) != findP(b)) {
            cc--;
            unionSet(a, b);
            ans[cc] = w;
        }
    }
    for(int i=1;i<=n;i++) cout << i << " clusters : " << ans[i] << "\n";

    for(int i=0;i<k;i++) {
        int d;
        cin >> d;
        cout << ans[d] << "\n";
    }
}