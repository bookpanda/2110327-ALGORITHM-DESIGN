#include<bits/stdc++.h>
using namespace std;
int n, m;
long long dp[13][10010];

int main() {
    //tile swapping => greedy
    //finding right sizes that add up to M => [10010][11] total area, how many tiles used
    //believe that there is only one combinations of N tiles that add up to M
    cin >> n >> m;
    for(int i=0;i<=n;i++) 
    for(int j=0;j<=m;j++)
        dp[i][j] = INT_MAX;

    dp[0][0] = 0;
    for(int i=1;i<=n;i++) {
        int tile;
        cin >> tile;
        for(int j=m;j>=0;j--) {
            for(int k=1;k<=100;k++) {
                int area = j-k*k;
                int dif = tile - k;
                if(area < 0) break;
                dp[i][j] = min(dp[i][j], dp[i-1][area] + dif*dif);
            }
        }
    }

    if(dp[n][m] == INT_MAX) cout << -1 << "\n";
    else cout << dp[n][m] << "\n";
}