#include<bits/stdc++.h>
using namespace std;
int dp[10010]; //pos i has station

int main() {
    int n, k;
    vector<int> v;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    dp[0] = v[0];
    for(int i=1;i<n;i++) dp[i] = INT_MAX;

    for(int i=1;i<n;i++) {
        for(int j=1;j<=2*k+1;j++) {
            int idx = i-j;
            if(idx < 0) {
                if(i-k <= 0) //if plant at i can still reach 0 (there are no other previous stations)
                    dp[i] = min(dp[i], v[i]);
                break;
            }
            dp[i] = min(dp[i], dp[idx] + v[i]);
        }
    }

    int ans = INT_MAX;
    for(int i=0;i<=k;i++) {
        int idx = n-1-i;
        if(idx < 0) break;
        ans = min(ans, dp[idx]);
    }

    // for(int i=0;i<n;i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";

    cout << ans << "\n";
}