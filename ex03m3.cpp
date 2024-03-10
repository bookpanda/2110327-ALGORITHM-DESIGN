#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v, dp; //min cost with last station is i

int main() {
    cin >> n >> k;
    v.resize(n);
    dp.resize(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        dp[i] = INT_MAX;
    }
    dp[0] = v[0];

    for(int i=1;i<n;i++) {
        for(int j=1;j<=2*k+1;j++) {
            int idx = i-j;
            if(idx < 0) {
                if(i-k<=0)
                    dp[i] = min(dp[i], v[i]);
                break;
            }
            dp[i] = min(dp[i], dp[idx] + v[i]);
        }
    }

    int ans = INT_MAX;
    for(int i=max(0,n-1-k);i<n;i++) ans = min(ans, dp[i]);

    cout << ans << "\n";
}