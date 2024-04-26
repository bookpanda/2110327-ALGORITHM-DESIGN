#include<bits/stdc++.h>
using namespace std;
int n, t[3];
vector<int> al[250010], visited[3];

int main() {
    cin >> n;
    for(int i=0;i<3;i++) cin >> t[i];
    for(int i=1;i<=n;i++) {
        int a;
        cin >> a;
        while(a--) {
            int b;
            cin >> b;
            al[i].push_back(b);
        }
    }

    for(int i=0;i<3;i++) {
        visited[i].resize(n);
        queue<pair<int, int> > q;
        q.push({t[i], 1});
        visited[i][t[i]] = 1;
        while(!q.empty()) {
            int node = q.front().first;
            int lvl = q.front().second;
            q.pop();
            // cout << "node " << node << ", lvl " << lvl << "\n";
            
            for(auto nn: al[node]) {
                // cout << "nn " << nn << "\n";
                if(visited[i][nn]) continue;
                q.push({nn, lvl+1});
                visited[i][nn] = lvl+1;
            }
        }
    }

    int ans = INT_MAX;
    for(int i=1;i<=n;i++) {
        // cout << visited[0][i] << ", " << visited[1][i] << ", " << visited[2][i] << "\n";
        if(!visited[0][i] || !visited[1][i] || !visited[2][i]) continue;
        ans = min(ans, max(visited[0][i], max(visited[1][i], visited[2][i])));
    }
    cout << ans-1 << "\n";
}