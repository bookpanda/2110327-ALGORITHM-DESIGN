#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> al[1010];

int main() {
    cin >> n >> m >> k;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    int maxk=0;
    for(int i=0;i<n;i++) {
        vector<int> visited(n);
        for(int i=0;i<n;i++) visited[i] = 0;
        queue<pair<int,int> > q;
        q.push({i, 0});
        visited[i] = 1;
        int cou=0;
        while(!q.empty()) {
            int node = q.front().first;
            int deg = q.front().second;
            q.pop();
            // cout << "node " << node << ", deg " << deg << "\n";
            if(deg <= k) {
                cou++;
            }
            for(int i=0;i<al[node].size();i++) {
                int nn = al[node][i];
                if(!visited[nn]) {
                    visited[nn] = 1;
                    q.push({nn, deg+1});
                }
            }
        }
        // cout << "freind " << i << " has " << cou << "\n";
        maxk = max(maxk, cou);
    }
    cout << maxk << "\n";
}