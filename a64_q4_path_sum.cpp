#include<bits/stdc++.h>
using namespace std;
int n, m, k[10], visited[20005][25];
vector<pair<int, int> > al[25];
int canCost[20010];

int main() {
    cin >> n >> m;
    for(int i=0;i<8;i++) cin >> k[i];
    for(int i=0;i<m;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        al[a].push_back({b, w});
        al[b].push_back({a, w});
    }
    queue<pair<int, pair<int, int> > > q;
    for(int i=0;i<n;i++) {
        q.push({i, {1<<i, 0}});
        visited[0][i] = 1;
    }
    while(!q.empty()) {
        int node = q.front().first;
        int mask = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        canCost[cost] = 1;

        for(auto [nn, nw]: al[node]) {
            int newcost = cost + nw;
            if((mask & (1<<nn)) == 0 && !visited[newcost][nn]) {
                q.push({nn, {mask | (1<<nn), newcost}});
                visited[newcost][nn] = 1;
            }
        }
    }

    for(int i=0;i<8;i++) {
        if(canCost[k[i]]) cout << "YES\n";
        else cout << "NO\n";
    }
}