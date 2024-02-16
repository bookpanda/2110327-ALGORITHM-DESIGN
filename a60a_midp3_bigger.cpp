#include<bits/stdc++.h>
using namespace std;
int dp[10010][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    dp[0][0] = 0;
    dp[0][1] = v[0];
    for(int i=1;i<n;i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if(i-2 >= 0) dp[i][1] = dp[i-2][0] + v[i];
        else dp[i][1] = dp[i-1][0] + v[i];

        // cout << "dp[" << i << "][0] = " << dp[i][0] << ", dp[" << i << "][1] = " << dp[i][1] << "\n";
    } 

    
    cout << max(dp[n-1][0], dp[n-1][1]) << "\n";
}