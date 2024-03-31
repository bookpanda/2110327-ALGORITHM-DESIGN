#include<bits/stdc++.h>
using namespace std;
int n, m, k, st[100010], c[100010];
vector<int> al[100010];
vector<int> visited;

int main() {
    cin >> n >> m >> k;
    for(int i=0;i<k;i++) cin >> st[i];
    for(int i=0;i<n;i++) cin >> c[i];
    visited.resize(n);
    for(int i=0;i<n;i++) visited[i] = INT_MAX;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    priority_queue<pair<int, int> > pq;
    for(int i=0;i<k;i++) {
        pq.push({-c[st[i]], st[i]});
        visited[st[i]] = c[st[i]];
    }
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(int i=0;i<al[node].size();i++) {
            int nn = al[node][i];
            if(visited[nn] > cost + c[nn]) {
                visited[nn] = cost + c[nn];
                pq.push({-(cost+c[nn]), nn});
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, visited[i]);
    cout << ans << "\n";
    
}