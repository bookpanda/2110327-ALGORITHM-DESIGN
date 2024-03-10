#include<bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    vector<vector<int> > dp(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) v[i][j] = s[j] - '0';
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        dp[i][0] = v[i][0];
        ans = max(ans, dp[i][0]);
    }
    for(int i=0;i<m;i++) {
        dp[0][i] = v[0][i];
        ans = max(ans, dp[0][i]);
    }

    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(v[i][j] == 1) 
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            else dp[i][j] = 0;

            ans = max(ans, dp[i][j]);
        }
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << dp[i][j] << "\t";
    //     } cout << "\n";
    // }
    cout << ans << "\n";
}