#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> k;
int visited[25][20005], ans[20005];
vector<pair<int, int> > al[25];

int main() {
    k.resize(8);
    cin >> n >> m;
    for(int i=0;i<8;i++) {
        cin >> k[i];
    }
    for(int i=0;i<m;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        al[a].push_back({w, b});
        al[b].push_back({w, a});
    }
    queue<pair<int, pair<int, int> > > q;
    for(int i=0;i<n;i++) {
        q.push({i, {0, 1<<i}});
    }
    while(!q.empty()) {
        int node = q.front().first;
        int w = q.front().second.first;
        int mask = q.front().second.second;
        q.pop();
        for(auto &[nw, nn]: al[node]) {
            int neww = nw+w;
            if(!visited[nn][neww] && (mask & (1<<nn)) == 0) {
                int newmask = mask | (1<<nn);
                q.push({nn, {neww, newmask}});
                visited[nn][neww] = 1;
                ans[neww] = 1;
            }
        }
    }

    for(int i=0;i<8;i++) {
        if(ans[k[i]]) cout << "YES\n";
        else cout << "NO\n";
    }
}