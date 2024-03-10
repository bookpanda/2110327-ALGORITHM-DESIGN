#include<bits/stdc++.h>
using namespace std;
int n, r=100000007;
int dp[10010][5];

int main() {
    cin >> n;
    dp[2][0] = 1; //00
    dp[2][1] = 1; //01
    dp[2][2] = 1; //10
    dp[2][3] = 1; //11

    for(int i=3;i<=n;i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][2]) % r;
        dp[i][1] = (dp[i-1][0]) % r;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % r;
        dp[i][3] = (dp[i-1][1] + dp[i-1][3]) % r;
    }

    int ans = dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3];
    ans %= r;
    cout << ans << "\n";
}