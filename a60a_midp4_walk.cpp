#include<bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    vector<vector<int> > dp(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            cin >> v[i][j];
    }
    dp[0][0] = v[0][0];
    for(int i=1;i<n;i++) dp[i][0] = dp[i-1][0] + v[i][0];
    for(int i=1;i<m;i++) dp[0][i] = dp[0][i-1] + v[0][i];

    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            dp[i][j] = max(dp[i-1][j] + v[i][j], max(dp[i][j-1] + v[i][j], dp[i-1][j-1] + 2*v[i][j]));
        }
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << dp[i][j] << "\t";
    //     } cout << "\n";
    // }
    
    cout << dp[n-1][m-1] << "\n";
}