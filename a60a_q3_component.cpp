#include<bits/stdc++.h>
using namespace std;
int v, e;
vector<int> al[10010], visited;

int main() {
    cin >> v >> e;
    visited.resize(v);
    for(int i=0;i<e;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    int cc = 0;
    for(int node=1;node<=v;node++) {
        if(visited[node]) continue;

        queue<int> q;
        cc++;
        // cout << "start node " << node << "\n";
        q.push(node);
        visited[node] = true;
        while(!q.empty()) {
            int cn = q.front();
            q.pop();
            for(int i=0;i<al[cn].size();i++) {
                int nn = al[cn][i];
                if(!visited[nn]) {
                    visited[nn] = true;
                    q.push(nn);
                }
            }
        }
    }
    cout << cc << "\n";
}