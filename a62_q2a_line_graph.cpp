#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> al[100010], visited;

bool dfs(int node, int prev) {
    visited[node] = 1;
    if(al[node].size() > 2) return false;
    for(auto nn: al[node]) {
        if(nn != prev && visited[nn]) return false;
        if(visited[nn]) continue;
        if(!dfs(nn, node)) return false;
    }

    return true;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    visited.resize(n);
    int line=0;
    for(int i=0;i<n;i++) {
        if(visited[i]) continue;
        if(dfs(i, -1)) line++;
    }

    cout << line << "\n";
}