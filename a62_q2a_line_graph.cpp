#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> al[200010], visited;

int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    visited.resize(n);
    int cou = 0;
    for(int i=0;i<n;i++) {
        if(visited[i]) continue;

        // cout << "st " << i << "\n";
        queue<int> q;
        q.push(i);
        int deg[3] = {0, 0, 0};
        bool isLine=true;
        while(!q.empty()) {
            int node = q.front();
            visited[node] = 1;
            q.pop();
            // cout << "node " << node << "\n";
            if(al[node].size() > 2) {
                isLine = false;
                break;
            }
            deg[al[node].size()]++;
            for(int j=0;j<al[node].size();j++) {
                int nn = al[node][j];
                if(!visited[nn]) {
                    q.push(nn);
                }
            }
        }
        if(!isLine) continue;
        if(deg[1] == 2 || (deg[1]==0 && deg[2]==0)) cou++;
        //another way: check if visited node is not parent => not line
    }
    cout << cou << "\n";
}