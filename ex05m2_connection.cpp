#include<bits/stdc++.h>
using namespace std;
vector<int> al[1010];

int main() {
    int n, e, k;
    cin >> n >> e >> k;
    for(int i=0;i<e;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    int maxnode = -1;
    for(int node=0;node<n;node++) {
        queue<pair<int,int> > q;
        vector<bool> visited(n);
        for(int i=0;i<n;i++) visited[i] = false;
        q.push({node, 0});
        int cou = 1;
        visited[node] = true;
        while(!q.empty()) {
            int cn = q.front().first;
            int lvl = q.front().second;
            q.pop();
            for(int i=0;i<al[cn].size();i++) {
                int nn = al[cn][i];
                if(!visited[nn] && lvl+1 <= k) {
                    visited[nn] = true;
                    cou++;
                    q.push({nn, lvl+1});
                }
            }
        }
        // cout << "node " << node << ", cou = " << cou << "\n";
        maxnode = max(maxnode, cou);
    }
    cout << maxnode << "\n";
}