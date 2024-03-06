#include<bits/stdc++.h>
using namespace std;
int dp[505][505];

int main() {
    int n, k;

    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            if(j > i) break;
            if(i == j) dp[i][j] = 1;
            else {
                dp[i][j] = dp[i-1][j-1] + j * dp[i-1][j];
                dp[i][j] %= 1997;
            }
        }
    }
    cout << dp[n][k] << "\n";
}