#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[10000010][3];
int r = 100000007;

int main() {
    cin >> n;
    dp[1][0] = 1; //00
    dp[1][1] = 1; //01
    dp[1][2] = 1; //10
    for(int i=2;i<=n;i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % r;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % r;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % r;
    }
    long long ans = (dp[n][0] + dp[n][1] + dp[n][2]) % r;
    // cout << dp[n][0] << ", " << dp[n][1] << ", " << dp[n][2] << ", " << "\n";
    cout << ans << "\n";
}