#include<bits/stdc++.h>
using namespace std;
int n, p[1010], s[1010];
vector<pair<int,pair<int,int> > > edges;

int find(int x) {
    if(x == p[x]) return x;
    p[x] = find(p[x]);
    return p[x];
}

void unionset(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(s[fx] > s[fy]) {
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
            int w;
            cin >> w;
            edges.push_back({w, {i, j}});
            // cout << "edge from " << i << " to " << j << ", w=" << w << "\n";
        }
    }
    sort(edges.begin(), edges.end());

    for(int i=0;i<n;i++) {
        p[i] = i;
        s[i] = 1;
    }

    int totalw = 0;
    for(int i=0;i<edges.size();i++) {
        int w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // cout << "finda = " << find(a) << ", findb = " << find(b) << "\n";
        if(find(a) != find(b)) {
            unionset(a, b);
            // cout << "w=" << w << ", connect " << a << ", " << b << "\n";
            // cout << "p: ";
            // for(int j=0;j<n;j++) {
            //     cout << p[j] << " ";
            // } cout << "\n";
            // cout << "s: ";
            // for(int j=0;j<n;j++) {
            //     cout << s[j] << " ";
            // } cout << "\n";
            totalw += w;
        }
    }
    cout << totalw << "\n";
}