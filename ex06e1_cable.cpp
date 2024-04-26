#include<bits/stdc++.h>
using namespace std;
int n, p[1010], s[1010];
vector<pair<int, pair<int, int> > > edges;

int findP(int x) {
    if(p[x] == x) return x;
    p[x] = findP(p[x]);
    return p[x];
}

void unionSet(int x, int y) {
    int fx = findP(x);
    int fy = findP(y);
    if(s[fx] >= s[fy]) {
        p[fy] = fx;
        s[fx] += s[fy];
        return;
    }
    p[fx] = fy;
    s[fy] += s[fx];
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

    int totalw = 0;
    for(int i=0;i<edges.size();i++) {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int w = edges[i].first;
        if(findP(a) != findP(b)) {
            unionSet(a, b);
            totalw += w;
        }
    }

    cout << totalw << "\n";
}