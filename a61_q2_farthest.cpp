#include<bits/stdc++.h>
using namespace std;
int n, am[1010][1010], visited[1010];

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> am[i][j];
        }
    }
    for(int i=2;i<=n;i++) visited[i] = INT_MAX;

    priority_queue<pair<int, int> > pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(int i=1;i<=n;i++) {
            if(i == node || am[node][i] == -1) continue;
            int newcost = cost + am[node][i];
            if(visited[i] > newcost) {
                visited[i] = newcost;
                pq.push({-newcost, i});
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans = max(ans, visited[i]);
    }
    if(ans == INT_MAX) cout << "-1\n";
    else cout << ans << "\n";
}