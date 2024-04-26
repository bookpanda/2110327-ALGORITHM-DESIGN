#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> al[10010], visited;

void dfs(int node) {
    visited[node] = 1;
    for(auto nn: al[node]) {
        if(visited[nn]) continue;
        dfs(nn);
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    visited.resize(n+1);
    int cou = 0;
    for(int i=1;i<=n;i++) {
        if(visited[i]) continue;
        dfs(i);
        cou++;
    }
    cout << cou << "\n";
}