#include<bits/stdc++.h>
using namespace std;
int n, m, k, ed, st[5010], sp[5010];
vector<pair<int, pair<int, int> > > edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k >> ed;
    for(int i=0;i<n;i++) sp[i] = 1000000000;
    for(int i=0;i<k;i++) {
        cin >> st[i];
        sp[st[i]] = 0;
    }
    for(int i=0;i<m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            int w = edges[j].first;
            int a = edges[j].second.first;
            int b = edges[j].second.second;
            sp[b] = min(sp[b], sp[a] + w);
        }
    }
    cout << sp[ed];
}