#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int dp[31][31][31][2];//len, color changing, streak, last

int main() {
    cin >> n >> m >> k;
    dp[1][0][1][0] = 0;
    dp[1][0][1][1] = 1;
    for(int i=2;i<=n;i++) {
        for(int x=0;x<=k;x++) {
            for(int j=1;j<=m;j++) {
                if(x-1 >= 0) dp[i][x][1][0] += dp[i-1][x-1][j][1];
                dp[i][x][j][0] += dp[i-1][x][j-1][0];

                if(x-1 >= 0) dp[i][x][1][1] += dp[i-1][x-1][j][0];
                dp[i][x][j][1] += dp[i-1][x][j-1][1];
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++) {
        ans += dp[n][k][i][0] + dp[n][k][i][1];
    }
    cout << ans << "\n";
}