#include<bits/stdc++.h>
using namespace std;
int n, m, k, ed, st[5010];
vector<pair<int, pair<int, int> > > edges;
vector<int> sp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    cin >> ed;
    sp.resize(n);
    for(int i=0;i<k;i++) cin >> st[i];
    for(int i=0;i<m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    for(int i=0;i<n;i++) sp[i] = 9999999;
    for(int i=0;i<k;i++) {
        sp[st[i]] = 0;
    }

    for(int i=0;i<n-1;i++) {
        for(int j=0;j<edges.size();j++) {
            int a = edges[j].second.first;
            int b = edges[j].second.second;
            int w = edges[j].first;
            if(sp[b] > sp[a] + w) {
                sp[b] = sp[a] + w;
            }
        }
    }

    cout << sp[ed] << "\n";
}