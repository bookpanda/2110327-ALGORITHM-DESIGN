#include<bits/stdc++.h>
using namespace std;
int n, m, k, st[100010], c[100010];
vector<pair<int, int> > al[100010];
vector<int> sp;

int main() {
    cin >> n >> m >> k;
    sp.resize(n);
    for(int i=0;i<n;i++) sp[i] = INT_MAX;
    for(int i=0;i<k;i++) {
        cin >> st[i];
    }
    for(int i=0;i<n;i++) {
        cin >> c[i];
    }
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back({b, c[b]});
        al[b].push_back({a, c[a]});
    }

    priority_queue<pair<int, int> > pq;
    for(int i=0;i<k;i++) {
        sp[st[i]] = c[st[i]];
        pq.push({-sp[st[i]], st[i]});
    }

    while(!pq.empty()) {
        int w = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto [nn, nw]: al[node]) {
            if(sp[nn] > w + nw) {
                pq.push({-(w+nw), nn});
                sp[nn] = w+nw;
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) {
        ans = max(ans, sp[i]);
    }
    cout << ans << "\n";
}