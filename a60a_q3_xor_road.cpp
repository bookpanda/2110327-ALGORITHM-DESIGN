#include<bits/stdc++.h>
using namespace std;
int n, code[2010], p[2010], s[2010];
vector<pair<long long, pair<int, int> > > edges;

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
    for(int i=0;i<n;i++) {
        cin >> code[i];
    }
    for(int i=0;i<n;i++) {
        p[i] = i;
        s[i] = 1;
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            edges.push_back({-(code[i] ^ code[j]), {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    unsigned long long totalsum = 0;
    for(int i=0;i<edges.size();i++) {
        long long w = -edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // cout << a << ", " << b << " w= " << w << "\n";
        if(find(a) != find(b)) {
            unionset(a, b);
            totalsum += w;
        }
    }
    cout << totalsum << "\n";
}