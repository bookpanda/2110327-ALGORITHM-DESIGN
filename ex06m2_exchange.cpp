#include<bits/stdc++.h>
using namespace std;
int t;

int main() {
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<double> > am(n, vector<double>(n)), dp(n, vector<double>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> am[i][j];
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j] = am[i][j];
            }
        }

        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);
                }
            }

            // cout << "\nround " << k << "\n";
            // for(int i=0;i<n;i++) {
            //     for(int j=0;j<n;j++) {
            //         cout << dp[i][j] << " ";
            //     } cout << "\n";
            // }
        }

        bool isProfit = false;
        for(int i=0;i<n;i++) {
            if(dp[i][i] > 1) {
                isProfit = true;
                break;
            }
            // for(int j=0;j<n;j++) {
            //     if(dp[i][j] * am[j][i] > 1) isProfit = true;
            // }
        }

        if(isProfit) cout << "YES\n";
        else cout << "NO\n";
    }
}