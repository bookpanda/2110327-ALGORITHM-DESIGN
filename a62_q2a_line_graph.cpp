#include<bits/stdc++.h>
using namespace std;
int n,e;
vector<int> al[200010];
vector<bool> visited;

int main() {
    cin >> n >> e;
    visited.resize(n);
    for(int i=0;i<n;i++) visited[i] = false;
    for(int i=0;i<e;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    int cou = 0;
    for(int node=0;node<n;node++) {
        if(visited[node]) continue;

        // cout << "node = " << node << "\n";
        bool isLine = true;
        queue<pair<int, int> > q;
        q.push({node, -1});
        visited[node] = true;
        while(!q.empty()) {
            int cn = q.front().first;
            int parent = q.front().second;
            q.pop();
            if(al[cn].size() > 2) {
                isLine = false;
            }
            for(int i=0;i<al[cn].size();i++) {
                int nn = al[cn][i];
                if(!visited[nn]) {
                    visited[nn] = true;
                    q.push({nn, cn});
                } else if(parent != nn) {
                    isLine = false;
                }
            }
        }
        // if(deg2 > 2) isLine = false;
        if(isLine) cou++;
    }
    cout << cou << "\n";
}