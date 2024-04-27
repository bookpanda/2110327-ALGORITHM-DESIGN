#include<bits/stdc++.h>
using namespace std;
int n, m, mincolor = 1;
vector<int> al[55], visited, bl[55];

void dfs(int node, vector<int> &seq) {
    visited[node] = 1;
    seq.push_back(node);

    for(auto nn: al[node]) {
        if(!visited[nn]) continue;
        bl[node].push_back(nn);
    }
    for(auto nn: al[node]) {
        if(visited[nn]) continue;
        dfs(nn, seq);
    }
}

bool canColor(int idx, vector<int> &seq, vector<int> &color) {
    if(idx == seq.size()) return true;

    int node = seq[idx];
    vector<int> cc(mincolor+1);
    for(auto nn: bl[node]) {
        cc[color[nn]]++;
    }
    for(int i=1;i<=mincolor;i++) {
        if(cc[i] == 0) {
            color[node] = i;
            if(canColor(idx+1, seq, color)) return true;
        }
    }
   
   return false;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    visited.resize(n);

    for(int i=0;i<n;i++) {
        if(visited[i]) continue;
        vector<int> seq;
        dfs(i, seq);
        // cout << "st " << i << ", seq : ";
        // for(auto x: seq) {
        //     cout << x << " ";
        // } cout << "\n";
        while(1) {
            vector<int> color(n, 0);
            if(canColor(0, seq, color)) break;
            mincolor++;
        }
    }

    cout << mincolor << "\n";
}