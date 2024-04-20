#include<bits/stdc++.h>
using namespace std;
int n, e, maxcolor=1;
vector<int> al[55], visited;
vector<vector<int> > bl;

void dfs(int node, vector<int> &seq) {
    visited[node] = 1;
    seq.push_back(node);
    for(auto nn: al[node]) {
        if(visited[nn]) bl[node].push_back(nn);
    }

    for(auto nn: al[node]) {
        if(visited[nn]) continue;
        dfs(nn, seq);
    }
}

bool color(int idx, vector<int> &seq, vector<int> &c) {
    if(idx == seq.size()) return true;
    int node = seq[idx];
    vector<bool> used(maxcolor+1, false);

    for(auto nn: bl[node]) {
        used[c[nn]] = true;
    }
    for(int i=1;i<=maxcolor;i++) {
        if(!used[i]) {
            c[node] = i;
            if(color(idx+1, seq, c)) return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> e;
    visited.resize(n);
    bl.resize(n);
    for(int i=0;i<e;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    for(int i=0;i<n;i++) {
        if(visited[i]) continue;
        vector<int> seq;
        bl.resize(n);
        dfs(i, seq);

        // cout << "seq : ";
        // for(auto x: seq) {
        //     cout << x << " ";
        // } cout << "\n";
        // for(int j=0;j<bl.size();j++) {
        //     cout << "bl[" << j << "]: ";
        //     for(int k=0;k<bl[j].size();k++) {
        //         cout << bl[j][k] << " ";
        //     }
        //     cout << "\n";
        // }
        while(1) {
            vector<int> c(n, 0);
            if(!color(0, seq, c)) maxcolor++;
            else break;
        }
    }
    cout << maxcolor << "\n";
}