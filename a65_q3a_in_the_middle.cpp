#include<bits/stdc++.h>
using namespace std;
int n, t[3];
vector<int> al[250100], visited[3];

int main() {
    cin >> n;
    for(int i=0;i<3;i++) cin >> t[i];
    for(int i=1;i<=n;i++) {
        int m;
        cin >> m;
        while(m--) {
            int a;
            cin >> a;
            al[i].push_back(a);
        }
    }
    for(int p=0;p<3;p++) {
        int st = t[p];
        visited[p].resize(n+1);
        for(int i=0;i<=n;i++) visited[p][i] = INT_MAX;

        queue<pair<int, int> > q;
        q.push({st, 0});
        visited[p][st] = 0;
        while(!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(int i=0;i<al[node].size();i++) {
                int nn = al[node][i];
                if(visited[p][nn] == INT_MAX) {
                    visited[p][nn] = dist + 1;
                    q.push({nn, dist+1});
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int i=1;i<=n;i++) {
        ans = min(ans, max(visited[0][i], max(visited[1][i], visited[2][i])));
    }
    cout << ans << "\n";
}