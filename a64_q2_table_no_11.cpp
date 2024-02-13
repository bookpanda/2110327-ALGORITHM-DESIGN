#include<bits/stdc++.h>
using namespace std;
int n;
int dp[10000010][4];
int r = 100000007;

//0 = 00, 1=10, 2=01

int main() {
    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i=2;i<=n;i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        dp[i][0] %= r;
        dp[i][1] = dp[i-1][0] + dp[i-1][2];
        dp[i][1] %= r;
        dp[i][2] = dp[i-1][0] + dp[i-1][1];
        dp[i][2] %= r;
    }

    int ans = dp[n][0] + dp[n][1] + dp[n][2];
    ans %= r;
    cout << ans << "\n";
}