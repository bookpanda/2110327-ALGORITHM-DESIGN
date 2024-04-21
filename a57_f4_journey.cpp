#include<bits/stdc++.h>
using namespace std;
int n, ans=-INT_MAX;
vector<vector<int> > v;
int dp[(1<<20)][25];
bool visited[(1<<20)][25];

int cook(int node, int mask) {
    // cout << "node " << node << ", mask " << mask << ", sum " << sum << "\n";
    if(mask == (1<<n)-1) { //visited every node
        if(node == n-1) return 0;
        return -999999;
    }
    if(visited[mask][node]) return dp[mask][node];

    int ans = -INT_MAX;
    for(int i=1;i<n;i++) {
        if(mask & (1<<i)) continue;
        int newmask = mask | (1<<i);
        ans = max(ans, cook(i, newmask) + v[node][i]);
    }
    dp[mask][node] = ans;
    visited[mask][node] = true;

    return ans;
}

int main() {
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) {
        v[i].resize(n);
        for(int j=0;j<n;j++) {
            cin >> v[i][j];
        }
    }
    
    cout << cook(0, 1) << "\n";
}