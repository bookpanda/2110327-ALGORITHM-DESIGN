#include<bits/stdc++.h>
using namespace std;
int n, p[1010], s[1010];
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
    cin >> n;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            int a;
            cin >> a;
            edges.push_back({a, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    for(int i=0;i<n;i++) {
        p[i] = i;
        s[i] = 1;
    }
    int totalsum = 0;
    for(int i=0;i<edges.size();i++) {
        int w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(find(a) != find(b)) {
            unionset(a, b);
            // cout << a << ", " << b << "\n";
            totalsum += w;
        }
    }
    cout << totalsum << "\n";
}