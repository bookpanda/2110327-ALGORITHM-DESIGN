#include<bits/stdc++.h>
using namespace std;
int n, p;
vector<int> e[5010], er[5010], e2[5010], visited, tpsort, comp;
int compcou=0, idx[5010], compsize[5010], dp[5010], ans[5010];

void dfs1(int node) {
    visited[node] = 1;
    for(int i=0;i<e[node].size();i++) {
        int nn = e[node][i];
        if(!visited[nn]) dfs1(nn);
    }
    tpsort.push_back(node);
}

void dfs2(int node) {
    visited[node] = 1;
    comp.push_back(node);
    for(int i=0;i<er[node].size();i++) {
        int nn = er[node][i];
        if(!visited[nn]) dfs2(nn);
    }
}

void scc() {
    for(int i=0;i<n;i++) {
        if(!visited[i]){
            dfs1(i);
        }
    }
    for(int i=0;i<n;i++) visited[i] = 0;
    for(int i=0;i<n;i++) {
        int st = tpsort[n-1-i]; //topo order
        if(!visited[st]){
            comp.clear();
            dfs2(st);
            for(int j=0;j<comp.size();j++) {
                idx[comp[j]] = compcou;
            }
            compsize[compcou] = comp.size();
            compcou++;
        }
    }
}

void dfs3(int node) {
    visited[node] = 1;
    for(int i=0;i<e2[node].size();i++) {
        int nn = e2[node][i];
        if(!visited[nn]) dfs3(nn);
    }
    tpsort.push_back(node);
}

int main() {
    cin >> n >> p;
    visited.resize(n);
    for(int i=0;i<p;i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        er[b].push_back(a);
    }

    scc();

    for(int i=0;i<n;i++) {
        for(int j=0;j<e[i].size();j++) {
            e2[idx[i]].push_back(idx[e[i][j]]);
        }
    }

    for(int i=0;i<n;i++) visited[i] = 0;
    tpsort.clear();
    for(int i=0;i<compcou;i++) {
        if(!visited[i]) dfs3(i);
    }

    for(int i=tpsort.size()-1;i>=0;i--) { //topo order
        int node = tpsort[i];
        dp[node]++;
        for(int j=0;j<e2[node].size();j++) {
            int nn = e2[node][j];
            dp[nn] = max(dp[nn], dp[node]);
        }
    }

    for(int i=0;i<compcou;i++) {
        ans[dp[i]] += compsize[i];
    }
    for(int i=1;i<=compcou;i++) {
        if(ans[i] == 0) break;
        cout << ans[i] << " ";
    }
}