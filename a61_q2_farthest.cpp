#include<bits/stdc++.h>
using namespace std;
int n, am[1010][1010], lp[1010];

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> am[i][j];
        }
    }
    for(int i=1;i<=n;i++) lp[i] = INT_MAX;

    priority_queue<pair<int,int> > pq;
    lp[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        // cout << node << ", w=" << w << "\n";
        for(int i=1;i<=n;i++) {
            if(am[node][i] == -1 || am[node][i] == 0) continue;

            if(lp[i] > w + am[node][i]) {
                lp[i] = w + am[node][i];
                pq.push({lp[i], i});
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans, lp[i]);
    if(ans == INT_MAX) cout << "-1\n";
    else cout << ans << "\n";
}