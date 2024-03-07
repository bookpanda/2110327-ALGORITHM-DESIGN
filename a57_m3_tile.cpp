#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> t;
int dp[15][10010]; // ith tile, total area at least cost

int main() {
    cin >> n >> m;
    t.push_back(-1);
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        t.push_back(a);
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++)
        dp[i][j] = INT_MAX;
    }
    dp[0][0] = 0;

    for(int i=1;i<=n;i++) {
        for(int k=m;k>=0;k--) {
            for(int j=1;j<=100;j++) {
                int dif = j - t[i];
                int cost = dif * dif;
                int befarea = k - j*j;
                if(befarea < 0) break;
                if(dp[i-1][befarea] == INT_MAX) continue;
                else dp[i][k] = min(dp[i][k], dp[i-1][befarea] + cost);
                // cout << "dp[" << i << "][" << k << "] = " << dp[i][k] << "\n";
            }
        }
    }
    if(dp[n][m] == INT_MAX) cout << "-1\n";
    else cout << dp[n][m] << "\n";
}