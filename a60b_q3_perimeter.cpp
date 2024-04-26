#include<bits/stdc++.h>
using namespace std;
int n, m, k, cou=0;
vector<int> al[1010], visited;

int main() {
    cin >> n >> m >> k;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    visited.resize(n);
    queue<pair<int, int> > q;
    q.push({0, 0});
    visited[0] = 1;
    while(!q.empty()) {
        int node = q.front().first;
        int lvl = q.front().second;
        q.pop();
        if(lvl == k) cou++;
        // cout << node << ", " << lvl << "\n";
        for(auto nn: al[node]) {
            if(visited[nn]) continue;
            q.push({nn, lvl+1});
            visited[nn] = 1;
        }
    }
    cout << cou << "\n";
}