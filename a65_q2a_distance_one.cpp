#include<bits/stdc++.h>
using namespace std;
int r = 100000007;
int k;
int dp[5010][2];

int cook(int n, int last) {
    if(n <= 0) return 0;
    if(dp[n][last] != 0) return dp[n][last];

    int ans;
    if(last == 0) {
        ans = cook(n-1, 0) + cook(n-1, 1);
    } else {
        ans = cook(n-k, 0) + cook(n-k, 1);
    }
    ans %= r;
    dp[n][last] = ans;
    // cout << "dp[" << n << "][" << last << "] = " << ans << "\n";
    return ans;
}

int main() {
    int n;
    cin >> n >> k;
    dp[1][0] = 1;
    for(int i=1;i<=k;i++) dp[i][1] = 1;
    int ans = cook(n, 0) + cook(n, 1);
    ans %= r;
    cout << ans << "\n";
}