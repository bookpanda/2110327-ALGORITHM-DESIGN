#include<bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    vector<int> v(n);
    vector<int> dp(m+1);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    dp[0] = 0;
    for(int i=1;i<=m;i++) dp[i] = INT_MAX;

    for(int i=1;i<=m;i++) {
        for(int j=0;j<n;j++) {
            int bef = i-v[j];
            if(bef < 0 || dp[bef] == INT_MAX) continue;
            dp[i] = min(dp[i], dp[bef]+1);
        }
    }
    cout << dp[m] << "\n";
}