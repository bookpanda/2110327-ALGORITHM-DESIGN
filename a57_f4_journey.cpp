#include<bits/stdc++.h>
using namespace std;
int n, am[25][25], dp[(1<<21)+5][25]; //21 because 1-based, shoudl use 0-based (2^0 = 1)
bool visited[(1<<21)+5][25];

int cook(int node, int mask) {
    // cout << "node " << node << ", mask " << mask << "\n";
    if(mask == (1<<n+1)-1-1) {
        if(node == n) return 0;
        return -9999999;
    }
    if(visited[mask][node]) return dp[mask][node];

    int ans = -9999999;
    for(int i=2;i<=n;i++) {
        if(mask & (1<<i)) continue;

        int nm = mask | (1<<i);
        ans = max(ans, cook(i, nm) + am[node][i]);
    }
    dp[mask][node] = ans;
    visited[mask][node] = true;

    return ans;
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> am[i][j];
        }
    }
    cout << cook(1, 2) << "\n";
}