#include<bits/stdc++.h>
using namespace std;
int t;

bool dfs(int node, int parent, vector<vector<int> > &edges, vector<int> &visited) {
    visited[node] = true;
    // cout << "node " << node << "\n";
    for(int i=0;i<edges[node].size();i++) {
        int nn = edges[node][i];
        if(!visited[nn]) {
            visited[nn] = 1;
            if(dfs(nn, node, edges, visited)) {
                // cout << "cycle in " << nn << "\n";
                return true;
            }
        } else if(parent != nn) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > edges(n);
        vector<int> visited(n);
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        for(int i=0;i<n;i++) visited[i] = 0;
        bool isCycle = false;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                // cout << "st " << i << "\n";
                if(dfs(i, -1, edges, visited)) {
                    isCycle = true;
                    break;
                }
            }
        }
        if(isCycle) cout << "YES\n";
        else cout << "NO\n";
    }
}