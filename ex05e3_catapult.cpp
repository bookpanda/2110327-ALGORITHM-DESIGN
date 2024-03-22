#include<bits/stdc++.h>
using namespace std;
int n, cou;
vector<int> e[1010], er[1010], visited, tpsort, comp;

void dfs1(int node) {
    visited[node] = true;
    for(int i=0;i<e[node].size();i++) {
        int nn = e[node][i];
        if(!visited[nn]) dfs1(nn);
    }
    tpsort.push_back(node);
}

void dfs2(int node) {
    visited[node] = true;
    cou++;
    // cout << "node " << node << "\n";
    for(int i=0;i<er[node].size();i++) {
        int nn = er[node][i];
        // cout << "nn " << nn << "\n";
        if(!visited[nn]) {
            dfs2(nn);
        }
    }
}

void scc() {
    for(int i=0;i<n;i++) {
        if(!visited[i])
            dfs1(i);
    }

    for(int i=0;i<n;i++) visited[i] = false;

    for(int i=0;i<n;i++) {
        int st = tpsort[n-1-i];
        if(!visited[st]) {
            // cout << "start new comp\n";
            cou=0;
            dfs2(st);
            comp.push_back(cou);
        }
    }
}


int main() {
    cin >> n;
    visited.resize(n);
    for(int i=0;i<n;i++) {
        int m;
        cin >> m;
        for(int j=0;j<m;j++) {
            int a;
            cin >> a; //i -> a
            e[i].push_back(a);
            er[a].push_back(i);
        }
    }

    scc();
    sort(comp.begin(), comp.end());
    for(auto x: comp) {
        cout << x << " ";
    }
}