#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> al[10010], visited;

void dfs(int node) {
    visited[node] = 1;
    for(int i=0;i<al[node].size();i++) {
        int nn = al[node][i];
        if(!visited[nn]) {
            dfs(nn);
        }
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
    for(int i=0;i<=n;i++) visited[i] = 0;
    int cou = 0;
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            cou++;
            dfs(i);
        }
    }
    cout << cou << "\n";
}