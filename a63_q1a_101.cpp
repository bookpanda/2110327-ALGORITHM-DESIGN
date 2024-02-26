#include<bits/stdc++.h>
using namespace std;
int n, r=100000007;
int dp[10010][2][2];

int main() {
    cin >> n;
    dp[2][0][0] = 1;
    dp[2][0][1] = 1;
    dp[2][1][0] = 1;
    dp[2][1][1] = 1;
    for(int i=3;i<=n;i++) {
        dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][1][0]) % r;
        dp[i][0][1] = (dp[i-1][0][0]) % r;
        dp[i][1][0] = (dp[i-1][0][1] + dp[i-1][1][1]) % r;
        dp[i][1][1] = (dp[i-1][0][1] + dp[i-1][1][1]) % r;
    }
    int ans = dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1];
    ans %= r;
    cout << ans << "\n";

}