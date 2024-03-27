#include<bits/stdc++.h>
using namespace std;
int n, m, q, p[5010], s[5010], weightGroup[5010];
vector<pair<int, pair<int,int> > > edges;

int find(int x) {
    if(x == p[x]) return p[x];
    p[x] = find(p[x]);
    return p[x];
}

void unionSet(int x, int y) {
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
    for(int i=0;i<n;i++) {
        p[i] = i;
        s[i] = 1;
    }
    sort(edges.begin(), edges.end());
    int ccou = n;
    for(int i=0;i<m;i++) {
        int w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(find(a) != find(b)) {
            ccou--;
            weightGroup[ccou] = w;
            // cout << "wg[" << ccou << "] = " << w << "\n";
            unionSet(a, b);
        }
    }
    for(int query=0;query<q;query++) {
        int d;
        cin >> d;
        cout << weightGroup[d] << "\n";
    }
}