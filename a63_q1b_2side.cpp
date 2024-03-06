#include<bits/stdc++.h>
using namespace std;
int n, w, k;
int dp[200010][2]; //max val at pos i, last one is left/right 
int dp2[200010][55][2];
vector<int> l, r;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w >> k;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        l.push_back(a);
    }
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        r.push_back(a);
    }

    if(k >= n) {
        dp[0][0] = l[0];
        dp[0][1] = r[0];
        for(int i=1;i<n;i++) {
            if(i-w-1 >= 0) {
                dp[i][0] = max(dp[i-1][0], dp[i-w-1][1] + l[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-w-1][0] + r[i]);
            } else {
                dp[i][0] = max(dp[i-1][0], l[i]);
                dp[i][1] = max(dp[i-1][1], r[i]);
            }
            // cout << "dp " << i << ", " << 0 << " = " << dp[i][0] << "\n";
            // cout << "dp " << i << ", " << 1 << " = " << dp[i][1] << "\n";
        }

        cout << max(dp[n-1][0], dp[n-1][1]) << "\n";
    } else {
        dp2[0][1][0] = l[0];
        dp2[0][1][1] = r[0];
        for(int i=1;i<n;i++) {
            for(int j=1;j<=k;j++) {
                if(i-w-1 >= 0) {
                    dp2[i][j][0] = max(dp2[i-1][j][0], dp2[i-w-1][j-1][1] + l[i]);
                    dp2[i][j][1] = max(dp2[i-1][j][1], dp2[i-w-1][j-1][0] + r[i]);
                } else {
                    dp2[i][j][0] = max(dp2[i-1][j][0], l[i]);
                    dp2[i][j][1] = max(dp2[i-1][j][1], r[i]);
                }
            }
            // cout << "dp " << i << ", " << 0 << " = " << dp[i][0] << "\n";
            // cout << "dp " << i << ", " << 1 << " = " << dp[i][1] << "\n";
        }
        int ans = -INT_MAX;
        for(int i=0;i<=k;i++) {
            ans = max(ans, dp2[n-1][i][0]);
            ans = max(ans, dp2[n-1][i][1]);
        }
        cout << ans << "\n";
    }
}