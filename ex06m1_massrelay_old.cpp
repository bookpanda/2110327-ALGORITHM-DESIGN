#include<bits/stdc++.h>
using namespace std;
int n, m, q;
vector<pair<int, int> > edges[5010];

void dfs(int node, vector<int> &visited, int &range) {
    visited[node] = 1;
    for(int i=0;i<edges[node].size();i++) {
        int nn = edges[node][i].first;
        int cost = edges[node][i].second;
        if(!visited[nn] && range >= cost) {
            dfs(nn, visited, range);
        }
    }
}

int main() {
    cin >> n >> m >> q;
    for(int i=0;i<m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    for(int query=0;query<q;query++) {
        int d;
        cin >> d;

        int high = 1000000;
        int low = 1;
        int mid = (high+low)/2;
        int ans = INT_MAX;
        
        while(low <= high) {
            vector<int> visited(n);
            int ccou = 0;
            for(int i=0;i<n;i++) {
                if(!visited[i]) {
                    dfs(i, visited, mid);
                    ccou++;
                }
            }
            if(ccou > d) { //too many clusters, need to increase range
                low = mid+1;
                mid = (high + low)/2;
            } else if(ccou <= d) { //doable
                ans = min(ans, mid);
                high = mid-1;
                mid = (high + low)/2;
            }
        }
        cout << ans << "\n";
    }
}