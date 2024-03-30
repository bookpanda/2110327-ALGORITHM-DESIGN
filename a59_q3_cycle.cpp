#include<bits/stdc++.h>
using namespace std;
int n, ans;
vector<int> al[100100], visited;

void dfs(int node) {
    for(auto nn: al[node]) {
        if(!visited[nn]) {
            visited[nn] = visited[node] + 1;
            dfs(nn);
        } else if(visited[nn] != visited[node]-1) {
            ans = visited[nn] - visited[node] + 1;
        }
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
    for(int i=0;i<n;i++) visited[i] = 0;
    visited[0] = 1;
    dfs(0);
    cout << ans << "\n";
}