#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> al[1010], visited;

int main() {
    cin >> n >> m >> k;
    visited.resize(n);
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    queue<pair<int, int> > q;
    q.push({0, 0});
    visited[0] = 1;
    int ans = 0;
    while(!q.empty()) {
        int dist = q.front().first;
        int node = q.front().second;
        q.pop();
        if(dist == k) ans++;
        for(int i=0;i<al[node].size();i++) {
            int nn = al[node][i];
            if(!visited[nn] && dist+1 <= k) {
                visited[nn] = 1;
                q.push({dist+1, nn});
            }
        }
    }
    cout << ans << "\n";
}