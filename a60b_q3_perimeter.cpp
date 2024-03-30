#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> al[1010], visited;

int main() {
    cin >> n >> m >> k;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    visited.resize(n);
    queue<pair<int, int> > q;
    q.push({0, 0});
    visited[0] = 1;
    int cou = 0;
    while(!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(dist == k) cou++;
        for(int i=0;i<al[node].size();i++) {
            int nn = al[node][i];
            if(!visited[nn]) {
                visited[nn] = 1;
                q.push({nn, dist+1});
            }
        }
    }
    cout << cou << "\n";
}