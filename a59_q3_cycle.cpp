#include<bits/stdc++.h>
using namespace std;
int n;
int visited[100010];
vector<int> al[100010];
int ans = -1;

void dfs(int node) {
    for(int i=0;i<al[node].size();i++) {
        int nn = al[node][i];
        if(!visited[nn]) {
            visited[nn] = visited[node] + 1;
            // cout << "visited[" << nn << "] = " << visited[nn] << "\n";
            dfs(nn);
        } else if(visited[nn] && visited[nn] != visited[node]-1) {
            // cout << "cycle node = " << node << "\n";
            ans = max(ans, abs(visited[node]-visited[nn])+1);
            return;
        }
    }
}

int main() {
    cin >> n;
    int st = -1;
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for(int i=0;i<n;i++) visited[i] = 0;
    visited[0] = 1;
    dfs(0);
    cout << ans << "\n";
}