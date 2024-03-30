#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> al[1010], visited, deg, ans;

int main() {
    cin >> n;
    visited.resize(n);
    deg.resize(n);
    for(int i=0;i<n;i++) {
        int m;
        cin >> m;
        deg[i] = m; //depends on m things
        while(m--) {
            int a;
            cin >> a;
            al[a].push_back(i);
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++) {
        if(deg[i] != 0) continue;
        visited[i] = 1;
        q.push(i);
        ans.push_back(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        // cout << "node " << node << "\n";
        for(int j=0;j<al[node].size();j++) {
            int nn = al[node][j];
            deg[nn]--;
            if(!visited[nn] && deg[nn]==0) {
                visited[nn] = 1;
                q.push(nn);
                ans.push_back(nn);
            }
        }
    }
    for(auto x: ans) {
        cout << x << " ";
    }
}