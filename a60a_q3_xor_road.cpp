#include<bits/stdc++.h>
using namespace std;
int n, code[2020], p[2020], s[2020];
vector<pair<int, pair<int,int> > > edges;

int find(int x) {
    if(x == p[x]) return x;
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
        for(int j=i+1;j<n;j++) {
            int val = code[i] ^ code[j];
            edges.push_back({-val, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());

    for(int i=0;i<n;i++) {
        s[i] = 1;
        p[i] = i;
    }

    unsigned long long totalsum = 0;
    for(int i=0;i<edges.size();i++) {
        int val = -edges[i].first;
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        if(find(x) != find(y)) {
            unionset(x, y);
            totalsum += val;
        }
    }

    cout << totalsum << "\n";
}