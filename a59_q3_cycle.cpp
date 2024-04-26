#include<bits/stdc++.h>
using namespace std;
int n, ans;
vector<int> al[100100], visited, tag;

void dfs(int node, int prev, int lvl) {
    visited[node] = 1;
    tag[node] = lvl;
    for(auto nn: al[node]) {
        if(nn != prev && visited[nn]) {
            ans = abs(tag[nn] - lvl)+1;
        }
        if(visited[nn]) continue;
        dfs(nn, node, lvl+1);
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    visited.resize(n);
    tag.resize(n);
    dfs(0, -1, 0);

    cout << ans << "\n";
}