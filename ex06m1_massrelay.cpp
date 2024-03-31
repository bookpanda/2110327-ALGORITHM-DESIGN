#include<bits/stdc++.h>
using namespace std;
int n, m, q, p[5010], s[5010], mink[5010], cou;
vector<pair<int, pair<int, int> > > edges;

int find(int x) {
    if(p[x] == x) return x;
    p[x] = find(p[x]);
    return p[x];
}

void unionset(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(s[fx] > s[fy]) {
        s[fx] += s[fy];
        p[fy] = fx;
        return;
    }
    s[fy] += s[fx];
    p[fx] = fy;
}

int main() {
    cin >> n >> m >> q;
    for(int i=0;i<m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    cou = n;
    sort(edges.begin(), edges.end());
    for(int i=0;i<n;i++) {
        p[i] = i;
        s[i] = 1;
        mink[i] = INT_MAX;
    }
    mink[n] = 0;
    for(int i=0;i<m;i++) {
        int w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(find(a) != find(b)) {
            cou--;
            mink[cou] = min(mink[cou], w);
            unionset(a, b);
        }
    }
    // for(int i=0;i<=n;i++) {
    //     cout << mink[i] << " ";
    // } cout << "\n";
    while(q--) {
        int d;
        cin >> d;
        cout << mink[d] << "\n";
    }
}