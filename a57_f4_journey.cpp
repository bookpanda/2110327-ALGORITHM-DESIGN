#include<bits/stdc++.h>
using namespace std;
int n, am[25][25];
int visited[1 << 20][21], dp[1 << 20][21];

int cook(int node, int mask) {
    if(mask == (1 << n) - 1) {
        if(node == n-1) return 0;
        return -9999999;
    }
    if(visited[mask][node]) return dp[mask][node];

    int res = -INT_MAX;
    for(int i=1;i<n;i++) {
        if((mask & (1<<i)) != 0 || node == i) continue;
        int newmask = mask | (1 << i);
        res = max(res, cook(i, newmask) + am[node][i]);
    }
    dp[mask][node] = res;
    visited[mask][node] = 1;

    return res;
}


int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> am[i][j];
        }
    }

    cout << cook(0, 1) << "\n";
}