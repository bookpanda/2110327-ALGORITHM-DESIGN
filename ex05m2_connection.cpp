#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> al[1010];

int main() {
    cin >> n >> m >> k;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        vector<int> visited(n, 0);
        queue<pair<int, int> > q;
        q.push({i, 0});
        visited[i] = 1;
        int cou = 0;
        while(!q.empty()) {
            int node = q.front().first;
            int lvl = q.front().second;
            q.pop();
            // cout << node << ", " << lvl << "\n";

            if(lvl <= k) {
                cou++;
            }
            for(auto nn: al[node]) {
                if(visited[nn]) continue;
                q.push({nn, lvl+1});
                visited[nn] = 1;
            }
        }
        ans = max(ans, cou);
        // cout << "start " << i << ", cou = " << cou << "\n";
    }

    cout << ans << "\n";
}