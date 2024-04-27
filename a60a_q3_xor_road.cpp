#include<bits/stdc++.h>
using namespace std;
int n, val[2010], p[2010], s[2010];
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
        s[fx] += s[fy];
        p[fy] = fx;
        return;
    }
    s[fy] += s[fx];
    p[fx] = fy;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> val[i];
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            edges.push_back({val[i] ^ val[j], {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    for(int i=0;i<n;i++) {
        p[i] = i;
        s[i] = 1;
    }

    unsigned long long sum = 0;
    for(int i=0;i<edges.size();i++) {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int w = edges[i].first;
        if(findP(a) != findP(b)) {
            unionSet(a, b);
            sum += w;
        }
    }

    cout << sum << "\n";
}