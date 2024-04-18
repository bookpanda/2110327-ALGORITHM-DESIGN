#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> al[110], visited, colored;
vector<vector<int> > bl;
int highest=0;

void dfs(int node, vector<int> &cc) {
    visited[node] = 1;
    cc.push_back(node);

    for(auto nn: al[node]) {
        if(visited[nn]) bl[node].push_back(nn);
    }

    for(auto nn: al[node]) {
        if(visited[nn]) continue;
        dfs(nn, cc);
    }
    return;
}

bool color(int idx, vector<int> &cc) {
    if(idx >= cc.size()) return true;

    int node = cc[idx];
    vector<int> used(highest+1);
    for(int i=0;i<highest+1;i++) used[i] = 0;
    for(auto nn: bl[node]) {
        int c = colored[nn];
        used[c] = 1;
    }
    for(int i=1;i<=highest;i++) {
        if(used[i]) continue;
        colored[node] = i;

        if(color(idx+1, cc)) return true;
    }

    return false;
}

int main() {
    cin >> n >> m;
    visited.resize(n);
    bl.resize(n);
    colored.resize(n);
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            vector<int> cc;
            dfs(i, cc);
            // cout << "comp with " << i << ", size = " << cc.size() << "\n";
            // for(int i=0;i<cc.size();i++) cout << cc[i] << " ";
            // cout << "\n";
            while(1) {
                if(color(0, cc)) break;
                highest++;
            }
        }
    }
    cout << highest << "\n";
}