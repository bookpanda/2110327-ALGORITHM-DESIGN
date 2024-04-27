#include<bits/stdc++.h>
using namespace std;
int n, am[1010][1010], sp[1010];

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> am[i][j];
        }
    }
    for(int i=0;i<n;i++) sp[i] = 999999;
    sp[0] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        int w = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(int i=0;i<n;i++) {
            if(i==node || am[node][i] < 1) continue;
            if(sp[i] > sp[node] + am[node][i]) {
                sp[i] = sp[node] + am[node][i];
                pq.push({-(sp[node] + am[node][i]), i});
            }
        }
    }
    int ans = -INT_MAX;
    for(int i=1;i<n;i++) {
        ans = max(ans, sp[i]);
    }
    if(ans == 999999) cout << -1;
    else cout << ans << "\n";
}