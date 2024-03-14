#include<bits/stdc++.h>
using namespace std;
int t;

bool dfs(int node, int parent, vector<vector<int> > &al, vector<bool> &visited) {
    for(auto x: al[node]) {
        if(x != parent){
            if(visited[x]) return true;
            visited[x] = true;
            if(dfs(x, node, al, visited)) return true;
        } 
    }
    return false;
}

int main() {
    cin >> t;
    while(t--) {
        int n, e;
        cin >> n >> e;
        vector<vector<int> > al(n);
        for(int i=0;i<e;i++) {
            int a, b;
            cin >> a >> b;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        bool hasCycle = false;
        vector<bool> visited(n);
        for(int i=0;i<n;i++) visited[i] = false;
        for(int i=0;i<n;i++) {
            if(visited[i]) continue;
            visited[i] = true;
            if(dfs(i, -1, al, visited)) {
                hasCycle = true;
                break;
            }
        }

        // cout << "visited: ";
        // for(auto x: visited) {
        //     cout << x << ", ";
        // } cout << "\n";

        if(hasCycle) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
}